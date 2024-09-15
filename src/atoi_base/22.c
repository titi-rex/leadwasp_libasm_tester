#include "_atoi_base.h"

int	atoi_base_22(void)
{
	char	*str = "-2741547";
	int		exp = atoi_base_ref(str, BASE_DEC);
	int		got = ft_atoi_base(str, BASE_DEC);

	if (exp == got)
		return (0);
	else
		return (-1);
}
