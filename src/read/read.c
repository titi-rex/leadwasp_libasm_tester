#include "test.h"

int g_verbose   = 0;


void _read_wrapper(char * pathname, size_t len)
{
    static int  i = 0;
    printf("%d.", i++);

    char exp[len + 1];
    char got[len + 1];

    exp[len] = 0;
    got[len] = 0;

    int errno_exp = 0;
    int errno_got = 0;

    int fd = open(pathname, O_RDONLY);
    ssize_t l_exp = read(fd, exp, len);
    if (l_exp == -1)
    {
        errno_exp = errno;
        errno = 0;
    }
    close(fd);

    fd = open(pathname, O_RDONLY);
    ssize_t l_got = ft_read(fd, got, len);
    if (l_got == -1)
        errno_got = errno;
    close(fd);

    check("ret:", l_exp == l_got);
    if ((l_exp == -1) || (l_got == -1))
        check("errno:", errno_exp == errno_got);
    else
        check("data:", strcmp(exp, got) == 0);
}

void    read_tester(void)
{
    printf("read:\t");
    _read_wrapper("Makefile", 10);
    _read_wrapper("Makefile", -10);
    _read_wrapper("Makefile", 51);
    _read_wrapper("Makefile", 10151);
    _read_wrapper("Makefile", 0);
    printf("\n");
}

int main(int ac, char** arg)
{
    (void)arg;
    if (ac != 1 )
        g_verbose = 1;
    signal(SIGSEGV, sigsegv_handler);
    read_tester();
}
