#include "test.h"

void _strdup_wrapper(const char * string)
{
    char *  exp = strdup(string);
    char *  got = ft_strdup(string);

    if (got != NULL && exp != NULL)
    {
        check((strcmp(got, exp) == 0));
        size_t  ge = malloc_usable_size(exp);
        size_t  go = malloc_usable_size(got);
        // printf("ms.");
        check(ge == go);
        // printf("malloc size : exp %ld, got %ld,\tlen str :% ld, size chat %ld, mult :%ld\n", ge, go, strlen(string), sizeof(char), strlen(string) * sizeof(char));
    }
    else
        printf("nulll");

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

int main(void)
{
    signal(SIGSEGV, sigsegv_handler);
    strdup_tester();
}
