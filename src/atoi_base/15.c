#include "_atoi_base.h"

int	atoi_base_15(void)
{
	char	*str = "0101010101";
	int		exp = atoi_base_ref(str, BASE_BIN);
	int		got = ft_atoi_base(str, BASE_BIN);

	if (exp == got)
		return (0);
	else
		return (-1);
}
