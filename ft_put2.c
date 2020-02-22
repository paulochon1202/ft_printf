/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:41:15 by paboutel          #+#    #+#             */
/*   Updated: 2020/02/21 19:02:42 by paboutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd, int *tab)
{
	write(fd, &c, 1);
	tab[7]++;
}

void	ft_putnbr_fd(long int nb, int fd, int *tab)
{
	if (nb < 0)
	{
		ft_putchar_fd('-', fd, tab);
		if (nb == -2147483648)
		{
			ft_putchar_fd('2', fd, tab);
			nb = -147483648;
		}
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd, tab);
	ft_putchar_fd('0' + nb % 10, fd, tab);
}

void	ft_put(char c, int i, int *tab)
{
	while (i > 0)
	{
		write(1, &c, 1);
		tab[7]++;
		i--;
	}
}
