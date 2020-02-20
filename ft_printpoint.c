/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpoint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:42:07 by paboutel          #+#    #+#             */
/*   Updated: 2020/02/20 17:48:37 by paboutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putstrpoint(char *str, int *tab)
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

char	ft_extpoint(int d, char c)
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

int		ft_hexlenpoint(long int n, int *tab)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		i++;
		if (tab[3] == 1 && tab[5] == 0)
			i--;
	}
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int		ft_point(unsigned long int t, char c, int *tab)
{
	unsigned long int	nbr;
	int					d;
	char				*str;
	int					pointlen;

	d = -1;
	pointlen = ft_hexlenpoint(t, tab);
	if (!(str = malloc(sizeof(char) * (pointlen + 1))))
		return (0);
	if (t == 0)
		str[0] = '0';
	while (t > 0)
	{
		nbr = t % 16;
		t = t / 16;
		if (nbr > 9)
			str[++d] = ft_extpoint(nbr % 10, c);
		else
			str[++d] = nbr + '0';
	}
	str[pointlen] = '\0';
	ft_putstrpoint(str, tab);
	free(str);
	return (0);
}

void	ft_putpoint(char c, int i, int *tab)
{
	while (i > 0)
	{
		write(1, &c, 1);
		tab[7]++;
		i--;
	}
}

void	ft_put_esppoint(unsigned long int nb, int *tab, char c)
{
	int		i;

	i = ft_hexlenpoint(nb, tab);
	tab[4] = tab[4] - i - 2;
	if (tab[0] == 0)
	{
		ft_putpoint(' ', tab[4], tab);
		write(1, "0x", 2);
		tab[7] = tab[7] + 2;
		ft_point(nb, c, tab);
	}
	if (tab[0] == 1)
	{
		write(1, "0x", 2);
		tab[7] = tab[7] + 2;
		ft_point(nb, c, tab);
		ft_putpoint(' ', tab[4], tab);
	}
}

int		ft_put_0point(unsigned long int nb, int n, char c, int *tab)
{
	int		i;

	i = ft_hexlenpoint(nb, tab);
	if (nb == 0 && n == 0)
		return (0);
	if (nb < 0)
	{
		write(1, "-", 1);
		tab[7]++;
		nb = -nb;
	}
	n = n - i;
	write(1, "0x", 2);
	tab[7] = tab[7] + 2;
	ft_putpoint('0', n, tab);
	ft_point(nb, c, tab);
	return (0);
}

int		ft_preci2point(unsigned long int nb, int *tab, char c)
{
	if (tab[5] > 0)
		tab[4] = tab[4] - tab[5];
	if (nb < 0)
		tab[4]--;
	tab[4] = tab[4] - 2;
	if (nb == 0 && tab[5] == 0)
	{
		ft_putpoint(' ', tab[4], tab);
		return (0);
	}
	if (tab[0] == 0)
		ft_putpoint(' ', tab[4], tab);
	if (nb < 0)
	{
		write(1, "-", 1);
		tab[7]++;
		nb = -nb;
	}
	write(1, "0x", 2);
	tab[7] = tab[7] + 2;
	ft_putpoint('0', tab[5], tab);
	ft_point(nb, c, tab);
	if (tab[0] == 1)
		ft_putpoint(' ', tab[4], tab);
	return (0);
}

int		ft_precipoint(unsigned long int nb, int *tab, char c)
{
	int	i;

	i = ft_hexlenpoint(nb, tab);
	tab[4] = tab[4] - i;
	tab[5] = tab[5] - i;
	if (tab[4] <= tab[5])
	{
		write(1, "0x", 2);
		tab[7] = tab[7] + 2;
		ft_putpoint('0', tab[5], tab);
		ft_point(nb, c, tab);
	}
	else
		ft_preci2point(nb, tab, c);
	return (0);
}

void	ft_printpoint(int tab[8], unsigned long int nb, char c)
{
	if (tab[2] == 0)
	{
		if (tab[3] == 0)
		{
			write(1, "0x", 2);
			tab[7] = tab[7] + 2;
			ft_point(nb, c, tab);
		}
		else
			ft_put_0point(nb, tab[5], c, tab);
	}
	else
	{
		if (tab[3] == 0 && tab[1] == 0)
			ft_put_esppoint(nb, tab, c);
		if (tab[3] == 0 && tab[1] == 1)
			ft_put_0point(nb, tab[4], c, tab);
		if (tab[3] == 1)
			ft_precipoint(nb, tab, c);
	}
}
