# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: janeway <janeway@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2021/06/20 17:01:17 by janeway       #+#    #+#                  #
#    Updated: 2021/07/17 18:10:46 by janeway       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

PUSH		=	push_swap
CHECKER		=	checker
H_FILES		=	src/push_swap.h\
				libft
CFLAGS		=	-Wall -Werror -Wextra -g -fsanitize=address

SRC			=	push_swap.c\
				presort.c\
				sort_upto_five.c\
				sort_more_than_five.c\
				sort_more_than_five_utils.c
SRC_PATH	=	src/
SRC_OBJ		=	$(SRC:%.c=$(SRC_PATH)%.o)

UTILS		=	set_up_data.c\
				check_data.c\
				atoi_modified.c\
				utils_lists.c\
				utils_sort.c\
				utils_sort2.c\
				exit_and_free.c
UTILS_PATH	=	utils/
UTILS_OBJ	=	$(UTILS:%.c=$(UTILS_PATH)%.o)

MOVES		=	push.c\
				swap.c\
				rotate.c\
				reverse_rotate.c
MOVES_PATH 	=	moves/
MOVES_OBJ	=	$(MOVES:%.c=$(MOVES_PATH)%.o)

LIBFT		=	ft_isdigit.c\
				ft_putstr_fd.c\
				ft_calloc.c\
				ft_bzero.c\
				ft_strjoin.c\
				ft_strlen.c\
				ft_strcmp.c
LIBFT_PATH	=	libft/
LIBFT_OBJ	=	$(LIBFT:%.c=$(LIBFT_PATH)%.o)

GNL			=	get_next_line.c\
				get_next_line_utils.c
GNL_PATH	=	get_next_line/
GNL_OBJ		=	$(GNL:%.c=$(GNL_PATH)%.o)

TESTER			=	checker.c
TESTER_PATH		=	tester/
TESTER_OBJ		=	$(TESTER:%.c=$(TESTER_PATH)%.o)

PUSH_FILES		=	$(SRC_OBJ) $(UTILS_OBJ) $(MOVES_OBJ) $(LIBFT_OBJ)
TESTER_FILES	=	$(TESTER_OBJ) $(UTILS_OBJ) $(MOVES_OBJ) $(LIBFT_OBJ) $(GNL_OBJ)

all: $(PUSH) $(CHECKER)

$(PUSH): $(PUSH_FILES)
	$(CC) $(PUSH_FILES) $(CFLAGS) -o $@
	
$(CHECKER): $(TESTER_FILES)
	$(CC) $(TESTER_FILES) $(CFLAGS) -o $@

%.o: %.c $(HEADER_FILES)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(PUSH_FILES) $(TESTER_FILES)

fclean: clean
	$(RM) *.o $(PUSH) $(CHECKER)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
