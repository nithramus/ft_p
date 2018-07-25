rm  on_client

make -C ../ft_p_server/
mv ../ft_p_server/ft_p_server .
./ft_p_server $1
