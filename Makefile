# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: janeway <janeway@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2021/06/20 17:01:17 by janeway       #+#    #+#                  #
#    Updated: 2021/06/29 19:54:20 by janeway       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
H_FILES		=	src/push_swap.h
CFLAGS		=	-Wall -Werror -Wextra

SRC			=	push_swap.c\
				set_up_data.c\
				sort_upto_five.c\
				presort.c\
				sort_upto_hundred.c\
				sort_upto_morehundred.c
SRC_PATH	=	src/
SRC_OBJ		=	$(SRC:%.c=$(SRC_PATH)%.o)

UTILS		=	atoi_modified.c\
				utils_lists.c\
				utils_sort.c\
				exit_and_free.c
UTILS_PATH	=	utils/
UTILS_OBJ	=	$(UTILS:%.c=$(UTILS_PATH)%.o)

MOVES		=	push.c\
				swap.c\
				rotate.c\
				reverse_rotate.c
MOVES_PATH 	=	moves/
MOVES_OBJ	=	$(MOVES:%.c=$(MOVES_PATH)%.o)

LIBFT		=	ft_isdigit.c \
				ft_putstr_fd.c
LIBFT_PATH	=	libft/
LIBFT_OBJ	=	$(LIBFT:%.c=$(LIBFT_PATH)%.o)

OBJ_FILES	=	$(SRC_OBJ) $(UTILS_OBJ) $(MOVES_OBJ) $(LIBFT_OBJ)

all: $(NAME)

$(NAME): $(OBJ_FILES)
		$(CC) $(OBJ_FILES) -o $@
		make clean

%.o: %.c $(HEADER_FILES)
	$(CC) -c $(CFLAGS)  $< -o $@ -g

clean:
	$(RM) $(OBJ_FILES)

fclean: clean
	$(RM) *.o $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
