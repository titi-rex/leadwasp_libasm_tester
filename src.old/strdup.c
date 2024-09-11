#include "test.h"

int g_verbose   = 0;

void _strdup_wrapper(const char * string)
{
    static int  i = 0;
    printf("%d.", i++);

    char *  exp = strdup(string);
    char *  got = ft_strdup(string);

    if (got != NULL && exp != NULL)
    {
        check("data", (strcmp(got, exp) == 0));
        size_t  ge = malloc_usable_size(exp);
        size_t  go = malloc_usable_size(got);
        check("msize", ge == go);
    }
    else
        printf("null");

    if (got)
        free(got);
    if (exp)
        free(exp);
}

void    strdup_tester(void)
{
    printf("strdup:\t");
    _strdup_wrapper("hehe");
    _strdup_wrapper("hehslkfj sljfojes;ofh sf6s84efs4efsf jse9w73 os;l9es9rf9fru3u8sl38ursl83rus9w3l8ry sl3yr7sylwsi3rysiyr 3i7yslry3iyurslie");
    _strdup_wrapper("");
    _strdup_wrapper("asd;a poadjw kkwd\n\n");
    printf("\n");
}

int main(int ac, char** arg)
{
    (void)arg;
    if (ac != 1 )
        g_verbose = 1;
    signal(SIGSEGV, sigsegv_handler);
    strdup_tester();
}
