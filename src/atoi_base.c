#include "test.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:31:10 by tlegrand          #+#    #+#             */
/*   Updated: 2022/07/28 09:15:09 by tlegrand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	_check_base(char *base)
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

int	_extract_nbr(char *str, char *base, int len)
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

int	atoi_base(char *str, char *base)
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

void    atoi_base_wrapper(char* str, char* base)
{
    int     exp = atoi_base(str, base);
    int     got = ft_atoi_base(str, base);
    check(exp == got);
    // printf("exp: %d, got %d. ", exp, got);
}

void	atoi_base_tester(void)
{
    printf("atoi_base:\t");
    atoi_base_wrapper("1", "001");
    atoi_base_wrapper("1", "011");
	char s8[] = {'0', '1', 8, 0}; 
    char s14[] = {'0', '1', 14, 0}; 
    char * gap = (char*)"0123450";

    atoi_base_wrapper("1", s8);
    atoi_base_wrapper("1", s14);
    atoi_base_wrapper("1", gap);

    atoi_base_wrapper("+89", "0123456789");
    atoi_base_wrapper("-1", "0123456789");
    atoi_base_wrapper("-24", "0123456789abcdef");
    atoi_base_wrapper("--1", "0123456789abcdef");
    atoi_base_wrapper("-+--1", "0123456789abcdef");

    atoi_base_wrapper("0000", "++012345679");
    atoi_base_wrapper("0000", "012+3456-7 9");
    atoi_base_wrapper("0000", "  0123+4 5679 ");
    atoi_base_wrapper("0000", "  +-0123+4 5679 ");
    atoi_base_wrapper("0000", "  5+-0123+4 5679 ");
    atoi_base_wrapper("0000", "0123456789");
    atoi_base_wrapper("010101", "01");
    atoi_base_wrapper("10000", "01");
    atoi_base_wrapper("684", "0123456789");
    atoi_base_wrapper("-89", "0123456789");
    atoi_base_wrapper("-5687421", "0123456789");
    atoi_base_wrapper("--968", "0123456789");
    atoi_base_wrapper("--++--+-+968", "0123456789");
    atoi_base_wrapper(" +-+----nope2kldj9f", "56sw");
    atoi_base_wrapper("oney", "poneyvif");
    atoi_base_wrapper("-vf", "poneyvif");
    atoi_base_wrapper("16", "0123456789abcdef");
    atoi_base_wrapper("-24", "0123456789abcdef");
    printf("\n");
}

int main(void)
{
    signal(SIGSEGV, sigsegv_handler);
    atoi_base_tester();
}
