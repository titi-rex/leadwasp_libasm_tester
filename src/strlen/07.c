#include "_strlen.h"

int	strlen_07(void)
{
	const char	*str = "Ut pharetra vel nisl et aliquet. Phasellus nec libero dapibus, fringilla velit vitae, ultrices ligula. Aliquam tincidunt metus ac elementum laoreet. Pellentesque laoreet leo sit amet nunc sagittis, nec dictum nunc tempus. Aenean eu augue eget nunc hendrerit maximus vitae eget nisl. Aliquam vitae bibendum mi. Pellentesque ut scelerisque eros, sit amet turpis duis.";
	if (ft_strlen(str) == strlen(str))
		return (0);
	else
		return (-1);
}
