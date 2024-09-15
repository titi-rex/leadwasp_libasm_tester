#include "_strcmp.h"

int	strcmp_08(void)
{
	const char	*s1 = "hi nice faery!";
	int exp = strcmp(s1, s1);
	int got = ft_strcmp(s1, s1);

	if ((exp == got) || (exp < 0 && got < 0) || (exp > 0 && got > 0))
		return (0);
	else
		return (-1);
}