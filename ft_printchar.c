/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:07:10 by paboutel          #+#    #+#             */
/*   Updated: 2020/02/19 14:47:18 by paboutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printespchar(int nb, int *tab)
{
	int	i;

	i = 1;
	while (i < nb)
	{
		write(1, " ", 1);
		tab[7]++;
		i++;
	}
}

void	ft_char_0(int *tab)
{
	while (tab[4]-- > 1)
	{
		write(1, "0", 1);
		tab[7]++;
	}
}

int		ft_printchar(int *tab, int n)
{
	unsigned char	c;

	c = n;
	if (tab[1] == 1)
		ft_char_0(tab);
	if (tab[0] == 0)
	{
		if (tab[2] == 1)
			ft_printespchar(tab[4], tab);
		write(1, &c, 1);
		tab[7]++;
		return (0);
	}
	if (tab[0] == 1)
	{
		write(1, &c, 1);
		tab[7]++;
		if (tab[2] == 1)
			ft_printespchar(tab[4], tab);
		return (0);
	}
	return (0);
}
