#include "_atoi_base.h"

int	atoi_base_34(void)
{
	char	*str = "jhuhisdj45";
	int	exp = atoi_base_ref(str, BASE_DEC);
	int	got = ft_atoi_base(str, BASE_DEC);

	if (exp == got)
		return (0);
	else
		return (-1);
}
