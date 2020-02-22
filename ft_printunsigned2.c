/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:43:16 by paboutel          #+#    #+#             */
/*   Updated: 2020/02/21 19:03:14 by paboutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
