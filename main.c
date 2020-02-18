/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:52:11 by paboutel          #+#    #+#             */
/*   Updated: 2020/02/18 16:11:42 by paboutel         ###   ########.fr       */
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

int	main()
{
	ft_printf("||Returned: %d ||\n\n", ft_printf("19\t%20.15X\n", 2147483647));
	printf("||Returned: %d ||\n\n", printf("19\t%20.15X\n", 2147483647));
	ft_printf("||Returned: %d ||\n\n", ft_printf("20\t%-20.15X\n", 2147483647));
	printf("||Returned: %d ||\n\n", printf("20\t%-20.15X\n", 2147483647));
	ft_printf("||Returned: %d ||\n\n", ft_printf("21\t%020.15X\n", 2147483647));
	printf("||Returned: %d ||\n\n", printf("21\t%020.15X\n", 2147483647));
	ft_printf("||Returned: %d ||\n\n", ft_printf("22\t%-*.*X\n", -20, -15, 2147483647));
	printf("||Returned: %d ||\n\n", printf("22\t%-*.*X\n", -20, -15, 2147483647));
	ft_printf("||Returned: %d ||\n\n", ft_printf("23\t%*.*X\n", 20, -15, 2147483647));
	printf("||Returned: %d ||\n\n", printf("23\t%*.*X\n", 20, -15, 2147483647));
	ft_printf("||Returned: %d ||\n\n", ft_printf("24\t%*.*X\n", -20, -15, 2147483647));
	printf("||Returned: %d ||\n\n", printf("24\t%*.*X\n", -20, -15, 2147483647));
	ft_printf("||Returned: %d ||\n\n", ft_printf("25\t%0*.*X\n", -20, -15, 2147483647));
	printf("||Returned: %d ||\n\n", printf("25\t%0*.*X\n", -20, -15, 2147483647));
	ft_printf("||Returned: %d ||\n\n", ft_printf("26\t%*.*X\n", -20, 15, -2147483647));
	printf("||Returned: %d ||\n\n", printf("26\t%*.*X\n", -20, 15, -2147483647));
	ft_printf("||Returned: %d ||\n\n", ft_printf("27\t%*.*X\n", -20, 15, -1));
	printf("||Returned: %d ||\n\n", printf("27\t%*.*X\n", -20, 15, -1));
	ft_printf("||Returned: %d ||\n\n", ft_printf("28\t%*.*X\n", -20, 15, -123456));
	printf("||Returned: %d ||\n\n", printf("28\t%*.*X\n", -20, 15, -123456));
/*	ft_printf("||Returned: %d ||\n\n", ft_printf("29\t%.*X\n", 15, -123456));
	printf("||Returned: %d ||\n\n", printf("29\t%.*X\n", 15, -123456));
	ft_printf("||Returned: %d ||\n\n", ft_printf("30\t%*X\n", -20, -123456));
	printf("||Returned: %d ||\n\n", printf("30\t%*X\n", -20, -123456));
	ft_printf("||Returned: %d ||\n\n", ft_printf("31\t%*X\n", 20, -123456));
	printf("||Returned: %d ||\n\n", printf("31\t%*X\n", 20, -123456));
	ft_printf("||Returned: %d ||\n\n", ft_printf("32\t%X\n", -123456));
	printf("||Returned: %d ||\n\n", printf("32\t%X\n", -123456));
	ft_printf("||Returned: %d ||\n\n", ft_printf("33\t%x\n", -123456));
	printf("||Returned: %d ||\n\n", printf("33\t%x\n", -123456));
	ft_printf("||Returned: %d ||\n\n", ft_printf("34\t%x\n", 123456));
	printf("||Returned: %d ||\n\n", printf("34\t%x\n", 123456));
	ft_printf("||Returned: %d ||\n\n", ft_printf("35\t%x\n", 0));
	printf("||Returned: %d ||\n\n", printf("35\t%x\n", 0));
	ft_printf("||Returned: %d ||\n\n", ft_printf("36\t%.3x\n", 123456));
	printf("||Returned: %d ||\n\n", printf("36\t%.3x\n", 123456));
	ft_printf("||Returned: %d ||\n\n", ft_printf("37\t%3x\n", 123456));
	printf("||Returned: %d ||\n\n", printf("37\t%3x\n", 123456));
	ft_printf("||Returned: %d ||\n\n", ft_printf("38\t%020.15x\n", -2147483647 - 1));	
	printf("||Returned: %d ||\n\n", printf("38\t%020.15x\n", -2147483647 - 1));
	ft_printf("||Returned: %d ||\n\n", ft_printf("39\t%.x\n", 0));
	printf("||Returned: %d ||\n\n", printf("39\t%.x\n", 0));
	ft_printf("||Returned: %d ||\n\n", ft_printf("40\t%20.x\n", 0)); 
	printf("||Returned: %d ||\n\n", printf("40\t%20.x\n", 0));
	ft_printf("||Returned: %d ||\n\n", ft_printf("41\t%020x\n", 0));
	printf("||Returned: %d ||\n\n", printf("41\t%020x\n", 0));
	ft_printf("||Returned: %d ||\n\n", ft_printf("42\t%-20x\n", 0));
	printf("||Returned: %d ||\n\n", printf("42\t%-20x\n", 0));
	ft_printf("||Returned: %d ||\n\n", ft_printf("43\t%20x\n", 0));
	printf("||Returned: %d ||\n\n", printf("43\t%20x\n", 0));*/
	return (0);
}
