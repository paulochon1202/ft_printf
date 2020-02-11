/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 18:13:08 by paboutel          #+#    #+#             */
/*   Updated: 2020/02/11 19:05:14 by paboutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_test(char *str)
{
	int	i;
	long int test;

	i = 0;
	test = (long int) str;
	printf("%lx\n", test);
}

int	main()
{
	char	*c = "poulet";

	printf("%p", c);
	printf("\n");
	ft_test(c);
	return (0);
}
