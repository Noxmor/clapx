# Copyright (c) 2025 Noxmor

.PHONY: install uninstall

NAME=clapx
PREFIX?=/usr/local

install:
	@echo "Installing $(NAME)..."
	mkdir -p $(PREFIX)/include/$(NAME)
	cp -r ./include/. $(PREFIX)/include/$(NAME)
	@echo "Successfully installed $(NAME)"

uninstall:
	@echo "Uninstalling $(NAME)..."
	rm -rf $(PREFIX)/include/$(NAME)
	@echo "Successfully uninstalled $(NAME)"
