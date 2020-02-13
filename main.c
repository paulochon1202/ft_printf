/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:52:11 by paboutel          #+#    #+#             */
/*   Updated: 2020/02/13 17:02:32 by paboutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	ft_conv(int tab[7], char c, va_list list)
{
	if (c == 'c')
		ft_printchar(tab[0], tab[2], tab[4], va_arg(list, int));
	if (c == 's')
		ft_printstr(tab, va_arg(list, char *));
	if (c == 'i' || c == 'd')	
		ft_printnbr(tab, va_arg(list, int));
	if (c == 'x' || c == 'X')
		ft_printhexa(tab, va_arg(list, int), c);
	if (c == 'u')
		ft_printunsigned(tab, va_arg(list, int));
	if (c == 'p')
		ft_printpoint(tab, va_arg(list, void *), c);
}

#include <stdio.h>

int 	ft_printf(const char *format, ...)
{
	va_list	list;
	int		tab[7];
	char	c;

	tab[6] = 0;
	va_start(list, format);
	while (format[tab[6]] != '\0')
	{
		while (format[tab[6]] && format[tab[6]] != '%')
		{	
			write(1, &format[tab[6]], 1);
			tab[6]++;
		}
		tab[6]++;
		(format[tab[6]] == '-') ? tab[0] = 1 && tab[6]++ : (tab[0] = 0);
		(format[tab[6]] == '0') ? tab[1] = 1 && tab[6]++ : (tab[1] = 0);
		(format[tab[6]] >= '0' && format[tab[6]] <= '9')
			? tab[2] = 1 : (tab[2] = 0);
		(tab[2] == 1) ? tab[4] = ft_atoiptr(format, &tab[6]) : (tab[4] = 0);
		if (format[tab[6]] == '*') 
		{
			tab[4] = va_arg(list, int) 
			&& tab[6]++;
			tab[2] = 1;
		}
		(format[tab[6]] == '.') ? tab[3] = 1 && tab[6]++ : (tab[3] = 0);
		(tab[3] == 1) ? tab[5] = ft_atoiptr(format, &tab[6]) : (tab[5] = 0);
		if (format[tab[6]] == '*') 
		{
			tab[5] = va_arg(list, int) ;
			tab[5]++;
			tab[3] = 1;
		}
		c = format[tab[6]++];
	/*	printf("0=%d\n", tab[0]);
		printf("1=%d\n", tab[1]);
		printf("2=%d\n", tab[2]);
		printf("3=%d\n", tab[3]);
		printf("4=%d\n", tab[4]);
		printf("5=%d\n", tab[5]);
		printf("6=%d\n", tab[6]);
		printf("c = %c\n", c);*/
		ft_conv(tab, c, list);
		while (format[tab[6]] && format[tab[6]] != '%')
		{
			write(1, &format[tab[6]], 1);
			tab[6]++;
		}
	}
	va_end(list);
	return (tab[6]);
}


int	main()
{
	ft_printf("%s\n", NULL);
	printf("%s", NULL);
	return (0);
}
