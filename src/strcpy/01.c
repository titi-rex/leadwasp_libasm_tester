#include "_strcpy.h"

int	strcpy_01(void)
{
	const char	*src = "";
	size_t		len = strlen(src);
	char		*dst1 = malloc(sizeof(char) * (len + 1));
	char		*dst2 = malloc(sizeof(char) * (len + 1));

	if (dst1 == NULL || dst2 == NULL)
	{
		if (dst1)
			free(dst1);
		if (dst2)
			free(dst2);
		return (1);
	}

	int	got = (dst1 == ft_strcpy(dst1, src));
	int	exp = (dst2 == strcpy(dst2, src));

	free(dst1);
	free(dst2);
	if (got == exp)
		return (0);
	else
		return (-1);
}
