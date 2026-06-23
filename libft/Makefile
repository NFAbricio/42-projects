CFLAGS  = -Wall -Wextra -Werror
CC  = cc
NAME    = libft.a
FLAGLIB = -rcs
RM = rm -f
TEST = ../tests/test_libft.c
TEST_BIN = ../tests/test_libft

FUNC = ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
                ft_isprint.c ft_memcmp.c ft_memset.c ft_strchr.c ft_strlcat.c\
                ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c\
                ft_tolower.c ft_toupper.c ft_bzero.c ft_calloc.c ft_memchr.c\
				ft_memcpy.c memmove.c ft_strdup.c ft_itoa.c ft_strtrim.c\
                ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c\
                ft_putendl_fd.c ft_putnbr_fd.c ft_substr.c ft_strjoin.c\
                ft_split.c

OBJ = $(FUNC:.c=.o)

BONUS   = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
                ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
                ft_lstmap.c

OBJ_BONUS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) libft.h
	@echo "linking $(NAME)"
	@ar $(FLAGLIB) $(NAME) $(OBJ)
	@ranlib $(NAME)

bonus: $(OBJ_BONUS) $(NAME)
	@echo "linking bonus"
	@ar $(FLAGLIB) $(NAME) $(OBJ_BONUS)
	@ranlib $(NAME)

test: bonus $(TEST)
	@echo "building test harness"
	@$(CC) $(CFLAGS) -I . $(TEST) $(NAME) -o $(TEST_BIN)
	@echo "running test harness"
	@./$(TEST_BIN)

.c.o:
	@echo "Compiling $(<)"
	@$(CC) $(CFLAGS) -I . -c $< -o $@

clean:
	@echo "cleaning"
	@$(RM) $(OBJ) $(OBJ_BONUS)
	@$(RM) $(TEST_BIN)

fclean: clean
	@echo "Cleaning headers"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean bonus test