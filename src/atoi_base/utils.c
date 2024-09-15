#include "_atoi_base.h"

static int	_check_base(char *base)
{
	int		len;
	int		i;

	len = 0;
	while (base[len])
	{
		i = len + 1;
		if (base[len] == 45 || base[len] == 43 || base[len] <= 32)
			return (1);
		while (base[i] != base[len] && base[i])
			i++;
		if (base[i] != 0)
			return (1);
		len++;
	}
	return (len);
}

static int	_extract_nbr(char *str, char *base, int len)
{
	int		res;
	int		i;

	res = 0;
	i = 0;
	while (*str != base[i] && base[i])
		i++;
	while (*str == base[i] && base[i])
	{
		res = res * len + i;
		str++;
		i = 0;
		while (*str != base[i] && base[i])
			i++;
	}
	return (res);
}

int	atoi_base_ref(char *str, char *base)
{
	int		len_base;
	int		signe;
	int		nb;

	signe = 1;
	nb = 0;
	len_base = _check_base(base);
	if (len_base <= 1)
		return (0);
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	while (*str == 45 || *str == 43)
	{
		if (*str == 45)
			signe *= -1;
		str++;
	}
	nb = _extract_nbr(str, base, len_base);
	return (nb * signe);
}
