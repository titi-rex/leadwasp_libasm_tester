#include "_atoi_base.h"

int	atoi_base_18(void)
{
	char	*str = "5142";
	int		exp = atoi_base_ref(str, BASE_OCTA);
	int		got = ft_atoi_base(str, BASE_OCTA);

	if (exp == got)
		return (0);
	else
		return (-1);
}