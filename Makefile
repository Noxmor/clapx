# Copyright (c) 2025 Noxmor

.PHONY: install uninstall

NAME="clapx"
PREFIX="$(HOME)/.local/include"

install:
	@echo "Installing $(NAME)..."
	mkdir -p $(PREFIX)/$(NAME)
	cp -r ./include/. $(PREFIX)/$(NAME)
	@echo "Successfully installed $(NAME)"

uninstall:
	@echo "Uninstalling $(NAME)..."
	rm -rf $(PREFIX)/$(NAME)
	@echo "Successfully uninstalled $(NAME)"
