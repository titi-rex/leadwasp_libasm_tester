#include "test.h"

int g_verbose   = 0;

void _strcpy_wrapper(const char * string)
{
    static int  i = 0;
    printf("%d.", i++);

    size_t  len = strlen(string);
    char *  dst1 = malloc(sizeof(char) * (len + 1));
    char *  dst2 = malloc(sizeof(char) * (len + 1));

    if (dst1 == NULL || dst2 == NULL)
       fatal("malloc failed");
    check("ret:", (dst1 == ft_strcpy(dst1, string)) == (dst2 == strcpy(dst2, string)));
    check("data:", strcmp(dst1, dst2) == 0);
    if (dst1)
        free(dst1);
    if (dst2)
        free(dst2);
}

void    strcpy_tester(void)
{
    printf("strcpy:\t");
    _strcpy_wrapper("hehe");
    _strcpy_wrapper("hehslkfj sljfojes;ofh sf6s84efs4efsf jse9w73 os;l9es9rf9fru3u8sl38ursl83rus9w3l8ry sl3yr7sylwsi3rysiyr 3i7yslry3iyurslie");
    _strcpy_wrapper("");
    printf("\n");
}

int main(int ac, char** arg)
{
    (void)arg;
    if (ac != 1 )
        g_verbose = 1;
    signal(SIGSEGV, sigsegv_handler);
    strcpy_tester();
}

