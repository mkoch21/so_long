# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkoch <mkoch@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/03 16:09:07 by mkoch             #+#    #+#              #
#    Updated: 2022/03/02 11:33:09 by mkoch            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftsolong.a
NAME_B = libftsolongbonus.a

SRCS =  get_next_line.c get_next_line_utils.c so_long_utils.c move.c map.c
SL = so_long.c
SRCS_B = get_next_line.c get_next_line_utils.c so_long_utils_bonus.c move_bonus.c map_bonus.c
SL_B = so_long_bonus.c

HEADER = so_long.h
HEADER_B = so_long_bonus.h

LIBFT = libft/libft.a

OBJ = $(SRCS:%.c=%.o)
OBJ_B = $(SRCS_B:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror
SLFLAGS = -lmlx -framework OpenGL -framework AppKit
RM = rm -f

all: $(NAME) so_long

$(NAME): $(OBJ) $(SL)
	$(MAKE) -C ./libft
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $?

%.o : %.c $(HEADER) $(SL) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

so_long: $(SL) Makefile 
	$(CC) $(CFLAGS) so_long.c -c
	$(CC) $(CFLAGS) $(SLFLAGS) $(NAME) so_long.o -o so_long

bonus: $(NAME_B) so_long_bonus  $(HEADER_B)

$(NAME_B): $(OBJ_B) $(SL_B)
	$(MAKE) -C ./libft
	cp $(LIBFT) $(NAME_B)
	ar rcs $(NAME_B) $?
	
%.o : %.c $(HEADER_B) $(SL_B) Makefile
	$(CC) $(CFLAGS) -c $< -o $@
	
so_long_bonus: $(SL_B) Makefile
	$(CC) $(CFLAGS) so_long_bonus.c -c
	$(CC) $(CFLAGS) $(SLFLAGS) $(NAME_B) so_long_bonus.o -o so_long_bonus

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJ) $(OBJ_B) so_long.o so_long_bonus.o

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME) $(NAME_B) so_long so_long_bonus

re: fclean all

.PHONY: all clean fclean re bonus