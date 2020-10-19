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

CC			=	clang
AR			=	ar

ARFLAGS		=	-rcs
CFLAGS		=	-Wall -Wextra -Werror -g3
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

VPATH		=	$(SRC_DIR) $(TEST_DIR)

# ********************************** FILES *********************************** #

INC_FILES	=	libasm.h libasm_tests.h

TEST_FILES	=	main.c				\
				check_errno_val.c	\
				check_return.c		\
				test_ft_strcmp.c	\
				test_ft_strcpy.c	\
				test_ft_strdup.c	\
				test_ft_strlen.c	\
				test_ft_read.c		\
				test_ft_write.c		\
				result_count.c

SRC			=	ft_strcmp.s			\
				ft_strcpy.s			\
				ft_strdup.s			\
				ft_strlen.s			\
				ft_read.s			\
				ft_write.s

# ********************************** RULES *********************************** #

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(AR) $(ARFLAGS) -o $@ $(OBJ)
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

show:
	@echo "OS: $(OS_NAME)"
	@echo "SRC_DIR: $(SRC_DIR)"

debug: $(NAME)
	@$(CC) $(CFLAGS) $(IFLAGS) $(TEST) -o test_libasm $(LFLAGS)
	./test_libasm

# CLEAN #

clean:
	@$(RM) -rf $(OBJ_DIR) test_libasm
	@echo "Cleaned\t\tobject files"

fclean: clean
	@$(RM) $(NAME)
	@echo "Removed\t\t$(NAME)"

re: fclean all

.PHONY: all show debug clean fclean re
