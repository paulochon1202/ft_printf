/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:05:10 by paboutel          #+#    #+#             */
/*   Updated: 2020/02/22 16:28:29 by paboutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_esp(long int nb, int n, int m, int *tab)
{
	long int	save;
	int			i;

	i = 0;
	save = nb;
	if (nb < 0)
		save = -save;
	while (save > 0)
	{
		i++;
		save = save / 10;
	}
	if (nb == 0 || nb < 0)
		i++;
	n = n - i;
	if (m == 0)
	{
		ft_put(' ', n, tab);
		ft_putnbr_fd(nb, 1, tab);
	}
	if (m == 1)
	{
		ft_putnbr_fd(nb, 1, tab);
		ft_put(' ', n, tab);
	}
}

int		ft_put_0(long int nb, int n, int *tab)
{
	long int	save;
	int			i;

	i = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		tab[7]++;
		nb = -nb;
		i++;
	}
	save = nb;
	if (nb == 0)
		i++;
	while (save > 0)
	{
		i++;
		save = save / 10;
	}
	if (nb == 0 && n == 0)
		return (0);
	n = n - i;
	ft_put('0', n, tab);
	ft_putnbr_fd(nb, 1, tab);
	return (0);
}

int		ft_preci2(long int nb, int *tab)
{
	if (tab[5] > 0)
		tab[4] = tab[4] - tab[5];
	if (nb < 0)
		tab[4]--;
	if (nb == 0 && tab[5] == 0)
	{
		ft_put(' ', tab[4], tab);
		return (0);
	}
	if (tab[0] == 0)
		ft_put(' ', tab[4], tab);
	if (nb < 0)
	{
		write(1, "-", 1);
		tab[7]++;
		nb = -nb;
	}
	ft_put('0', tab[5], tab);
	ft_putnbr_fd(nb, 1, tab);
	if (tab[0] == 1)
		ft_put(' ', tab[4], tab);
	return (0);
}

int		ft_preci(long int nb, int *tab)
{
	long int	save;

	save = nb;
	if (save < 0)
		save = -save;
	while (save > 0)
	{
		tab[4]--;
		tab[5]--;
		save = save / 10;
	}
	if (tab[4] <= tab[5])
	{
		write(1, "tu\n", 3);
		ft_putnbr_fd(nb, 1, tab);
	}
	else
		ft_preci2(nb, tab);
	return (0);
}

void	ft_printnbr(int tab[8], int nb)
{
	if (nb == 0 && tab[5] != 0)
		tab[5]--;
	if (tab[2] == 0)
	{
		if (tab[3] == 0)
			ft_putnbr_fd(nb, 1, tab);
		else
			ft_put_0(nb, tab[5], tab);
	}
	else
	{
		if (tab[3] == 0 && tab[1] == 0)
			ft_put_esp(nb, tab[4], tab[0], tab);
		if (tab[3] == 0 && tab[1] == 1)
			ft_put_0(nb, tab[4], tab);
		if (tab[3] == 1)
			ft_preci(nb, tab);
	}
}
