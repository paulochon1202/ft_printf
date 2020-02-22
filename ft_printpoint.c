/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpoint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:42:07 by paboutel          #+#    #+#             */
/*   Updated: 2020/02/22 16:30:21 by paboutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
