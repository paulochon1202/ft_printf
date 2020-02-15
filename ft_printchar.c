/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:07:10 by paboutel          #+#    #+#             */
/*   Updated: 2020/02/14 15:34:40 by paboutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printespchar(nb)
{
	int	i;

	i = 1;
	while (i < nb)
	{
		write(1, " ", 1);
		i++;
	}
}


int		ft_printchar(int m, int w, int nb, int n)
{
	unsigned char	c;

	c = n;
	if (m == 0)
	{
		if (w == 1)
			ft_printespchar(nb);
		write(1, &c, 1);
		return (0);
	}
	if (m == 1)
	{
		write(1, &c, 1);
		if (w == 1)
			ft_printespchar(nb);
		return (0);
	}
	return (0);
}
