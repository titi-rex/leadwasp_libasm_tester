#include "_strcpy.h"

int	strcpy_09(void)
{
	const char	*src = "Aliquam in tempus mi. Aenu mauris arcu, tempor porttitor blandit eget, commodo fringilla nulla. Aliquam pharetra augue eget eros volutpat mattis. Nunc quis mauris pulvinar, aliquet metus id, aliquet turpis. Morbi dolor risus, ullamcorper nec ultrices eu, maximus sit amet felis. Fusce placerat eros eu efficitur dapibus. Morbi lacinia viverra vehicula. Pellentesque sit amet arcu a augue pulvinar condimentum. Phasellus eleifend lacinia elit, quis ultrices lacus eleifend vitae. Suspendisse potenti. Suspendisse leo augue, consectetur vitae eleifend et, aliquam sit amet nunc. Nunc vel sollicitudin lorem. Aenean mi ligula, laoreet in molestie quis, vehicula eget erat. Integer vel libero dapibus, venenatis nisi in, laoreet urna. Vivamus facilisis turpis congue mi maximus porttitor. Integer maximus posuere purus, cursus ullamcorper nibh molestie nec. Curabitur id ultricies felis, nec placerat arcu. Duis non interdum sem. In tincidunt eget massa in euismod. Morbi ante lacus, finibus et risus vel, ornare nullam. ";
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