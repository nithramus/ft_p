# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bandre <bandre@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/09 17:23:26 by bandre            #+#    #+#              #
#    Updated: 2018/11/13 16:30:34 by bandre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: make_server make_client

make_server:
	make -C ft_p_server
	cp ft_p_server/server test_server/

make_client:
	make -C ft_p_client
	cp ft_p_client/client test_client/

clean:
	make -C ft_p_client clean
	make -C ft_p_server clean
fclean:
	make -C ft_p_client fclean
	rm -f client
	make -C ft_p_server fclean
	rm -f server
re: fclean all