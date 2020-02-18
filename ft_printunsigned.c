/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 21:50:00 by paboutel          #+#    #+#             */
/*   Updated: 2020/02/18 11:23:06 by paboutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putcharunsign(char c, int fd, int *tab)
{
	write(fd, &c, 1);
	tab[7]++;
}

void	ft_putnbr_fdunsign(unsigned int nb, int fd, int *tab)
{
	if (nb >= 10)
		ft_putnbr_fdunsign(nb / 10, fd, tab);
	ft_putcharunsign('0' + nb % 10, fd, tab);
}

void	ft_putunsign(char c, int i, int *tab)
{
	while (i > 0)
	{
		write(1, &c, 1);
		tab[7]++;
		i--;
	}
}

void	ft_put_espunsign(unsigned long int nb, int n, int m, int *tab)
{
	unsigned long int	save;
	int					i;

	i = 0;
	save = nb;
	while (save > 0)
	{
		i++;
		save = save / 10;
	}
	n = n - i;
	if (m == 0)
	{
		ft_putunsign(' ', n, tab);
		ft_putnbr_fdunsign(nb, 1, tab);
	}
	if (m == 1)
	{
		ft_putnbr_fdunsign(nb, 1, tab);
		ft_putunsign(' ', n, tab);
	}
}

int		ft_put_0unsign(unsigned long int nb, int n, int *tab)
{
	unsigned long int	save;
	int					i;

	i = 0;
	save = nb;
	while (save > 0)
	{
		i++;
		save = save / 10;
	}
	if (nb == 0 && n == 0)
		return (0);
	if (nb < 0)
	{
		write(1, "-", 1);
		tab[7]++;
		nb = -nb;
	}
	n = n - i;
	ft_putunsign('0', n, tab);
	ft_putnbr_fdunsign(nb, 1, tab);
	return (0);
}

int		ft_preci2unsign(unsigned int nb, int *tab)
{
	if (tab[5] > 0)
		tab[4] = tab[4] - tab[5];
	if (tab[0] == 0)
		ft_putunsign(' ', tab[4], tab);
	if (nb == 0 && tab[5] == 0)
	{
		ft_putunsign(' ', tab[4], tab);
		return (0);
	}
	ft_putunsign('0', tab[5], tab);
	ft_putnbr_fdunsign(nb, 1, tab);
	if (tab[0] == 1)
		ft_putunsign(' ', tab[4], tab);
	return (0);
}

int		ft_preciunsign(unsigned long int nb, int *tab)
{
	unsigned long int		save;

	save = nb;
	if (nb == 0)
	{
		tab[4]--;
		tab[5]--;
	}
	while (save > 0)
	{
		tab[4]--;
		tab[5]--;
		save = save / 10;
	}
	if (tab[4] <= tab[5])
	{
		ft_putunsign('0', tab[5], tab);
		ft_putnbr_fdunsign(nb, 1, tab);
	}
	else
		ft_preci2unsign(nb, tab);
	return (0);
}

void	ft_printunsigned(int tab[8], unsigned int nb)
{
	if (tab[5] < 0)
		tab[3] = 0;
	if (tab[2] == 0)
	{
		if (tab[3] == 0)
			ft_putnbr_fdunsign(nb, 1, tab);
		else
			ft_put_0unsign(nb, tab[5], tab);
	}
	else
	{
		if (tab[3] == 0 && tab[1] == 0)
			ft_put_espunsign(nb, tab[4], tab[0], tab);
		if (tab[3] == 0 && tab[1] == 1)
			ft_put_0unsign(nb, tab[4], tab);
		if (tab[3] == 1)
			ft_preciunsign(nb, tab);
	}
}
