NAME		=	libasm.a

SHELL		=	/bin/sh

ASM			=	nasm
ASFLAGS		=	-f elf64
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
IFLAGS		=	-I$(TEST_PATH)
LFLAGS		=	-L -lasm

RM			=	rm -rf

.SUFFIXE:
.SUFFIXES: .s .c .o .h

TEST_PATH	=	$(shell find tests -type d)
SRC_PATH	=	$(shell find src -type d)
OBJ_PATH	=	obj

vpath %.s $(foreach dir, $(SRC_PATH), $(dir):)

INC_FILES	=	libasm.h
INC			=	$(addprefix $(TEST_PATH)/, $(INC_FILES))

TEST_FILES	=	main.c
TEST		=	$(addprefix $(TEST_PATH)/, $(TEST_FILES))

SRC			=	ft_strlen.s

OBJ			=	$(addprefix $(OBJ_PATH)/, $(SRC:%.s=%.o))

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ)
	@$(LD) -o $@ $(OBJ)
	@echo "\nOK\t\t$(NAME) is ready"

$(OBJ_PATH):
	@mkdir -p $@
	@echo "Created\t\t$@ directory"

$(OBJ_PATH)/%.o : %.s
	@echo "\r\033[KCompiling\t$< \c"
	@$(ASM) $(ASFLAGS) $< -o $@

.PHONY: debug
debug: $(NAME)
	@$(CC) $(CFLAGS) $(TEST) $(LFLAGS) -o test_libasm
	@$(RM) main.o
	./test_libasm

.PHONY: clean
clean:
	@$(RM) $(OBJ_PATH) test_libasm
	@echo "Cleaned\t\tobject files"

.PHONY: fclean
fclean: clean
	@$(RM) $(NAME)
	@echo "Removed\t\t$(NAME)"

.PHONY: re
re: fclean all
