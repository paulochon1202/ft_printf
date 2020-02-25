/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:52:11 by paboutel          #+#    #+#             */
/*   Updated: 2020/02/25 07:37:52 by paboutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_conv(int tab[8], char c, va_list list)
{
	if (tab[4] < 0)
	{
		tab[4] = -tab[4];
		tab[0] = 1;
		tab[1] = 0;
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
		ft_printpoint(tab, va_arg(list, unsigned long int), 'x');
	if (c == '%')
		ft_printchar(tab, '%');
}

void	ft_next1(const char *format, int *tab)
{
	tab[6]++;
	if (format[tab[6]] == '-')
		tab[0] = 1;
	else
		tab[0] = 0;
	while (format[tab[6]] == '-')
		tab[6]++;
	if (format[tab[6]] == '0')
		tab[1] = 1;
	else
		tab[1] = 0;
	while (format[tab[6]] == '0')
		tab[6]++;
	if (format[tab[6]] >= '0' && format[tab[6]] <= '9')
		tab[2] = 1;
	else
		tab[2] = 0;
	if (tab[2] == 1)
		tab[4] = ft_atoiptr(format, &tab[6]);
	else
		tab[4] = 0;
}

void	ft_next2(const char *format, int *tab, va_list list)
{
	if (format[tab[6]] == '*')
	{
		tab[4] = va_arg(list, int);
		tab[6]++;
		tab[2] = 1;
	}
	if (format[tab[6]] == '.')
	{
		tab[3] = 1;
		tab[6]++;
	}
	else
		tab[3] = 0;
	if (tab[3] == 1)
		tab[5] = ft_atoiptr(format, &tab[6]);
	else
		tab[5] = 0;
	if (format[tab[6]] == '*')
	{
		tab[5] = va_arg(list, int);
		tab[6]++;
		tab[3] = 1;
	}
}

void	ft_next3(const char *format, int *tab)
{
	while (format[tab[6]] && format[tab[6]] != '%')
	{
		write(1, &format[tab[6]], 1);
		tab[6]++;
		tab[7]++;
	}
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
		ft_next3(format, tab);
		if (format[tab[6]] == '\0')
			return (tab[7]);
		ft_next1(format, tab);
		ft_next2(format, tab, list);
		c = format[tab[6]++];
		ft_conv(tab, c, list);
		ft_next3(format, tab);
	}
	va_end(list);
	return (tab[7]);
}

int	main(void)
{
	ft_printf("%05.*dG\n", 10, 191350883);
	printf("%05.*dG\n", 10,  191350883);
}
