#include "test.h"

void _read_wrapper(char * pathname, size_t len)
{
    char exp[len + 1];
    char got[len + 1];

    exp[len] = 0;
    // exp[0] = 0;
    got[len] = 0;
    // got[0] = 0;

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

    check(l_exp == l_got);
    if ((l_exp == -1) || (l_got == -1))
        check(errno_exp == errno_got);
    else
        check(strcmp(exp, got) == 0);
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

int main(void)
{
    signal(SIGSEGV, sigsegv_handler);
    read_tester();
}
