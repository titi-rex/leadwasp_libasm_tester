#ifndef __READ_H_
# define __READ_H_
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>
# include "libasm.h"

# define BASE_BIN "01"
# define BASE_DEC "0123456789"
# define BASE_OCTA "01234567"
# define BASE_HEXA "0123456789abcdef"

# define BASE_OCTA_STR "poneyvif"
# define BASE_7 "suix54"
# define BASE_5 "142sa"

# define BAD_BASE_SPACE1 " 01245"
# define BAD_BASE_SPACE2 "012 45"
# define BAD_BASE_SPACE3 "01245  "
# define BAD_BASE_SIGN1 "-012456789"
# define BAD_BASE_SIGN2 "+012456789"
# define BAD_BASE_SIGN3 "01245+6789"
# define BAD_BASE_SIGN4 "0124567-89"
# define BAD_BASE_SIGN5 "012456789+-"
# define BAD_BASE_SIGN6 "--012456789"
# define BAD_BASE_NON_PRINT1 {'0', '1', 8, 0}
# define BAD_BASE_NON_PRINT2 {'0', '1', 14, 0}
# define BAD_BASE_DUP1 "01234567890"
# define BAD_BASE_DUP2 "012223456789"

// check base
int	atoi_base_01(void);
int	atoi_base_02(void);
int	atoi_base_03(void);
int	atoi_base_04(void);
int	atoi_base_05(void);
int	atoi_base_06(void);
int	atoi_base_07(void);
int	atoi_base_08(void);
int	atoi_base_09(void);
int	atoi_base_10(void);
int	atoi_base_11(void);
int	atoi_base_12(void);
int	atoi_base_13(void);

// binary
int	atoi_base_14(void);
int	atoi_base_15(void);
int	atoi_base_16(void);

// octal
int	atoi_base_17(void);
int	atoi_base_18(void);
int	atoi_base_19(void);

// decimal
int	atoi_base_20(void);
int	atoi_base_21(void);
int	atoi_base_22(void);

// hexadecimal
int	atoi_base_23(void);
int	atoi_base_24(void);
int	atoi_base_25(void);

// octa str
int	atoi_base_26(void);
int	atoi_base_27(void);
int	atoi_base_28(void);

// multi sign
int	atoi_base_29(void);
int	atoi_base_30(void);
int	atoi_base_31(void);

// int32 max/min
int	atoi_base_32(void);
int	atoi_base_33(void);

// garbage
int	atoi_base_34(void);
int	atoi_base_35(void);
int	atoi_base_36(void);

// space
int	atoi_base_37(void);
int	atoi_base_38(void);
int	atoi_base_39(void);

int	atoi_base_ref(char *str, char *base);

#endif
