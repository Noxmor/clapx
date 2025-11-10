// Copyright (c) 2025 Noxmor

#ifndef CLAPX_H
#define CLAPX_H

#include <stddef.h>
#include <stdint.h>

/**
 * Value indicating a flag with no long name.
 */
#define CLAPX_NO_LONG NULL

/**
 * Value indicating a flag with no long name.
 */
#define CLAPX_NO_SHORT '\0'

/**
 * Value indicating a flag with no callback.
 */
#define CLAPX_NO_CALLBACK NULL

/**
 * Helper macro for defining a flag with only a long name.
 * @param name The name of the flag.
 */
#define CLAPX_ONLY_LONG(name) name, CLAPX_NO_SHORT

/**
 * Helper macro for defining a flag with only a short name.
 * @param name The name of the flag.
 */
#define CLAPX_ONLY_SHORT(name) CLAPX_NO_LONG, name

/**
 * Retrieves the value of a bool flag.
 * @param flag The label of the flag.
 */
#define CLAPX_BOOL_FLAG_VALUE(flag) (clapx_flags[CLAPX_FLAG_INDEX_##flag].bool_value)

/**
 * Retrieves the value of a uint8_t flag.
 * @param flag The label of the flag.
 */
#define CLAPX_U8_FLAG_VALUE(flag) (clapx_flags[CLAPX_FLAG_INDEX_##flag].u8_value)

/**
 * Retrieves the value of a uint16_t flag.
 * @param flag The label of the flag.
 */
#define CLAPX_U16_FLAG_VALUE(flag) (clapx_flags[CLAPX_FLAG_INDEX_##flag].u16_value)

/**
 * Retrieves the value of a uint32_t flag.
 * @param flag The label of the flag.
 */
#define CLAPX_U32_FLAG_VALUE(flag) (clapx_flags[CLAPX_FLAG_INDEX_##flag].u32_value)

/**
 * Retrieves the value of a uint64_t flag.
 * @param flag The label of the flag.
 */
#define CLAPX_U64_FLAG_VALUE(flag) (clapx_flags[CLAPX_FLAG_INDEX_##flag].u64_value)

/**
 * Retrieves the value of a int8_t flag.
 * @param flag The label of the flag.
 */
#define CLAPX_I8_FLAG_VALUE(flag) (clapx_flags[CLAPX_FLAG_INDEX_##flag].i8_value)

/**
 * Retrieves the value of a int16_t flag.
 * @param flag The label of the flag.
 */
#define CLAPX_I16_FLAG_VALUE(flag) (clapx_flags[CLAPX_FLAG_INDEX_##flag].i16_value)

/**
 * Retrieves the value of a int32_t flag.
 * @param flag The label of the flag.
 */
#define CLAPX_I32_FLAG_VALUE(flag) (clapx_flags[CLAPX_FLAG_INDEX_##flag].i32_value)

/**
 * Retrieves the value of a int64_t flag.
 * @param flag The label of the flag.
 */
#define CLAPX_I64_FLAG_VALUE(flag) (clapx_flags[CLAPX_FLAG_INDEX_##flag].i64_value)

/**
 * Retrieves the value of a char flag.
 * @param flag The label of the flag.
 */
#define CLAPX_CHAR_FLAG_VALUE(flag) (clapx_flags[CLAPX_FLAG_INDEX_##flag].char_value)

/**
 * Retrieves the value of a string flag.
 * @param flag The label of the flag.
 */
#define CLAPX_STRING_FLAG_VALUE(flag) (clapx_flags[CLAPX_FLAG_INDEX_##flag].string_value)

/**
 * Retrieves the value of a subcommand specific bool flag.
 * @param subcommand The label of the subcommand.
 * @param flag The label of the flag.
 */
