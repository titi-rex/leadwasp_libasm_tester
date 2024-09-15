#include "_atoi_base.h"

int	atoi_base_11(void)
{
	char	*str = "0101";
	char	base[] = BAD_BASE_NON_PRINT2;
	int		exp = atoi_base_ref(str, base);
	int		got = ft_atoi_base(str, base);

	if (exp == got)
		return (0);
	else
		return (-1);
}