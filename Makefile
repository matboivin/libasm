NAME		:=	libasm.a

SHELL		=	/bin/sh
RM			=	rm -rf

.SUFFIXE:
.SUFFIXES: .s .c .o .h

# ******************************** CC AND FLAGS ****************************** #

ASM			=	nasm
ASFLAGS		=	-f elf64

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
IFLAGS		=	-I$(TEST_PATH)
LFLAGS		=	-L -lasm

# ******************************** DIR AND PATHS ***************************** #

TEST_PATH	=	$(shell find tests -type d)
SRC_PATH	=	$(shell find src -type d)
OBJ_PATH	=	obj

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