#define CLAPX_SUBCOMMAND_BOOL_FLAG_VALUE(subcommand, flag) \
    (clapx_subcommands[CLAPX_SUBCOMMAND_INDEX_##subcommand].flags[CLAPX_FLAG_INDEX_##flag].bool_value)

/**
 * Retrieves the value of a subcommand specific uint8_t flag.
 * @param subcommand The label of the subcommand.
 * @param flag The label of the flag.
 */
#define CLAPX_SUBCOMMAND_U8_FLAG_VALUE(subcommand, flag) \
    (clapx_subcommands[CLAPX_SUBCOMMAND_INDEX_##subcommand].flags[CLAPX_FLAG_INDEX_##flag].u8_value)

/**
 * Retrieves the value of a subcommand specific uint16_t flag.
 * @param subcommand The label of the subcommand.
 * @param flag The label of the flag.
 */
#define CLAPX_SUBCOMMAND_U16_FLAG_VALUE(subcommand, flag) \
    (clapx_subcommands[CLAPX_SUBCOMMAND_INDEX_##subcommand].flags[CLAPX_FLAG_INDEX_##flag].u16_value)

/**
 * Retrieves the value of a subcommand specific uint32_t flag.
 * @param subcommand The label of the subcommand.
 * @param flag The label of the flag.
 */
#define CLAPX_SUBCOMMAND_U32_FLAG_VALUE(subcommand, flag) \
    (clapx_subcommands[CLAPX_SUBCOMMAND_INDEX_##subcommand].flags[CLAPX_FLAG_INDEX_##flag].u32_value)

/**
 * Retrieves the value of a subcommand specific uint64_t flag.
 * @param subcommand The label of the subcommand.
 * @param flag The label of the flag.
 */
#define CLAPX_SUBCOMMAND_U64_FLAG_VALUE(subcommand, flag) \
    (clapx_subcommands[CLAPX_SUBCOMMAND_INDEX_##subcommand].flags[CLAPX_FLAG_INDEX_##flag].u64_value)

/**
 * Retrieves the value of a subcommand specific int8_t flag.
 * @param subcommand The label of the subcommand.
 * @param flag The label of the flag.
 */
#define CLAPX_SUBCOMMAND_I8_FLAG_VALUE(subcommand, flag) \
    (clapx_subcommands[CLAPX_SUBCOMMAND_INDEX_##subcommand].flags[CLAPX_FLAG_INDEX_##flag].i8_value)

/**
 * Retrieves the value of a subcommand specific int16_t flag.
 * @param subcommand The label of the subcommand.
 * @param flag The label of the flag.
 */
#define CLAPX_SUBCOMMAND_I16_FLAG_VALUE(subcommand, flag) \
    (clapx_subcommands[CLAPX_SUBCOMMAND_INDEX_##subcommand].flags[CLAPX_FLAG_INDEX_##flag].i16_value)
/**
 * Retrieves the value of a subcommand specific int32_t flag.
 * @param subcommand The label of the subcommand.
 * @param flag The label of the flag.
 */
#define CLAPX_SUBCOMMAND_I32_FLAG_VALUE(subcommand, flag) \
    (clapx_subcommands[CLAPX_SUBCOMMAND_INDEX_##subcommand].flags[CLAPX_FLAG_INDEX_##flag].i32_value)
/**
 * Retrieves the value of a subcommand specific int64_t flag.
 * @param subcommand The label of the subcommand.
 * @param flag The label of the flag.
 */
#define CLAPX_SUBCOMMAND_I64_FLAG_VALUE(subcommand, flag) \
    (clapx_subcommands[CLAPX_SUBCOMMAND_INDEX_##subcommand].flags[CLAPX_FLAG_INDEX_##flag].i64_value)

/**
 * Retrieves the value of a subcommand specific char flag.
 * @param subcommand The label of the subcommand.
 * @param flag The label of the flag.
 */
#define CLAPX_SUBCOMMAND_CHAR_FLAG_VALUE(subcommand, flag) \
    (clapx_subcommands[CLAPX_SUBCOMMAND_INDEX_##subcommand].flags[CLAPX_FLAG_INDEX_##flag].char_value)

/**
 * Retrieves the value of a subcommand specific string flag.
 * @param subcommand The label of the subcommand.
 * @param flag The label of the flag.
 */
#define CLAPX_SUBCOMMAND_STRING_FLAG_VALUE(subcommand, flag) \
    (clapx_subcommands[CLAPX_SUBCOMMAND_INDEX_##subcommand].flags[CLAPX_FLAG_INDEX_##flag].string_value)

/**
 * Defines a new bool flag.
 * @param label The unique label of the flag.
 * @param long_name The long name of the flag, either a string or CLAPX_NO_LONG.
 * @param short_name The short name of the flag, either an alphanumeric character or CLAPX_NO_SHORT.
 * @param callback The callback of the flag, either a function of type clapx_flag_callback_t or CLAPX_NO_CALLBACK.
 */
#define CLAPX_BOOL_FLAG_IMPL(label, long_name, short_name, callback) \
    CLAPX_FLAG(label, CLAPX_FLAG_TYPE_NO_VALUE, CLAPX_FLAG_VALUE_TYPE_BOOL, long_name, short_name, callback, .bool_value = 0)

/**
 * Defines a new uint8_t flag.
 * @param label The unique label of the flag.
 * @param type The type of the flag, must be either CLAPX_FLAG_TYPE_OPT_VALUE or CLAPX_FLAG_TYPE_REQ_VALUE.
 * @param long_name The long name of the flag, either a string or CLAPX_NO_LONG.
 * @param short_name The short name of the flag, either an alphanumeric character or CLAPX_NO_SHORT.
 * @param callback The callback of the flag, either a function of type clapx_flag_callback_t or CLAPX_NO_CALLBACK.
 * @param default_value The default value for the flag.
 */
#define CLAPX_U8_FLAG_IMPL(label, type, long_name, short_name, callback, default_value) \
    CLAPX_FLAG(label, type, CLAPX_FLAG_VALUE_TYPE_U8, long_name, short_name, callback, .u8_value = default_value)

/**
 * Defines a new uint16_t flag.
 * @param label The unique label of the flag.
 * @param type The type of the flag, must be either CLAPX_FLAG_TYPE_OPT_VALUE or CLAPX_FLAG_TYPE_REQ_VALUE.
 * @param long_name The long name of the flag, either a string or CLAPX_NO_LONG.
 * @param short_name The short name of the flag, either an alphanumeric character or CLAPX_NO_SHORT.
 * @param callback The callback of the flag, either a function of type clapx_flag_callback_t or CLAPX_NO_CALLBACK.
 * @param default_value The default value for the flag.
 */
#define CLAPX_U16_FLAG_IMPL(label, type, long_name, short_name, callback, default_value) \
    CLAPX_FLAG(label, type, CLAPX_FLAG_VALUE_TYPE_U16, long_name, short_name, callback, .u16_value = default_value)
/**
 * Defines a new uint32_t flag.
 * @param label The unique label of the flag.
 * @param type The type of the flag, must be either CLAPX_FLAG_TYPE_OPT_VALUE or CLAPX_FLAG_TYPE_REQ_VALUE.
 * @param long_name The long name of the flag, either a string or CLAPX_NO_LONG.
 * @param short_name The short name of the flag, either an alphanumeric character or CLAPX_NO_SHORT.
 * @param callback The callback of the flag, either a function of type clapx_flag_callback_t or CLAPX_NO_CALLBACK.
 * @param default_value The default value for the flag.
 */
#define CLAPX_U32_FLAG_IMPL(label, type, long_name, short_name, callback, default_value) \
    CLAPX_FLAG(label, type, CLAPX_FLAG_VALUE_TYPE_U32, long_name, short_name, callback, .u32_value = default_value)
/**
 * Defines a new uint64_t flag.
 * @param label The unique label of the flag.
 * @param type The type of the flag, must be either CLAPX_FLAG_TYPE_OPT_VALUE or CLAPX_FLAG_TYPE_REQ_VALUE.
 * @param long_name The long name of the flag, either a string or CLAPX_NO_LONG.
 * @param short_name The short name of the flag, either an alphanumeric character or CLAPX_NO_SHORT.
 * @param callback The callback of the flag, either a function of type clapx_flag_callback_t or CLAPX_NO_CALLBACK.
 * @param default_value The default value for the flag.
 */
#define CLAPX_U64_FLAG_IMPL(label, type, long_name, short_name, callback, default_value) \
    CLAPX_FLAG(label, type, CLAPX_FLAG_VALUE_TYPE_U64, long_name, short_name, callback, .u64_value = default_value)

/**
 * Defines a new int8_t flag.
 * @param label The unique label of the flag.
 * @param type The type of the flag, must be either CLAPX_FLAG_TYPE_OPT_VALUE or CLAPX_FLAG_TYPE_REQ_VALUE.
 * @param long_name The long name of the flag, either a string or CLAPX_NO_LONG.
 * @param short_name The short name of the flag, either an alphanumeric character or CLAPX_NO_SHORT.
 * @param callback The callback of the flag, either a function of type clapx_flag_callback_t or CLAPX_NO_CALLBACK.
 * @param default_value The default value for the flag.
 */
#define CLAPX_I8_FLAG_IMPL(label, type, long_name, short_name, callback, default_value) \
    CLAPX_FLAG(label, type, CLAPX_FLAG_VALUE_TYPE_I8, long_name, short_name, callback, .i8_value = default_value)

/**
 * Defines a new int16_t flag.
 * @param label The unique label of the flag.
 * @param type The type of the flag, must be either CLAPX_FLAG_TYPE_OPT_VALUE or CLAPX_FLAG_TYPE_REQ_VALUE.
 * @param long_name The long name of the flag, either a string or CLAPX_NO_LONG.
 * @param short_name The short name of the flag, either an alphanumeric character or CLAPX_NO_SHORT.
 * @param callback The callback of the flag, either a function of type clapx_flag_callback_t or CLAPX_NO_CALLBACK.
 * @param default_value The default value for the flag.
 */
#define CLAPX_I16_FLAG_IMPL(label, type, long_name, short_name, callback, default_value) \
    CLAPX_FLAG(label, type, CLAPX_FLAG_VALUE_TYPE_I16, long_name, short_name, callback, .i16_value = default_value)
/**
 * Defines a new int32_t flag.
 * @param label The unique label of the flag.
 * @param type The type of the flag, must be either CLAPX_FLAG_TYPE_OPT_VALUE or CLAPX_FLAG_TYPE_REQ_VALUE.
 * @param long_name The long name of the flag, either a string or CLAPX_NO_LONG.
 * @param short_name The short name of the flag, either an alphanumeric character or CLAPX_NO_SHORT.
 * @param callback The callback of the flag, either a function of type clapx_flag_callback_t or CLAPX_NO_CALLBACK.
 * @param default_value The default value for the flag.
 */
#define CLAPX_I32_FLAG_IMPL(label, type, long_name, short_name, callback, default_value) \
    CLAPX_FLAG(label, type, CLAPX_FLAG_VALUE_TYPE_I32, long_name, short_name, callback, .i32_value = default_value)
/**
 * Defines a new int64_t flag.
 * @param label The unique label of the flag.
 * @param type The type of the flag, must be either CLAPX_FLAG_TYPE_OPT_VALUE or CLAPX_FLAG_TYPE_REQ_VALUE.
 * @param long_name The long name of the flag, either a string or CLAPX_NO_LONG.
 * @param short_name The short name of the flag, either an alphanumeric character or CLAPX_NO_SHORT.
 * @param callback The callback of the flag, either a function of type clapx_flag_callback_t or CLAPX_NO_CALLBACK.
 * @param default_value The default value for the flag.
 */
#define CLAPX_I64_FLAG_IMPL(label, type, long_name, short_name, callback, default_value) \
    CLAPX_FLAG(label, type, CLAPX_FLAG_VALUE_TYPE_I64, long_name, short_name, callback, .i64_value = default_value)

/**
 * Defines a new char flag.
 * @param label The unique label of the flag.
 * @param type The type of the flag, must be either CLAPX_FLAG_TYPE_OPT_VALUE or CLAPX_FLAG_TYPE_REQ_VALUE.
 * @param long_name The long name of the flag, either a string or CLAPX_NO_LONG.
 * @param short_name The short name of the flag, either an alphanumeric character or CLAPX_NO_SHORT.
 * @param callback The callback of the flag, either a function of type clapx_flag_callback_t or CLAPX_NO_CALLBACK.
 * @param default_value The default value for the flag.
 */
#define CLAPX_CHAR_FLAG_IMPL(label, type, long_name, short_name, callback, default_value) \
    CLAPX_FLAG(label, type, CLAPX_FLAG_VALUE_TYPE_CHAR, long_name, short_name, callback, .char_value = default_value)
/**
 * Defines a new string flag.
 * @param label The unique label of the flag.
 * @param type The type of the flag, must be either CLAPX_FLAG_TYPE_OPT_VALUE or CLAPX_FLAG_TYPE_REQ_VALUE.
 * @param long_name The long name of the flag, either a string or CLAPX_NO_LONG.
 * @param short_name The short name of the flag, either an alphanumeric character or CLAPX_NO_SHORT.
 * @param callback The callback of the flag, either a function of type clapx_flag_callback_t or CLAPX_NO_CALLBACK.
 * @param default_value The default value for the flag.
 */
#define CLAPX_STRING_FLAG_IMPL(label, type, long_name, short_name, callback, default_value) \
    CLAPX_FLAG(label, type, CLAPX_FLAG_VALUE_TYPE_STRING, long_name, short_name, callback, .string_value = default_value)

/**
 * Defines a new custom flag.
 * @param label The unique label of the flag.
 * @param type The type of the flag, must be either CLAPX_FLAG_TYPE_OPT_VALUE or CLAPX_FLAG_TYPE_REQ_VALUE.
 * @param long_name The long name of the flag, either a string or CLAPX_NO_LONG.
 * @param short_name The short name of the flag, either an alphanumeric character or CLAPX_NO_SHORT.
 * @param callback The callback of the flag, either a function of type clapx_flag_callback_t or CLAPX_NO_CALLBACK.
 * @param parser The custom parser function for the flag, must be of type clapx_custom_parser_callback_t.
 */
#define CLAPX_CUSTOM_FLAG_IMPL(label, type, long_name, short_name, callback, parser) \
    CLAPX_FLAG(label, type, CLAPX_FLAG_VALUE_TYPE_CUSTOM, long_name, short_name, callback, .custom_parser_callback = parser)

/**
 * Defines a new bool flag.
 */
#define CLAPX_BOOL_FLAG(...) CLAPX_BOOL_FLAG_IMPL(__VA_ARGS__)

/**
 * Defines a new uint8_t flag.
 */
#define CLAPX_U8_FLAG(...) CLAPX_U8_FLAG_IMPL(__VA_ARGS__)

/**
 * Defines a new uint16_t flag.
 */
#define CLAPX_U16_FLAG(...) CLAPX_U16_FLAG_IMPL(__VA_ARGS__)

/**
 * Defines a new uint32_t flag.
 */
#define CLAPX_U32_FLAG(...) CLAPX_U32_FLAG_IMPL(__VA_ARGS__)

/**
 * Defines a new uint64_t flag.
 */
#define CLAPX_U64_FLAG(...) CLAPX_U64_FLAG_IMPL(__VA_ARGS__)

/**
 * Defines a new int8_t flag.
 */
#define CLAPX_I8_FLAG(...) CLAPX_I8_FLAG_IMPL(__VA_ARGS__)

/**
 * Defines a new int16_t flag.
 */
#define CLAPX_I16_FLAG(...) CLAPX_I16_FLAG_IMPL(__VA_ARGS__)

/**
 * Defines a new int32_t flag.
 */
#define CLAPX_I32_FLAG(...) CLAPX_I32_FLAG_IMPL(__VA_ARGS__)

/**
 * Defines a new int64_t flag.
 */
#define CLAPX_I64_FLAG(...) CLAPX_I64_FLAG_IMPL(__VA_ARGS__)

/**
 * Defines a new char flag.
 */
#define CLAPX_CHAR_FLAG(...) CLAPX_CHAR_FLAG_IMPL(__VA_ARGS__)

/**
 * Defines a new string flag.
 */
#define CLAPX_STRING_FLAG(...) CLAPX_STRING_FLAG_IMPL(__VA_ARGS__)

/**
 * Defines a new custom flag.
 */
#define CLAPX_CUSTOM_FLAG(...) CLAPX_CUSTOM_FLAG_IMPL(__VA_ARGS__)


enum
{
    CLAPX_SUCCESS = 0,
    CLAPX_ERROR_INVALID_SUBCOMMAND,
    CLAPX_ERROR_INVALID_LONG_FLAG,
    CLAPX_ERROR_INVALID_LONG_FLAG_VALUE,
    CLAPX_ERROR_MISSING_LONG_FLAG_REQ_VALUE,
    CLAPX_ERROR_INVALID_SHORT_FLAG,
    CLAPX_ERROR_INVALID_SHORT_FLAG_VALUE,
    CLAPX_ERROR_MISSING_SHORT_FLAG_REQ_VALUE,
    CLAPX_ERROR_INVALID_FLAG_VALUE,

    CLAPX_ERROR_COUNT
};

/**
 * Error type for clapx functions.
 */
typedef uint8_t clapx_error_code_t;

enum
{
    CLAPX_FLAG_TYPE_REQ_VALUE = 0,
    CLAPX_FLAG_TYPE_OPT_VALUE,
    CLAPX_FLAG_TYPE_NO_VALUE,

    CLAPX_FLAG_TYPE_COUNT
};

/**
 * The argument type of a flag.
 */
typedef uint8_t clapx_flag_type_t;

enum
{
    CLAPX_FLAG_VALUE_TYPE_BOOL = 0,
    CLAPX_FLAG_VALUE_TYPE_U8,
    CLAPX_FLAG_VALUE_TYPE_U16,
    CLAPX_FLAG_VALUE_TYPE_U32,
    CLAPX_FLAG_VALUE_TYPE_U64,
    CLAPX_FLAG_VALUE_TYPE_I8,
    CLAPX_FLAG_VALUE_TYPE_I16,
    CLAPX_FLAG_VALUE_TYPE_I32,
    CLAPX_FLAG_VALUE_TYPE_I64,
    CLAPX_FLAG_VALUE_TYPE_CHAR,
    CLAPX_FLAG_VALUE_TYPE_STRING,
    CLAPX_FLAG_VALUE_TYPE_CUSTOM,

    CLAPX_FLAG_VALUE_TYPE_COUNT
};

/**
 * The value type of a flag.
 */
typedef uint8_t clapx_flag_value_type_t;

/**
 * The callback function type for custom flags.
 * @param arg The argument to parse.
 * @return Returns 0 on success, any non-zero value otherwise.
 */
typedef uint8_t (*clapx_custom_parser_callback_t)(const char* arg);

/**
 * The callback function type for subcommands.
 */
typedef void (*clapx_subcommand_callback_t)(int argc, char** argv);

/**
 * The callback function type for flags.
 */
typedef void (*clapx_flag_callback_t)(void);

/**
 * Representation of a command-line flag.
 */
typedef struct clapx_flag
{
    clapx_flag_type_t type;
    clapx_flag_value_type_t value_type;
    const char* long_name;
    char short_name;
    clapx_flag_callback_t callback;
    union
    {
        uint8_t bool_value;
        uint8_t u8_value;
        uint16_t u16_value;
        uint32_t u32_value;
        uint64_t u64_value;
        int8_t i8_value;
        int16_t i16_value;
        int32_t i32_value;
        int64_t i64_value;
        char char_value;
        const char* string_value;
        clapx_custom_parser_callback_t custom_parser_callback;
    };
} clapx_flag_t;

/**
 * Representation of a subcommand.
 */
typedef struct clapx_subcommand
{
    const char* name;
    clapx_subcommand_callback_t callback;
    clapx_flag_t* flags;
    size_t flags_count;
} clapx_subcommand_t;

/**
 * Parses command-line arguments, flags and subcommands based on the CLAPX_FLAGS and CLAPX_SUBCOMMANDS macros.
 * @param argc The number of command-line arguments.
 * @param argv The array of argument strings.
 * @return Returns CLAPX_SUCCESS on success, any other value of type clapx_error_code_t otherwise.
 */
clapx_error_code_t clapx_parse_args(int argc, char** argv);

/**
 * Prints the default usage string.
 * @param argv0 The first element of argv.
 */
void clapx_print_usage_str(const char* argv0);

/**
 * Retrieves the longest long_name of all flags.
 * @return Returns the length of the string.
 */
size_t clapx_longest_long_name(void);

/**
 * Retrieves the longest subcommand name of all subcommands.
 * @return Returns the length of the subcommand name.
 */
size_t clapx_longest_subcommand_name(void);

/**
 * Parses an argument of a flag.
 * @param flag The flag.
 * @param arg The argument.
 * @return Returns CLAPX_SUCCESS on success, CLAPX_ERROR_INVALID_FLAG_VALUE otherwise.
 */
clapx_error_code_t clapx_parse_flag_arg(clapx_flag_t* flag, const char* arg);

/**
 * Default parser for bool flags.
 * @param value The value of the bool flag.
 * @return Returns CLAPX_SUCCESS on success, CLAPX_ERROR_INVALID_FLAG_VALUE otherwise.
 */
clapx_error_code_t clapx_bool_parser_callback(uint8_t* value);

/**
 * Default parser for string flags.
 * @param value The value of the string flag.
 * @param arg The argument to parse.
 * @return Returns CLAPX_SUCCESS on success, CLAPX_ERROR_INVALID_FLAG_VALUE otherwise.
 */
clapx_error_code_t clapx_string_parser_callback(const char** value, const char* arg);

#ifdef CLAPX_IMPLEMENTATION

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef CLAPX_BOOL_PARSER_CALLBACK
#define CLAPX_BOOL_PARSER_CALLBACK(value) clapx_bool_parser_callback(value)
#endif

#ifndef CLAPX_U8_PARSER_CALLBACK
#define CLAPX_U8_PARSER_CALLBACK(value, arg) clapx_u8_parser_callback(value, arg)
#endif

#ifndef CLAPX_U16_PARSER_CALLBACK
#define CLAPX_U16_PARSER_CALLBACK(value, arg) clapx_u16_parser_callback(value, arg)
#endif

#ifndef CLAPX_U32_PARSER_CALLBACK
#define CLAPX_U32_PARSER_CALLBACK(value, arg) clapx_u32_parser_callback(value, arg)
#endif

#ifndef CLAPX_U64_PARSER_CALLBACK
#define CLAPX_U64_PARSER_CALLBACK(value, arg) clapx_u64_parser_callback(value, arg)
#endif

#ifndef CLAPX_I8_PARSER_CALLBACK
#define CLAPX_I8_PARSER_CALLBACK(value, arg) clapx_i8_parser_callback(value, arg)
#endif

#ifndef CLAPX_I16_PARSER_CALLBACK
#define CLAPX_I16_PARSER_CALLBACK(value, arg) clapx_i16_parser_callback(value, arg)
#endif

#ifndef CLAPX_I32_PARSER_CALLBACK
#define CLAPX_I32_PARSER_CALLBACK(value, arg) clapx_i32_parser_callback(value, arg)
#endif

#ifndef CLAPX_I64_PARSER_CALLBACK
#define CLAPX_I64_PARSER_CALLBACK(value, arg) clapx_i64_parser_callback(value, arg)
#endif

#ifndef CLAPX_CHAR_PARSER_CALLBACK
#define CLAPX_CHAR_PARSER_CALLBACK(value, arg) clapx_char_parser_callback(value, arg)
#endif

#ifndef CLAPX_STRING_PARSER_CALLBACK
#define CLAPX_STRING_PARSER_CALLBACK(value, arg) clapx_string_parser_callback(value, arg)
#endif

#ifndef CLAPX_POS_ARGS_CALLBACK
#define CLAPX_POS_ARGS_CALLBACK
#endif

#ifndef CLAPX_INVALID_SUBCOMMAND_CALLBACK
#define CLAPX_INVALID_SUBCOMMAND_CALLBACK
#endif

#ifndef CLAPX_INVALID_LONG_FLAG_CALLBACK
#define CLAPX_INVALID_LONG_FLAG_CALLBACK
#endif

#ifndef CLAPX_INVALID_LONG_FLAG_VALUE_CALLBACK
#define CLAPX_INVALID_LONG_FLAG_VALUE_CALLBACK
#endif

#ifndef CLAPX_MISSING_LONG_FLAG_REQ_VALUE_CALLBACK
#define CLAPX_MISSING_LONG_FLAG_REQ_VALUE_CALLBACK
#endif

#ifndef CLAPX_INVALID_SHORT_FLAG_CALLBACK
#define CLAPX_INVALID_SHORT_FLAG_CALLBACK
#endif

#ifndef CLAPX_INVALID_SHORT_FLAG_VALUE_CALLBACK
#define CLAPX_INVALID_SHORT_FLAG_VALUE_CALLBACK
#endif

#ifndef CLAPX_MISSING_SHORT_FLAG_REQ_VALUE_CALLBACK
#define CLAPX_MISSING_SHORT_FLAG_REQ_VALUE_CALLBACK
#endif

#ifndef CLAPX_ERROR_INVALID_FLAG_VALUE_CALLBACK
#define CLAPX_ERROR_INVALID_FLAG_VALUE_CALLBACK
#endif

#ifndef CLAPX_USAGE_STR_COLUMN_GAP
#define CLAPX_USAGE_STR_COLUMN_GAP 6
#endif

// Generate enum for indexing flags based on their label
#ifdef CLAPX_FLAGS
#define CLAPX_FLAG(label, type, value_type, long_name, short_name, callback, default_value) \
    CLAPX_FLAG_INDEX_##label,
enum
{
    CLAPX_FLAGS
    CLAPX_FLAGS_COUNT
};
#undef CLAPX_FLAG
#else
#define CLAPX_FLAGS_COUNT 0
#endif

// Generate array of flags
#ifdef CLAPX_FLAGS
#define CLAPX_FLAG(label, type, value_type, long_name, short_name, callback, default_value) \
    (clapx_flag_t){ type, value_type, long_name, short_name, callback, default_value},
static clapx_flag_t clapx_flags[] = { CLAPX_FLAGS };
#undef CLAPX_FLAG
#endif

// Assert valid flags
#ifdef CLAPX_FLAGS
#define CLAPX_FLAG(label, type, value_type, long_name, short_name, callback, default_value) \
    static_assert(long_name != CLAPX_NO_LONG || short_name != CLAPX_NO_SHORT, "Flags must not specify both CLAPX_NO_LONG and CLAPX_NO_SHORT!"); \
    static_assert(long_name == CLAPX_NO_LONG || strlen(long_name) > 1, "Long names must have a length of at least 2!"); \
    static_assert(short_name == CLAPX_NO_SHORT \
                  || (short_name >= 'a' && short_name <= 'z') \
                  || (short_name >= 'A' && short_name <= 'Z') \
                  || (short_name >= '0' && short_name <= '9'), "Short name must be alphanumeric!");
CLAPX_FLAGS
#undef CLAPX_FLAG
#endif

// Generate enum for indexing subcommands based on their label
#ifdef CLAPX_SUBCOMMANDS
#define CLAPX_SUBCOMMAND(label, name, callback, ...) \
    CLAPX_SUBCOMMAND_INDEX_##label,
enum
{
    CLAPX_SUBCOMMANDS
    CLAPX_SUBCOMMANDS_COUNT
};
#undef CLAPX_SUBCOMMAND
#endif

// Generate enums for indexing subcommand flags based on their label
#ifdef CLAPX_SUBCOMMANDS
#define CLAPX_SUBCOMMAND(label, name, callback, ...) \
    enum { __VA_ARGS__ CLAPX_SUBCOMMAND_##label##_COUNT };
#define CLAPX_FLAG(label, type, value_type, long_name, short_name, callback, default_value) \
    CLAPX_FLAG_INDEX_##label,
CLAPX_SUBCOMMANDS
#undef CLAPX_FLAG
#undef CLAPX_SUBCOMMAND
#endif

// Generate array of subcommands
#ifdef CLAPX_SUBCOMMANDS
#define CLAPX_SUBCOMMAND(label, name, callback, ...) \
    { name, callback, (clapx_flag_t[]){ __VA_ARGS__ }, sizeof((clapx_flag_t[]){ __VA_ARGS__ }) / sizeof(clapx_flag_t) },
#define CLAPX_FLAG(label, type, value_type, long_name, short_name, callback, default_value) \
    (clapx_flag_t){ type, value_type, long_name, short_name, callback, default_value }
static clapx_subcommand_t clapx_subcommands[] = { CLAPX_SUBCOMMANDS };
#undef CLAPX_FLAG
#undef CLAPX_SUBCOMMAND
#endif

// Assert valid subcommand flags
#ifdef CLAPX_SUBCOMMANDS
#define CLAPX_SUBCOMMAND(label, name, callback, ...) __VA_ARGS__
#define CLAPX_FLAG(label, type, value_type, long_name, short_name, callback, default_value) \
    static_assert(long_name != CLAPX_NO_LONG || short_name != CLAPX_NO_SHORT, "Flags must not specify both CLAPX_NO_LONG and CLAPX_NO_SHORT!");
CLAPX_SUBCOMMANDS
#undef CLAPX_FLAG
#undef CLAPX_SUBCOMMAND
#endif

clapx_error_code_t clapx_parse_args(int argc, char** argv)
{
    static uint8_t options_delimiter_parsed = 0;

#ifdef CLAPX_FLAGS
    clapx_flag_t* flags_arr = clapx_flags;
#else
    clapx_flag_t* flags_arr = NULL;
#endif

    size_t flags_count = CLAPX_FLAGS_COUNT;

#ifdef CLAPX_SUBCOMMANDS
    clapx_subcommand_t* parsed_subcommand = NULL;
#endif

    char* pos_args[argc - 1];
    size_t pos_args_count = 0;

    for (size_t i = 1; i < argc; ++i)
    {
        const char* arg = argv[i];
        if (options_delimiter_parsed || arg[0] != '-')
        {
#ifdef CLAPX_SUBCOMMANDS
            if (parsed_subcommand == NULL)
            {
                for (size_t j = 0; j < CLAPX_SUBCOMMANDS_COUNT; ++j)
                {
                    clapx_subcommand_t* subcommand = &clapx_subcommands[j];
                    if (strcmp(subcommand->name, arg) == 0)
                    {
                        flags_arr = subcommand->flags;
                        flags_count = subcommand->flags_count;
                        parsed_subcommand = subcommand;

                        break;
                    }
                }

                if (parsed_subcommand == NULL)
                {
                    CLAPX_INVALID_SUBCOMMAND_CALLBACK(arg);
                    return CLAPX_ERROR_INVALID_SUBCOMMAND;
                }

            }
            else
            {
                pos_args[pos_args_count++] = (char*)arg;
            }
#else
            pos_args[pos_args_count++] = (char*)arg;
#endif

            continue;
        }

        if (arg[1] == '-')
        {
            // Handle options delimiter
            if (arg[2] == '\0')
            {
                options_delimiter_parsed = 1;
                continue;
            }

            // Handle long flags
            const char* flag_str = arg + 2;
            size_t flag_len = strlen(flag_str);
            const char* flag_arg = NULL;
            char* equals = strchr(arg, '=');
            if (equals)
            {
                flag_arg = equals + 1;
                flag_len = equals - flag_str;
            }

            uint8_t flag_found = 0;
#if defined(CLAPX_FLAGS) || defined(CLAPX_SUBCOMMANDS)
            for (size_t j = 0; j < flags_count; ++j)
            {
                clapx_flag_t* flag = &flags_arr[j];

                if (flag->long_name == NULL || strncmp(flag->long_name, flag_str, flag_len) != 0)
                {
                    continue;
                }

                flag_found = 1;
                const char* final_flag_arg = NULL;

                if (flag->type != CLAPX_FLAG_TYPE_NO_VALUE)
                {
                    final_flag_arg = flag_arg;
                }
                else if (flag_arg != NULL)
                {
                    CLAPX_INVALID_LONG_FLAG_VALUE_CALLBACK(flag->long_name, flag_arg);
                    return CLAPX_ERROR_INVALID_LONG_FLAG_VALUE;
                }

                if (flag_arg == NULL && flag->type == CLAPX_FLAG_TYPE_REQ_VALUE)
                {
                    if (i + 1 < argc)
                    {
                        final_flag_arg = argv[++i];
                    }
                    else
                    {
                        CLAPX_MISSING_LONG_FLAG_REQ_VALUE_CALLBACK(flag->long_name);
                        return CLAPX_ERROR_MISSING_LONG_FLAG_REQ_VALUE;
                    }
                }

                clapx_error_code_t parse_result = clapx_parse_flag_arg(flag, final_flag_arg);
                if (parse_result != CLAPX_SUCCESS)
                {
                    CLAPX_ERROR_INVALID_FLAG_VALUE_CALLBACK(final_flag_arg);
                    return CLAPX_ERROR_INVALID_FLAG_VALUE;
                }

                if (flag->callback != CLAPX_NO_CALLBACK)
                {
                    flag->callback();
                }

                break;
            }
#endif

            if (!flag_found)
            {
                if (equals)
                {
                    *equals = '\0';
                }

                CLAPX_INVALID_LONG_FLAG_CALLBACK(flag_str);

                if (equals)
                {
                    *equals = '=';
                }

                return CLAPX_ERROR_INVALID_LONG_FLAG;
            }
        }
        else
        {
            // Handle short flags
            const char* flag_str = arg + 1;
            const char* flag_arg = flag_str + 1;

            while (*flag_str != '\0')
            {
                uint8_t flag_found = 0;
#if defined(CLAPX_FLAGS) || defined(CLAPX_SUBCOMMANDS)
                for (size_t j = 0; j < flags_count; ++j)
                {
                    clapx_flag_t* flag = &flags_arr[j];

                    if (flag->short_name != *flag_str)
                    {
                        continue;
                    }

                    flag_found = 1;
                    const char* final_flag_arg = NULL;

                    if (flag->type != CLAPX_FLAG_TYPE_NO_VALUE)
                    {
                        final_flag_arg = flag_arg;
                    }
                    else if (*flag_arg != '\0')
                    {
                        CLAPX_INVALID_SHORT_FLAG_VALUE_CALLBACK(flag->short_name, flag_arg);
                        return CLAPX_ERROR_INVALID_SHORT_FLAG_VALUE;
                    }

                    if (*flag_arg == '\0' && flag->type == CLAPX_FLAG_TYPE_REQ_VALUE)
                    {
                        if (i + 1 < argc)
                        {
                            final_flag_arg = argv[++i];
                        }
                        else
                        {
                            CLAPX_MISSING_SHORT_FLAG_REQ_VALUE_CALLBACK(flag->short_name);
                            return CLAPX_ERROR_MISSING_SHORT_FLAG_REQ_VALUE;
                        }
                    }

                    clapx_error_code_t parse_result = clapx_parse_flag_arg(flag, final_flag_arg);
                    if (parse_result != CLAPX_SUCCESS)
                    {
                        CLAPX_ERROR_INVALID_FLAG_VALUE_CALLBACK(final_flag_arg);
                        return CLAPX_ERROR_INVALID_FLAG_VALUE;
                    }

                    if (flag->callback != CLAPX_NO_CALLBACK)
                    {
                        flag->callback();
                    }
                }
#endif

                if (!flag_found)
                {
                    CLAPX_INVALID_SHORT_FLAG_CALLBACK(*flag_str);
                    return CLAPX_ERROR_INVALID_SHORT_FLAG;
                }

                ++flag_str;
                ++flag_arg;
            }
        }
    }

#ifdef CLAPX_SUBCOMMANDS
    if (parsed_subcommand != NULL)
    {
        parsed_subcommand->callback(pos_args_count, pos_args);
    }
#endif

    CLAPX_POS_ARGS_CALLBACK(pos_args_count, pos_args);

    return CLAPX_SUCCESS;
}

void clapx_print_usage_str(const char* argv0)
{
#ifdef CLAPX_FLAGS
#ifdef CLAPX_SUBCOMMANDS
    printf("usage: %s [GLOBAL FLAG]... [SUBCOMMAND] [FLAG]... [ARG]...\n", argv0);
#else
    printf("usage: %s [FLAG]... [ARG]...\n", argv0);
#endif
#else
#ifdef CLAPX_SUBCOMMANDS
    printf("usage: %s [SUBCOMMAND] [FLAG]... [ARG]...\n", argv0);
#else
    printf("usage: %s [ARG]...", argv0);
#endif
#endif

    size_t max_subcommand_flag_width = strlen("    -, --") + 1 + clapx_longest_long_name();
    size_t max_subcommand_width = strlen("  ") + clapx_longest_subcommand_name();

    size_t max_width = max_subcommand_width > max_subcommand_flag_width ? max_subcommand_width : max_subcommand_flag_width;
    max_width += CLAPX_USAGE_STR_COLUMN_GAP;

#ifdef CLAPX_FLAGS
#ifdef CLAPX_SUBCOMMANDS
    printf("\n[GLOBAL FLAG]S\n");
#else
    printf("\n[FLAG]S\n");
#endif

#define CLAPX_FLAG(label, type, value_type, long_name, short_name, callback, default_value) \
    if (long_name != CLAPX_NO_LONG && short_name != CLAPX_NO_SHORT) \
    { \
        for (size_t i = printf("    -%c, --%s", short_name, long_name); i < max_width; ++i) \
        { \
            printf(" "); \
        } \
        \
    } \
    else if (long_name != CLAPX_NO_LONG) \
    { \
        for (size_t i = printf("        --%s", long_name); i < max_width; ++i) \
        { \
            printf(" "); \
        } \
        \
    } \
    else \
    { \
        for (size_t i = printf("    -%c    ", short_name); i < max_width; ++i) \
        { \
            printf(" "); \
        } \
        \
    }\
    \
    printf("\n");
CLAPX_FLAGS
#undef CLAPX_FLAG
#endif

#ifdef CLAPX_SUBCOMMANDS
    printf("\n[SUBCOMMAND]S");
#define CLAPX_SUBCOMMAND(label, name, callback, ...) \
    printf("\n"); \
    \
    for (size_t i = printf("  %s", name); i < max_width; ++i) \
    { \
        printf(" "); \
    }\
    \
    printf("\n"); \
    __VA_ARGS__
#define CLAPX_FLAG(label, type, value_type, long_name, short_name, callback, default_value) \
    if (long_name != CLAPX_NO_LONG && short_name != CLAPX_NO_SHORT) \
    { \
        for (size_t i = printf("    -%c, --%s", short_name, long_name); i < max_width; ++i) \
        { \
            printf(" "); \
        } \
        \
    } \
    else if (long_name != CLAPX_NO_LONG) \
    { \
        for (size_t i = printf("        --%s", long_name); i < max_width; ++i) \
        { \
            printf(" "); \
        } \
        \
    } \
    else \
    { \
        for (size_t i = printf("    -%c    ", short_name); i < max_width; ++i) \
        { \
            printf(" "); \
        } \
        \
    } \
    \
    printf("\n");
CLAPX_SUBCOMMANDS
#undef CLAPX_FLAG
#undef CLAPX_SUBCOMMAND
#endif
}

size_t clapx_longest_long_name(void)
{
    size_t result = 0;
#ifdef CLAPX_FLAGS
#define CLAPX_FLAG(label, type, value_type, long_name, short_name, callback, default_value) \
    if (long_name != CLAPX_NO_LONG && result < strlen(long_name)) result = strlen(long_name);
CLAPX_FLAGS
#undef CLAPX_FLAG
#endif

#ifdef CLAPX_SUBCOMMANDS
#define CLAPX_SUBCOMMAND(label, name, callback, ...) \
    __VA_ARGS__
#define CLAPX_FLAG(label, type, value_type, long_name, short_name, callback, default_value) \
    if (long_name != CLAPX_NO_LONG && result < strlen(long_name)) result = strlen(long_name);
CLAPX_SUBCOMMANDS
#undef CLAPX_FLAG
#undef CLAPX_SUBCOMMAND
#endif

    return result;
}

size_t clapx_longest_subcommand_name(void)
{
    size_t result = 0;

#ifdef CLAPX_SUBCOMMANDS
#define CLAPX_SUBCOMMAND(label, name, callback, ...) \
    if (name != CLAPX_NO_LONG && result < strlen(name)) result = strlen(name);
CLAPX_SUBCOMMANDS
#undef CLAPX_SUBCOMMAND
#endif

    return result;
}

clapx_error_code_t clapx_parse_flag_arg(clapx_flag_t* flag, const char* arg)
{
    switch (flag->value_type)
    {
        case CLAPX_FLAG_VALUE_TYPE_BOOL: return CLAPX_BOOL_PARSER_CALLBACK(&flag->bool_value);
        case CLAPX_FLAG_VALUE_TYPE_STRING: return CLAPX_STRING_PARSER_CALLBACK(&flag->string_value, arg);
        case CLAPX_FLAG_VALUE_TYPE_CUSTOM: return flag->custom_parser_callback(arg) == 0 ? CLAPX_SUCCESS : CLAPX_ERROR_INVALID_FLAG_VALUE;
        default: return CLAPX_ERROR_INVALID_FLAG_VALUE;
    }
}

clapx_error_code_t clapx_bool_parser_callback(uint8_t* value)
{
    *value = 1;

    return CLAPX_SUCCESS;
}

clapx_error_code_t clapx_u8_parser_callback(uint8_t* value, const char* arg)
{
    uint64_t number = strtoull(arg, NULL, 10);

    if (number <= UINT8_MAX)
    {
        *value = number;
        return CLAPX_SUCCESS;
    }

    return CLAPX_ERROR_INVALID_FLAG_VALUE;
}

clapx_error_code_t clapx_u16_parser_callback(uint16_t* value, const char* arg)
{
    uint64_t number = strtoull(arg, NULL, 10);

    if (number <= UINT16_MAX)
    {
        *value = number;
        return CLAPX_SUCCESS;
    }

    return CLAPX_ERROR_INVALID_FLAG_VALUE;
}

clapx_error_code_t clapx_u32_parser_callback(uint32_t* value, const char* arg)
{
    uint64_t number = strtoull(arg, NULL, 10);

    if (number <= UINT32_MAX)
    {
        *value = number;
        return CLAPX_SUCCESS;
    }

    return CLAPX_ERROR_INVALID_FLAG_VALUE;
}

clapx_error_code_t clapx_u64_parser_callback(uint64_t* value, const char* arg)
{
    uint64_t number = strtoull(arg, NULL, 10);

    if (number <= UINT64_MAX)
    {
        *value = number;
        return CLAPX_SUCCESS;
    }

    return CLAPX_ERROR_INVALID_FLAG_VALUE;
}

clapx_error_code_t clapx_i8_parser_callback(int8_t* value, const char* arg)
{
    int64_t number = strtoll(arg, NULL, 10);

    if (number >= INT8_MIN && number <= INT8_MAX)
    {
        *value = number;
        return CLAPX_SUCCESS;
    }

    return CLAPX_ERROR_INVALID_FLAG_VALUE;
}

clapx_error_code_t clapx_i16_parser_callback(int16_t* value, const char* arg)
{
    int64_t number = strtoll(arg, NULL, 10);

    if (number >= INT16_MIN && number <= INT16_MAX)
    {
        *value = number;
        return CLAPX_SUCCESS;
    }

    return CLAPX_ERROR_INVALID_FLAG_VALUE;
}

clapx_error_code_t clapx_i32_parser_callback(int32_t* value, const char* arg)
{
    int64_t number = strtoll(arg, NULL, 10);

    if (number >= INT32_MIN && number <= INT32_MAX)
    {
        *value = number;
        return CLAPX_SUCCESS;
    }

    return CLAPX_ERROR_INVALID_FLAG_VALUE;
}

clapx_error_code_t clapx_i64_parser_callback(int64_t* value, const char* arg)
{
    int64_t number = strtoll(arg, NULL, 10);

    if (number >= INT64_MIN && number <= INT64_MAX)
    {
        *value = number;
        return CLAPX_SUCCESS;
    }

    return CLAPX_ERROR_INVALID_FLAG_VALUE;
}

clapx_error_code_t clapx_char_parser_callback(char* value, const char* arg)
{
    *value = arg[0];

    return strlen(arg) == 1 ? CLAPX_SUCCESS : CLAPX_ERROR_INVALID_FLAG_VALUE;
}

clapx_error_code_t clapx_string_parser_callback(const char** value, const char* arg)
{
    *value = arg;

    return CLAPX_SUCCESS;
}

#endif

#endif
