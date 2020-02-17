/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:52:11 by paboutel          #+#    #+#             */
/*   Updated: 2020/02/17 18:01:15 by paboutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_conv(int tab[7], char c, va_list list)
{
	if (tab[4] < 0)
	{
		tab[4] = -tab[4];
		tab[0] = 1;
	}
	if (c == 'c')
		ft_printchar(tab, va_arg(list, int));
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
	if (c == '%')
		ft_printchar(tab, '%');
}

int		ft_printf(const char *format, ...)
{
	va_list	list;
	int		tab[8];
	char	c;

	tab[6] = 0;
	tab[7] = 0;
	va_start(list, format);
	while (format[tab[6]] != '\0')
	{
		while (format[tab[6]] && format[tab[6]] != '%')
		{
			write(1, &format[tab[6]], 1);
			tab[6]++;
			tab[7]++;
		}
		if (format[tab[6]] == '\0')
			return (tab[7]);
		tab[6]++;
		(format[tab[6]] == '-') ? tab[0] = 1 && tab[6]++ : (tab[0] = 0);

	
		//tab[0] = ( format[tab[6]] == '-' ? : 1 : 0);
		//if (tab[0] == 1)
		//	tab[6]++;

		(format[tab[6]] == '0') ? tab[1] = 1 && tab[6]++ : (tab[1] = 0);
		(format[tab[6]] >= '0' && format[tab[6]] <= '9')
			? tab[2] = 1 : (tab[2] = 0);
		(tab[2] == 1) ? tab[4] = ft_atoiptr(format, &tab[6]) : (tab[4] = 0);
		if (format[tab[6]] == '*')
		{
			tab[4] = va_arg(list, int);
			tab[6]++;
			tab[2] = 1;
		}
		(format[tab[6]] == '.') ? tab[3] = 1 && tab[6]++ : (tab[3] = 0);
		(tab[3] == 1) ? tab[5] = ft_atoiptr(format, &tab[6]) : (tab[5] = 0);
		if (format[tab[6]] == '*')
		{
			tab[5] = va_arg(list, int);
			tab[6]++;
			tab[3] = 1;
		}
		c = format[tab[6]++];
		ft_conv(tab, c, list);
		while (format[tab[6]] && format[tab[6]] != '%')
		{
			write(1, &format[tab[6]], 1);
			tab[6]++;
			tab[7]++;
		}
	}
	va_end(list);
	return (tab[7]);
}
/*
int	main()
{
//	ft_printf("%-*XJ68BI", 10, -92113801); 
//	ft_printf("%-.3u", 0); 
//	ft_printf("%5d1N", 1283278733); 
//	ft_printf("%4d", 2147483647); 
//	ft_printf("%1X3oN6v", 0);
//	ft_printf("\n");
	ft_printf("%-*XJ68BI%-.3u%5d1N%4d%1X3oN6v\n", 10, -92113801, 0, 1283278733, 2147483647, 1);
//	printf("%-*XJ68BI", 10, -92113801); 
//	printf("%-.3u", 0); 
//	printf("%5d1N", 1283278733); 
//	printf("%4d", 2147483647); 
//	printf("%1X3oN6v", 0);
//	printf("\n");
	printf("%-*XJ68BI%-.3u%5d1N%4d%1X3oN6v\n", 10, -92113801, 0, 1283278733, 2147483647, 1);
	return (0);
}*/
