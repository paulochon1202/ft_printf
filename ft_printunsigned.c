/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 21:50:00 by paboutel          #+#    #+#             */
/*   Updated: 2020/02/14 15:47:38 by paboutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putcharunsign(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_fdunsign(unsigned int nb, int fd)
{
	if (nb >= 10)
		ft_putnbr_fdunsign(nb / 10, fd);
	ft_putcharunsign('0' + nb % 10);
}

void	ft_putunsign(char c, int i)
{
	while (i > 0)
	{
		write(1, &c, 1);
		i--;
	}
}

void	ft_put_espunsign(unsigned int nb, int n, int m)
{
	unsigned int		save;
	int					i;

	i = 1;
	save = nb;
	while (save > 0)
	{
		i++;
		save = save / 10;
	}
	n = n - i;
	if (m == 0)
	{
		ft_putunsign(' ', n);
		ft_putnbr_fdunsign(nb, 1);
	}
	if (m == 1)
	{
		ft_putnbr_fdunsign(nb, 1);
		ft_putunsign(' ', n);
	}
}

int		ft_put_0unsign(unsigned int nb, int n)
{
	unsigned int		save;
	int					i;

	i = 1;
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
		nb = -nb;
	}
	n = n - i;
	ft_putunsign('0', n);
	ft_putnbr_fdunsign(nb, 1);
	return (0);
}

int		ft_preci2unsign(unsigned int nb, int n, int t, int m)
{
	n = n - t;
	if (nb < 0)
		n--;
	if (m == 0)
		ft_putunsign(' ', n);
	if (nb == 0 && t == 0)
		return (0);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	ft_putunsign('0', t);
	ft_putnbr_fdunsign(nb, 1);
	if (m == 1)
		ft_putunsign(' ', n);
	return (0);
}

int		ft_preciunsign(unsigned int nb, int n, int t, int m)
{
	unsigned int		save;

	save = nb;
	while (save > 0)
	{
		n--;
		t--;
		save = save / 10;
	}
	if (n <= t)
	{
		ft_putunsign('0', t);
		ft_putnbr_fdunsign(nb, 1);
	}
	else
		ft_preci2unsign(nb, n, t, m);
	return (0);
}

void	ft_printunsigned(int tab[7], unsigned int nb)
{
	if (tab[2] == 0)
	{
		if (tab[3] == 0)
			ft_putnbr_fdunsign(nb, 1);
		else
			ft_put_0unsign(nb, tab[5]);
	}
	else
	{
		if (tab[3] == 0 && tab[1] == 0)
			ft_put_espunsign(nb, tab[4], tab[0]);
		if (tab[3] == 0 && tab[1] == 1)
			ft_put_0unsign(nb, tab[4]);
		if (tab[3] == 1)
			ft_preciunsign(nb, tab[4], tab[5], tab[0]);
	}
}
