# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: janeway <janeway@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2021/07/04 14:52:18 by janeway       #+#    #+#                  #
#    Updated: 2021/07/04 15:08:39 by janeway       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
OBJS_FILES =	ft_bzero.c\
				ft_calloc.c\
				ft_isdigit.c\
				ft_putstr_fd.c\
				ft_strcmp.c\
				ft_strjoin.c\
				ft_strlen.c

HEADER_FILES = libft.h
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS_FILES)
	ar -rcs $@ $^

%.o: %.c $(HEADER_FILES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_FILES)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
