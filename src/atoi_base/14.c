#include "_atoi_base.h"

int	atoi_base_14(void)
{
	char	*str = "0";
	int		exp = atoi_base_ref(str, BASE_BIN);
	int		got = ft_atoi_base(str, BASE_BIN);

	if (exp == got)
		return (0);
	else
		return (-1);
}