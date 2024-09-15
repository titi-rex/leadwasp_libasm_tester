#include "_strcpy.h"

int	strcpy_08(void)
{
	const char	*src = "Nulla scelerisque lectus leo, vitae cursus ipsum interdum eget. Nam eget viverra leo. Duis id facilisis quam, id viverra turpis. Phasellus sodales sem vitae est feugiat gravida. Fusce in cursus diam. Proin non varius eros, ut consequat elit. Pellentesque cras amet.";
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
	ft_strcpy(dst1, src);
	strcpy(dst2, src);

	int ret = strncmp(dst1, dst2, len + 1);

	free(dst1);
	free(dst2);

	if (ret == 0)
		return (0);
	else
		return (-1);
}