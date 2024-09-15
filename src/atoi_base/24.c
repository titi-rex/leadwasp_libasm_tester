#include "_atoi_base.h"

int	atoi_base_24(void)
{
	char	*str = "-251f";
	int	exp = atoi_base_ref(str, BASE_HEXA);
	int	got = ft_atoi_base(str, BASE_HEXA);

	if (exp == got)
		return (0);
	else
		return (-1);
}
