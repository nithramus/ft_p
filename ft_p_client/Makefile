# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bandre <bandre@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/18 12:13:38 by nithramir         #+#    #+#              #
#    Updated: 2018/11/15 22:18:11 by bandre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client

SRC_PATH = ft_p_src


OBJ_PATH = ft_p_obj

H_FILES= ft_p.h

SRC = main_client.o\
	  exit_error.o\
	  request.o\
	  upload.o\
	  get_filename.o\
	  cd.o\
	  download.o\
	  ls.o\
	  pwd.o\

CC = gcc -g -I.

FLAG = -Wall -Wextra -O -fsanitize=address -Werror

LIB = libft/libftprintf.a libft_chained_list/libft_chained_list.a

SRC_O = $(addprefix $(OBJ_PATH)/,$(SRC))


all: EXEC $(NAME)

$(NAME): $(SRC_O)
	$(CC) $(FLAG) -o $(NAME) $(SRC_O) $(LIB)

$(OBJ_PATH)/%.o:$(SRC_PATH)/%.c
	$(CC) $(FLAG) -c $< -o $@ $(FLAG)

EXEC:
	make -C libft/
	make -C libft_chained_list/

clean:
	rm -f $(addprefix $(OBJ_PATH)/,$(SRC))
	make -C libft clean
	make -C libft_chained_list clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean
	make -C libft_chained_list fclean


re: fclean all

flag: $(SRC)
	$(CC) $(NAME) $(LIB) -o $(NAME)

do: all

.PHONY: $(NAME) all %.o clean fclean re flag EXEC