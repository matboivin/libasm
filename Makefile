NAME := libasm.a

SHELL = /bin/sh
RM = /bin/rm

.SUFFIXES:
.SUFFIXES: .s .c .o .h

# ********************************* S FILES ********************************** #

SRC_FILES	=	ft_strcmp.s				\
				ft_strcpy.s				\
				ft_strdup.s				\
				ft_strlen.s				\
				ft_read.s				\
				ft_write.s				\
				ft_list_size.s			\
				ft_list_push_front.s	\
				libasm.s

SRC_BONUS	=	ft_list_size.s

# ******************************** TEST FILES ******************************** #

INC_FILES	=	libasm.h libasm_tests.h

TEST_FILES	=	main.c					\
				launch_tests.c			\
				result_count.c			\
				check_errno_val.c		\
				check_return.c			\
				test_ft_strcmp.c		\
				test_ft_strcpy.c		\
				test_ft_strdup.c		\
				test_ft_strlen.c		\
				test_ft_read.c			\
				test_ft_write.c			\
				test_ft_list_size.c

# ********************************* OBJECTS ********************************** #

OBJ_FILES = $(SRC_FILES:%.s=%.o)
OBJ_BONUS_FILES = $(SRC_BONUS:%.s=%.o)

# ********************************* PLATFORM ********************************* #

OS_NAME = $(shell uname -s)

ifeq ($(OS_NAME), Linux)
	OS = Linux
endif

ifeq ($(OS_NAME), Darwin)
	OS = MacOS
endif

# ******************************* DIRS AND PATHS ***************************** #

ifeq ($(OS), Linux)
	SRC_DIR = src/linux
endif

ifeq ($(OS), MacOS)
	SRC_DIR = src/macos
endif

TEST_DIR	=	tests
OBJ_DIR		=	obj

INC			=	$(addprefix $(TEST_DIR)/, $(INC_FILES))
TEST		=	$(addprefix $(TEST_DIR)/, $(TEST_FILES))
OBJ			=	$(addprefix $(OBJ_DIR)/, $(OBJ_FILES))
OBJ_BONUS	=	$(addprefix $(OBJ_DIR)/, $(OBJ_BONUS_FILES))

VPATH		=	$(SRC_DIR) $(TEST_DIR)

# *************************** COMPILING AND FLAGS **************************** #

AS = nasm

ifeq ($(OS), Linux)
	ASFLAGS = -f elf64
endif

ifeq ($(OS), MacOS)
	ASFLAGS = -f macho64
endif

CC = clang
AR = ar

ARFLAGS = -rcs
CFLAGS = -Wall -Wextra -Werror -g3
CPPFLAGS = -I$(TEST_DIR)
LDFLAGS = -L.
LDLIBS = -lasm

# ********************************** RULES *********************************** #

all: $(NAME)

# OBJ DIR #

$(OBJ_DIR):
	@mkdir -p $@
	@echo "Created\t\t$@ directory"

# COMPILING #

$(OBJ_DIR)/%.o : %.s
	@echo "\r\033[KCompiling\t$< \c"
	@$(AS) $(ASFLAGS) $< -o $@

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(AR) $(ARFLAGS) -o $@ $(OBJ)
	@echo "\nOK\t\t$(NAME) is ready"

# BONUS #

bonus: $(NAME) $(OBJ_BONUS)
	@$(AR) $(ARFLAGS) -o $(NAME) $(OBJ_BONUS)
	@echo "\nOK\t\tAdded bonus files to $(NAME)"

# DEBUG #

show:
	@echo "OS: $(OS_NAME)"
	@echo "SRC_DIR: $(SRC_DIR)"

debug: $(NAME)
	@$(CC) $(CPPFLAGS) $(CFLAGS) $(TEST) $(LDFLAGS) $(LDLIBS) -o test_libasm
	@echo "\nOK\t\tCreated test executable\n"
	@./test_libasm -h

# CLEAN #

clean:
	@$(RM) -rf $(OBJ_DIR) test_libasm
	@echo "Cleaned\t\tobject files"

fclean: clean
	@$(RM) -f $(NAME)
	@echo "Removed\t\t$(NAME)"

re: fclean all

.PHONY: all bonus show debug clean fclean re
