NAME		:=	libasm.a

SHELL		=	/bin/sh
RM			=	/bin/rm

.SUFFIXES:
.SUFFIXES: .s .c .o .h

# ********************************** PLATFORM ******************************** #

OS_NAME = $(shell uname -s)

ifeq ($(OS_NAME), Linux)
	OS = Linux
endif

ifeq ($(OS_NAME), Darwin)
	OS = MacOS
endif

# ******************************** CC AND FLAGS ****************************** #

ASM			=	nasm

ifeq ($(OS), Linux)
	ASFLAGS = -f elf64
endif

ifeq ($(OS), MacOS)
	ASFLAGS = -f macho64
endif

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror
IFLAGS		=	-I$(TEST_DIR)
LFLAGS		=	-L. -lasm

# ******************************* DIRS AND PATHS ***************************** #

TEST_DIR	=	tests
OBJ_DIR		=	obj

ifeq ($(OS), Linux)
	SRC_DIR = src/linux
endif

ifeq ($(OS), MacOS)
	SRC_DIR = src/osx
endif

INC			=	$(addprefix $(TEST_DIR)/, $(INC_FILES))
OBJ			=	$(addprefix $(OBJ_DIR)/, $(SRC:%.s=%.o))
TEST		=	$(addprefix $(TEST_DIR)/, $(TEST_FILES))

VPATH		=	$(SRC_DIR)

# ********************************** FILES *********************************** #

INC_FILES	=	libasm.h

TEST_FILES	=	main.c

SRC			=	ft_strlen.s ft_write.s

# ********************************** RULES *********************************** #

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(LD) -o $@ $(OBJ)
	@echo "\nOK\t\t$(NAME) is ready"

# OBJ DIR #

$(OBJ_DIR):
	@mkdir -p $@
	@echo "Created\t\t$@ directory"

# COMPILING #

$(OBJ_DIR)/%.o : %.s
	@echo "\r\033[KCompiling\t$< \c"
	@$(ASM) $(ASFLAGS) $< -o $@

# DEBUG #

.PHONY: show
show:
	@echo "OS: $(OS_NAME)"
	@echo "SRC_DIR: $(SRC_DIR)"

.PHONY: debug
debug: $(NAME)
	@$(CC) $(CFLAGS) $(TEST) $(LFLAGS) -o test_libasm
	./test_libasm

# CLEAN #

.PHONY: clean
clean:
	@$(RM) -rf $(OBJ_DIR) test_libasm
	@echo "Cleaned\t\tobject files"

.PHONY: fclean
fclean: clean
	@$(RM) $(NAME)
	@echo "Removed\t\t$(NAME)"

.PHONY: re
re: fclean all
