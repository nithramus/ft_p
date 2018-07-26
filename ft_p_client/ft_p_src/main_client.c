#include "../ft_p.h"

int create_client(char *addr, int port)
{
    int sock;
    struct protoent     *proto;
    struct sockaddr_in  sin;

    proto = getprotobyname("tcp");
    sock = socket(AF_INET, SOCK_STREAM, proto->p_proto);
    if (sock == -1)
    {
        ft_putendl("exit");
        exit_error(2);
    }
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
    sin.sin_addr.s_addr = inet_addr(addr);
    if (connect(sock, (struct sockaddr*)&sin, sizeof(sin)) == -1)
    {
        ft_putendl("connect problem");
        exit_error(3);
    }
    // listen(sock, 42);
    return (sock);
}

int main(int argc, char **argv)
{
    int     sock;
    char    command[4096];
    int r;
    int con;

    con = 0;
    if (argc < 3)
        exit_error(1);
    sock = create_client(argv[1], atoi(argv[2]));
    ft_putstr("$> ");
    // get_next_line
    while ((r = read(0, command, 4095)) != 0)
    {
        command[r - 1] = '\0';
        con = request(command, sock);
        if (con == -2)
        {
            close(sock);
            return (0);
        }
        ft_putstr("$> ");
    }
    close(sock);
    return (0);
}