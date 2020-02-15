/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:05:10 by paboutel          #+#    #+#             */
/*   Updated: 2020/02/14 15:41:04 by paboutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		if (nb == -2147483648)
		{
			ft_putchar_fd('2', fd);
			nb = -147483648;
		}
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd('0' + nb % 10, fd);
}

void	ft_put(char c, int i)
{
	while (i > 0)
	{
		write(1, &c, 1);
		i--;
	}
}

void	ft_put_esp(int nb, int n, int m)
{
	int		save;
	int		i;

	i = 0;
	save = nb;
	if (save < 0)
		save = -save;
	while (save > 0)
	{
		i++;
		save = save / 10;
	}
	n = n - i;
	if (m == 0)
	{
		ft_put(' ', n);
		ft_putnbr_fd(nb, 1);
	}
	if (m == 1)
	{
		ft_putnbr_fd(nb, 1);
		ft_put(' ', n);
	}
}

int		ft_put_0(int nb, int n)
{
	int		save;
	int		i;

	i = 1;
	save = nb;
	if (save < 0)
		save = -save;
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
	ft_put('0', n);
	ft_putnbr_fd(nb, 1);
	return (0);
}

int		ft_preci2(int nb, int n, int t, int m)
{
	n = n - t;
	if (nb < 0)
		n--;
	if (m == 0)
		ft_put(' ', n);
	if (nb == 0 && t == 0)
		return (0);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	ft_put('0', t);
	ft_putnbr_fd(nb, 1);
	if (m == 1)
		ft_put(' ', n);
	return (0);
}

int		ft_preci(int nb, int n, int t, int m)
{
	int		save;

	save = nb;
	if (save < 0)
		save = -save;
	while (save > 0)
	{
		n--;
		t--;
		save = save / 10;
	}
	if (n <= t)
	{
		ft_put('0', t);
		ft_putnbr_fd(nb, 1);
	}
	else
		ft_preci2(nb, n, t, m);
	return (0);
}

void	ft_printnbr(int tab[7], int nb)
{
	if (tab[2] == 0)
	{
		if (tab[3] == 0)
			ft_putnbr_fd(nb, 1);
		else
			ft_put_0(nb, tab[5]);
	}
	else
	{
		if (tab[3] == 0 && tab[1] == 0)
			ft_put_esp(nb, tab[4], tab[0]);
		if (tab[3] == 0 && tab[1] == 1)
			ft_put_0(nb, tab[4]);
		if (tab[3] == 1)
			ft_preci(nb, tab[4], tab[5], tab[0]);
	}
}
