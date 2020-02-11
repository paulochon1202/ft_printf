/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:07:10 by paboutel          #+#    #+#             */
/*   Updated: 2020/01/31 21:26:58 by paboutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_printesp(nb)
{
	int	i;

	i = 1;
	while (i < nb)
	{
		write(1, " ", 1);
		i++;
	}
}


int		ft_printchar(int m, int w, int nb, char c)
{
	if (m == 0)
	{
		if (w == 1)
			ft_printesp(nb);
		write(1, &c, 1);
		return (0);
	}
	if (m == 1)
	{
		write(1, &c, 1);
		if (w == 1)
			ft_printesp(nb);
		return (0);
	}
	return (0);
}

int	main()
{
	printf("%-10c", 'c');
	printf("finis");
	printf("\n");
	ft_printchar(1, 1, 10, 'c');
	printf("finis");
	return (0);
}
