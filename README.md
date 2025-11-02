# clapx
A command-line argument parser single-header library written in C using [X macros](https://en.wikipedia.org/wiki/X_macro).

***

## Installation
1. Start by cloning the repository with `git clone https://github.com/Noxmor/clapx`.
2. Run `make install`.
3. Done! You can now include the library by typing `#include <clapx/clapx.h>`.
> [!NOTE]
> Alternatively, you can also just copy/clone the library locally and include it directly.

***

## How to use
In order to use `clapx`, you will want to first define the `CLAPX_FLAGS` and `CLAPX_SUBCOMMANDS` macros to fit the specification of your application.

> [!IMPORTANT]
> The macros `CLAPX_FLAGS` and `CLAPX_SUBCOMMANDS` must be defined **before** including `clapx` with implementation details.
> 
> Define `CLAPX_IMPLEMENTATION` before including `clapx` to include the implementation details.

### Global flags
In order to define global flags, you will need to define the `CLAPX_FLAGS` macro. Each flag will then be defined via one of the `CLAPX_<type>_FLAG` macros, like this:
```c
void help_callback(void);

#define CLAPX_FLAGS \
    CLAPX_BOOL_FLAG(help, "help", 'h', help_callback) \
    CLAPX_STRING_FLAG(foo, "foo", CLAPX_NO_SHORT, CLAPX_NO_CALLBACK, "my-custom-default-string") \
    CLAPX_CHAR_FLAG(bar, CLAPX_ONLY_SHORT('b'), CLAPX_NO_CALLBACK, 'b')
```

#### List of macros for defining global flags
- `CLAPX_BOOL_FLAG(label, long_name, short_name, callback)`
- `CLAPX_U8_FLAG(label, type, long_name, short_name, callback, default_value)`
- `CLAPX_U16_FLAG(label, type, long_name, short_name, callback, default_value)`
- `CLAPX_U32_FLAG(label, type, long_name, short_name, callback, default_value)`
- `CLAPX_U64_FLAG(label, type, long_name, short_name, callback, default_value)`
- `CLAPX_I8_FLAG(label, type, long_name, short_name, callback, default_value)`
- `CLAPX_I16_FLAG(label, type, long_name, short_name, callback, default_value)`
- `CLAPX_I32_FLAG(label, type, long_name, short_name, callback, default_value)`
- `CLAPX_I64_FLAG(label, type, long_name, short_name, callback, default_value)`
- `CLAPX_CHAR_FLAG(label, type, long_name, short_name, callback, default_value)`
- `CLAPX_STRING_FLAG(label, type, long_name, short_name, callback, default_value)`
- `CLAPX_CUSTOM_FLAG(label, type, long_name, short_name, callback, parser)`

where...
- `label` is a unique and valid C identifier.
- `type` is either `CLAPX_FLAG_TYPE_OPT_ARG` or `CLAPX_FLAG_TYPE_REQ_ARG`.
- `long_name` is a string literal or `CLAPX_NO_LONG`.
- `short_name` is an alphanumeric character or `CLAPX_NO_SHORT`.
- `callback` is a function pointer of type `clapx_flag_callback_t` or `CLAPX_NO_CALLBACK`. If set, this callback is triggered immediately after the flag is parsed.
- `parser` is a function pointer of type `clapx_custom_parser_callback_t`.

> [!NOTE]
> Any pair of arguments `(long_name, short_name)` may be replaced with one of the following macros:
> - `CLAPX_ONLY_LONG(long_name)`
> - `CLAPX_ONLY_SHORT(short_name)`

### Subcommands
In order to define subcommands, you will need to define the `CLAPX_SUBCOMMANDS` macro. Each subcommand will then be defined via the `CLAPX_SUBCOMMAND` macro, like this:
```c
void foo_callback(int argc, char** argv);

#define CLAPX_SUBCOMMANDS \
    CLAPX_SUBCOMMAND(foo, "foo", foo_callback) \
    CLAPX_SUBCOMMAND(bar, "bar", CLAPX_NO_CALLBACK, CLAPX_BOOL_FLAG(help, "help", 'h', CLAPX_NO_CALLBACK))
```

#### List of macros for defining subcommands
- `CLAPX_SUBCOMMAND(label, name, callback, ...)`

where...
- `label` is a unique and valid C identifier.
- `name` is a string literal.
- `callback` is a function pointer of type `clapx_subcommand_callback_t` or `CLAPX_NO_CALLBACK`. If set, this callback is triggered immediately after the command-line is completely parsed.
- `...` are zero or more `CLAPX_FLAG` macros.

### Parsing the command-line
You can parse the command-line, typically inside your main function, as follows:
```c
int main(int argc, char** argv)
{
    if (clapx_parse_args(argc, argv) != CLAPX_SUCCESS)
    {
        // Some internal parser error occured.
        return EXIT_FAILURE;
    }
}
```

### Retrieving flag values
Most likely, after parsing the command-line, you will want to inspect the value of a certain flag, since it may differ from the default value  if the user specified it.
The way this is done depends on whether the flag is global or subcommand-specific.

**For global flags**: Use one of the `CLAPX_<type>_FLAG_VALUE(flag)` macros, like this:
```c
int main(int argc, char** argv)
{
    // Retrieves the value of the global flag 'foo'.
    const char* string_flag_value = CLAPX_STRING_FLAG_VALUE(foo);
}
```

#### List of macros for retrieving global flag's values
- `CLAPX_BOOL_FLAG_VALUE(flag)`
- `CLAPX_U8_FLAG_VALUE(flag)`
- `CLAPX_U16_FLAG_VALUE(flag)`
- `CLAPX_U32_FLAG_VALUE(flag)`
- `CLAPX_U64_FLAG_VALUE(flag)`
- `CLAPX_I8_FLAG_VALUE(flag)`
- `CLAPX_I16_FLAG_VALUE(flag)`
- `CLAPX_I32_FLAG_VALUE(flag)`
- `CLAPX_I64_FLAG_VALUE(flag)`
- `CLAPX_CHAR_FLAG_VALUE(flag)`
- `CLAPX_STRING_FLAG_VALUE(flag)`

where...
- `flag` is the label of the flag.

**For subcommand-specific flags**: Use one of the `CLAPX_SUBCOMMAND_<t<pe>_FLAG_VALUE(subcommand, flag)` macros, like this:
```c
void foo_callback(int argc, char** argv)
{
    // Retrieves the value of the 'bar' flag, which is bound to the 'foo' subcommand.
    if (CLAPX_SUBCOMMAND_BOOL_FLAG_VALUE(foo, bar))
    {
        // ...
    }
    else
    {
        // ...
    }
}
```

#### List of macros for retrieving subcommand-specific flag's values
- `CLAPX_SUBCOMMAND_BOOL_FLAG_VALUE(subcommand, flag)`
- `CLAPX_SUBCOMMAND_U8_FLAG_VALUE(subcommand, flag)`
- `CLAPX_SUBCOMMAND_U16_FLAG_VALUE(subcommand, flag)`
- `CLAPX_SUBCOMMAND_U32_FLAG_VALUE(subcommand, flag)`
- `CLAPX_SUBCOMMAND_U64_FLAG_VALUE(subcommand, flag)`
- `CLAPX_SUBCOMMAND_I8_FLAG_VALUE(subcommand, flag)`
- `CLAPX_SUBCOMMAND_I16_FLAG_VALUE(subcommand, flag)`
- `CLAPX_SUBCOMMAND_I32_FLAG_VALUE(subcommand, flag)`
- `CLAPX_SUBCOMMAND_I64_FLAG_VALUE(subcommand, flag)`
- `CLAPX_SUBCOMMAND_CHAR_FLAG_VALUE(subcommand, flag)`
- `CLAPX_SUBCOMMAND_STRING_FLAG_VALUE(subcommand, flag)`

where...
- `subcommand` is the label of the subcommand.
- `flag` is the label of the subcommand-specific flag.
