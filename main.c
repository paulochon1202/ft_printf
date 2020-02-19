/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:52:11 by paboutel          #+#    #+#             */
/*   Updated: 2020/02/19 16:34:00 by paboutel         ###   ########.fr       */
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
		(format[tab[6]] == '-') ? tab[0] = 1 : (tab[0] = 0);
		while (format[tab[6]] == '-')
			tab[6]++;
		(format[tab[6]] == '0') ? tab[1] = 1 : (tab[1] = 0);
		while (format[tab[6]] == '0')
			tab[6]++;
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
	ft_printf("||Returned: %d ||\n\n", ft_printf("56\t%3d\n", -1));	
	printf("||Returned: %d ||\n\n", printf("56\t%3d\n", -1));	
//	ft_printf("||Returned: %d ||\n\n", ft_printf("57\t%4d\n", -1));	
//	printf("||Returned: %d ||\n\n", printf("57\t%4d\n", -1));	
//	ft_printf("||Returned: %d ||\n\n", ft_printf("58\t%020.15d\n", -1));
//	printf("||Returned: %d ||\n\n", printf("58\t%020.15d\n", -1));
//	ft_printf("||Returned: %d ||\n\n", ft_printf("59\t%20.15d\n", -1));
//	printf("||Returned: %d ||\n\n", printf("59\t%20.15d\n", -1));
//	ft_printf("||Returned: %d ||\n\n", ft_printf("60\t%-20.15d\n", -123));
//	printf("||Returned: %d ||\n\n", printf("60\t%-20.15d\n", -123));
//	ft_printf("||Returned: %d ||\n\n", ft_printf("61\t%d\n", 2147483647));
//	printf("||Returned: %d ||\n\n", printf("61\t%d\n", 2147483647));
//	ft_printf("||Returned: %d ||\n\n", ft_printf("62\t%d\n", -2147483647 - 1));
//	printf("||Returned: %d ||\n\n", printf("62\t%d\n", -2147483647 - 1));
//	ft_printf("||Returned: %d ||\n\n", ft_printf("63\t%020.15d\n", -2147483647 - 1));
//	printf("||Returned: %d ||\n\n", printf("63\t%020.15d\n", -2147483647 - 1));
//	ft_printf("||Returned: %d ||\n\n", ft_printf("64\t%.d\n", 0));
//	printf("||Returned: %d ||\n\n", printf("64\t%.d\n", 0));
//	ft_printf("||Returned: %d ||\n\n", ft_printf("65\t%20.d\n", 0));
//	printf("||Returned: %d ||\n\n", printf("65\t%20.d\n", 0));
//	ft_printf("||Returned: %d ||\n\n", ft_printf("66\t%020d\n", 0));
//	printf("||Returned: %d ||\n\n", printf("66\t%020d\n", 0));
//	ft_printf("||Returned: %d ||\n\n", ft_printf("67\t%-20d\n", 0));
//	printf("||Returned: %d ||\n\n", printf("67\t%-20d\n", 0));
//	ft_printf("||Returned: %d ||\n\n", ft_printf("67\t%20d\n", 0));
//	printf("||Returned: %d ||\n\n", printf("67\t%20d\n", 0));
//	ft_printf("||Returned: %d ||\n\n", ft_printf("68\t%00000000004d\n", -1));
//	printf("||Returned: %d ||\n\n", printf("68\t%00000000004d\n", -1));
//	ft_printf("||Returned: %d ||\n\n", ft_printf("70\t%----------4d\n", -1));
//	printf("||Returned: %d ||\n\n", printf("70\t%----------4d\n", -1));
//	ft_printf("||Returned: %d ||\n\n", ft_printf("71\t%.0005d\n", 132));
//	printf("||Returned: %d ||\n\n", printf("71\t%.0005d\n", 132));
	
	return (0);
}
