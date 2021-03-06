NAME := libasm.a

RM = /bin/rm

.SUFFIXES:
.SUFFIXES: .s .c .o .h

# ********************************* S FILES ********************************** #

SRC_FILES	=	ft_strcmp.s					\
				ft_strcpy.s					\
				ft_strdup.s					\
				ft_strlen.s					\
				ft_read.s					\
				ft_write.s					\
				libasm.s

SRC_BONUS	=	ft_list_size.s

# ******************************** TEST FILES ******************************** #

INC_FILES	=	libasm.h libasm_test.h

TEST_FILES	=	main.c						\
				test_counter.c				\
				test_ft_list_size.c			\
				test_ft_read.c				\
				test_ft_strcmp.c			\
				test_ft_strcpy.c			\
				test_ft_strdup.c			\
				test_ft_strlen.c			\
				test_ft_write.c				\
				test_launchers.c			\
				test_list_utils.c			\
				test_str_utils.c			\
				test_utils.c

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

VPATH		=	$(SRC_DIR) $(TEST_DIR) $(TEST_DIR)/utils

# *************************** COMPILING AND FLAGS **************************** #

ifeq ($(OS), Linux)
	AS = nasm
	ASFLAGS = -f elf64
endif

ifeq ($(OS), MacOS)
	AS = /usr/local/bin/nasm
	ASFLAGS = -f macho64
endif

CC = clang
AR = ar

ARFLAGS = rc
CFLAGS = -Wall -Wextra -Werror
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

# ARCHIVING AND INDEXING #

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(AR) $(ARFLAGS) $@ $(OBJ)
	@echo "\nOK\t\t$@ is ready"

# BONUS #

bonus: $(NAME) $(OBJ_BONUS)
	@$(AR) $(ARFLAGS) -o $(NAME) $(OBJ_BONUS)
	@echo "OK\t\tAdded bonus files to $(NAME)"

# DEBUG #

show:
	@echo "OS: $(OS)"
	@echo "SRC_DIR: $(SRC_DIR)"

build_test: re bonus
	@$(CC) $(CPPFLAGS) $(CFLAGS) $(TEST) $(LDFLAGS) $(LDLIBS) -o libasm_tester
	@echo "OK\t\tCreated test executable"

debug: build_test
	@./libasm_tester --bonus

# CLEAN #

clean:
	@$(RM) -rf $(OBJ_DIR) libasm_tester
	@echo "Cleaned\t\tobject files"

fclean: clean
	@$(RM) -f $(NAME)
	@echo "Removed\t\t$(NAME)"

re: fclean all

.PHONY: all bonus show build_test debug clean fclean re
