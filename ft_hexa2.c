/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:44:37 by paboutel          #+#    #+#             */
/*   Updated: 2020/02/25 05:17:13 by paboutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *tab)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	i--;
	while (i >= 0)
	{
		write(1, &str[i], 1);
		tab[7]++;
		i--;
	}
}

char	ft_ext(int d, char c)
{
	char	a;

	if (c == 'X')
		a = 'A';
	if (c == 'x')
		a = 'a';
	while (d > 0)
	{
		a++;
		d--;
	}
	return (a);
}

int		ft_hexlen(long int n, int *tab)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		i++;
		if (tab[3] == 1)
			i--;
	}
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int		ft_hexa(unsigned long int t, char c, int *tab)
{
	unsigned long int	nbr;
	int					d;
	char				*str;
	int					hexlen;

	d = -1;
	hexlen = ft_hexlen(t, tab);
	if (!(str = malloc(sizeof(char) * (hexlen + 1))))
		return (0);
	if (t == 0)
		str[0] = '0';
	while (t > 0)
	{
		nbr = t % 16;
		t = t / 16;
		if (nbr > 9)
			str[++d] = ft_ext(nbr % 10, c);
		else
			str[++d] = nbr + '0';
	}
	str[hexlen] = '\0';
	ft_putstr(str, tab);
	free(str);
	return (0);
}

void	ft_puthexa(char c, int i, int *tab)
{
	while (i > 0)
	{
		write(1, &c, 1);
		tab[7]++;
		i--;
	}
}
