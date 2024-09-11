#include "libunit.h"

static int	_all_tests(t_mifunc *ftab, size_t len)
{
	int		ret;
	size_t	i;

	i = 0;
	ret = 0;
	while (i < len)
	{
		ret += ftab[i].f_ptr();
		++i;
	}
	if (ret != 0)
		ret = -1;
	return (ret);
}

static int	_specific_tests(t_mifunc *ftab, size_t len, int ac, char **argv)
{
	int		ret;
	int		arg_idx;
	size_t	i;

	ret = 0;
	arg_idx = 0;
	while (++arg_idx < ac)
	{
		i = 0;
		while (i < len)
		{
			if (strcmp(argv[arg_idx], ftab[i].name) == 0)
				ret += ftab[i].f_ptr();
			++i;
		}
	}
	if (ret != 0)
		ret = -1;
	return (ret);
}

int	test_start(t_mifunc *ftab, size_t len, int ac, char **argv)
{
	if (ac == 1)
		return (_all_tests(ftab, len));
	else
		return (_specific_tests(ftab, len, ac, argv));
}
