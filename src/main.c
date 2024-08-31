#include "test.h"

sig_atomic_t    g_test = I_START;

int main(void)
{
    signal(SIGSEGV, sigsegv_handler);
    strlen_tester();
    strcpy_tester();
    strcmp_tester();
    strdup_tester();
    write_tester();
    read_tester();
    // bonus
    atoi_base_tester();
    list_push_front_tester();
    list_size_tester();
    list_sort_tester();
    list_remove_if_tester();
}




/*

errno check
malloc check
sigsev signal handler -> exit


*/