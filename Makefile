NAME		:=	libasm.a

SHELL		=	/bin/sh
RM			=	rm -rf

.SUFFIXE:
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
IFLAGS		=	-I$(TEST_PATH)
LFLAGS		=	-L -lasm

# ******************************** DIR AND PATHS ***************************** #

TEST_PATH	=	$(shell find tests -type d)
OBJ_PATH	=	obj

ifeq ($(OS), Linux)
	SRC_PATH = $(shell find src/linux -type d)
endif

ifeq ($(OS), MacOS)
	SRC_PATH = $(shell find src/osx -type d)
endif

INC			=	$(addprefix $(TEST_PATH)/, $(INC_FILES))
OBJ			=	$(addprefix $(OBJ_PATH)/, $(SRC:%.s=%.o))
TEST		=	$(addprefix $(TEST_PATH)/, $(TEST_FILES))

vpath %.s $(foreach dir, $(SRC_PATH), $(dir):)

# ********************************** FILES *********************************** #

INC_FILES	=	libasm.h

TEST_FILES	=	main.c

SRC			=	ft_strlen.s

# ********************************** RULES *********************************** #

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ)
	@$(LD) -o $@ $(OBJ)
	@echo "\nOK\t\t$(NAME) is ready"

# OBJ DIR #

$(OBJ_PATH):
	@mkdir -p $@
	@echo "Created\t\t$@ directory"

# COMPILING #

$(OBJ_PATH)/%.o : %.s
	@echo "\r\033[KCompiling\t$< \c"
	@$(ASM) $(ASFLAGS) $< -o $@

# DEBUG #

.PHONY: show
show:
	@echo "OS: $(OS_NAME)"
	@echo "SRC_PATH: $(SRC_PATH)"

.PHONY: debug
debug: $(NAME)
	@$(CC) $(CFLAGS) $(TEST) $(LFLAGS) -o test_libasm
	@$(RM) main.o
	./test_libasm

# CLEAN #

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
