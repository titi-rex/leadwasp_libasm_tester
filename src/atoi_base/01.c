#include "_atoi_base.h"

int	atoi_base_01(void)
{
	char	*str = "0101";
	int		exp = atoi_base_ref(str, BAD_BASE_SPACE1);
	int		got = ft_atoi_base(str, BAD_BASE_SPACE1);

	if (exp == got)
		return (0);
	else
		return (-1);
}
