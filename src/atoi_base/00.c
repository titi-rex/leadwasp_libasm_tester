#include "libunit.h"
#include "_atoi_base.h"

int	atoi_base_00_launcher(void)
{
	t_test	*test;

	test = NULL;
	test_loader(&test, "bad base: space1", &atoi_base_01, 0);
	test_loader(&test, "bad base: space2", &atoi_base_02, 0);
	test_loader(&test, "bad base: space3", &atoi_base_03, 0);
	test_loader(&test, "bad base: sign1", &atoi_base_04, 0);
	test_loader(&test, "bad base: sign2", &atoi_base_05, 0);
	test_loader(&test, "bad base: sign3", &atoi_base_06, 0);
	test_loader(&test, "bad base: sign4", &atoi_base_07, 0);
	test_loader(&test, "bad base: sign5", &atoi_base_08, 0);
	test_loader(&test, "bad base: sign6", &atoi_base_09, 0);
	test_loader(&test, "bad base: non-printable1", &atoi_base_10, 0);
	test_loader(&test, "bad base: non-printable2", &atoi_base_11, 0);
	test_loader(&test, "bad base: duplicate1", &atoi_base_12, 0);
	test_loader(&test, "bad base: duplicate2", &atoi_base_13, 0);
	test_loader(&test, "base binary: 0", &atoi_base_14, 0);
	test_loader(&test, "base binary: 365", &atoi_base_15, 0);
	test_loader(&test, "base binary: -5", &atoi_base_16, 0);
	test_loader(&test, "base octal: 0", &atoi_base_17, 0);
	test_loader(&test, "base octal: 21271", &atoi_base_18, 0);
	test_loader(&test, "base octal: -1727", &atoi_base_19, 0);
	test_loader(&test, "base decimal: 684512", &atoi_base_20, 0);
	test_loader(&test, "base decimal: 451", &atoi_base_21, 0);
	test_loader(&test, "base decimal: -2741547", &atoi_base_22, 0);
	test_loader(&test, "base hexadecimal: 11533889", &atoi_base_23, 0);
	test_loader(&test, "base hexadecimal: -9503", &atoi_base_24, 0);
	test_loader(&test, "base hexadecimal: 31", &atoi_base_25, 0);
	test_loader(&test, "base 'poneyvif': 5130", &atoi_base_26, 0);
	test_loader(&test, "base 'poneyvif': -125", &atoi_base_27, 0);
	test_loader(&test, "base 'poneyvif': 342391", &atoi_base_28, 0);
	test_loader(&test, "multiple sign 1: +", &atoi_base_29, 0);
	test_loader(&test, "multiple sign 2: +", &atoi_base_30, 0);
	test_loader(&test, "multiple sign 3: -", &atoi_base_31, 0);
	test_loader(&test, "INT32_MAX", &atoi_base_32, 0);
	test_loader(&test, "INT32_MIN", &atoi_base_33, 0);
	test_loader(&test, "garbage first", &atoi_base_34, 0);
	test_loader(&test, "garbage last 1", &atoi_base_35, 0);
	test_loader(&test, "garbage last 2", &atoi_base_36, 0);
	test_loader(&test, "leading space 1", &atoi_base_37, 0);
	test_loader(&test, "leading space 2", &atoi_base_38, 0);
	test_loader(&test, "leading space 3", &atoi_base_39, 0);
	return (test_launcher(&test, "ATOI_BASE"));
}
