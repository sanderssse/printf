NAME     = libftprintf.a
CC       = cc

CFLAGS   = -Wall -Wextra -Werror

SRC      = printf.c printf2.c printf3.c ft_putnbr.c 
OBJ      = $(SRC:.c=.o)

all: $(NAME)

${NAME}: $(OBJ) 
	ar -rc $@ $(OBJ)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean fclean

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all