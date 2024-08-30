#include "test.h"


void _strlen_wrapper(const char * string)
{
    check(ft_strlen(string) == strlen(string));
}

void    strlen_tester(void)
{
    printf("strlen:\t");
    _strlen_wrapper("hehe");
    _strlen_wrapper("hehslkfj sljfojes;ofh sf6s84efs4efsf jse9w73 os;l9es9rf9fru3u8sl38ursl83rus9w3l8ry sl3yr7sylwsi3rysiyr 3i7yslry3iyurslie");
    _strlen_wrapper("");
    printf("\n");
}
