/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:52:11 by paboutel          #+#    #+#             */
/*   Updated: 2020/02/05 23:43:54 by paboutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

void	ft_conv(int tab[7], char c, va_list list)
{
	if (c == 'c')
		ft_printchar(tab[0], tab[2], tab[4], va_arg(list, char));
	if (c == 's')
		ft_printstr(tab, va_arg(list, char *));
	if (c == 'i' || c == 'd')	
		ft_printnbr(tab, va_arg(list, int));
	if (c == 'x' || c == 'X')
		ft_printhexa(tab, va_arg(list, int), c);
	if (c == 'u')
		ft_printunsign(tab, va_arg(list, int));
	if (c == 'p')
		ft_printpoint(tab, va_arg(list, unsigned long int));
}



int 	ft_printf(const char *format, ...)
{
	va_list	list;
	int		tab[7];
	char	c;

	tab[6] = 0;
	va_start(list, format);
	printf("%s", va_arg(list, char *));
	while (*format)
	{
		while (*format && format[tab[6]++] != '%')
			ft_putchar(s[d]);
		(format[tab[6]] == '-') ? tab[0] = 1 && tab[6]++ : tab[0] = 0;
		(format[tab[6]] == '0') ? tab[1] = 1 && tab[6]++ : tab[1] = 0;
		(format[tab[6]] >= '0' && format[tab[6]] <= '9')
			? tab[2] = 1 && tab[6]++ : tab[2] = 0;
		(tab[2] == 1) ? tab[4] = ft_atoi(&format[tab[6]]) : tab[4] = 0;
		(format[tab[6]] == '*') ? tab[4] = va_arg(list, int) 
			&& tab[6]++ : tab[2] = 0;
		(format[tab[6]] == '.') ? tab[3] = 1 && tab[6]++ : tab[3] = 0;
		(tab[3] == 1) ? tab[5] = ft_atoi(&format[tab[6]]) : tab[5] = 0;
		(format[tab[6]] == '*') ? tab[5] = va_arg(list, int) 
			&& tab[5]++ : tab[3] = 0;
		c = format[tab[6]];
		ft_conv(tab, c, list);
	}
	va_end(list);
}


int	main(int ac, char **av)
{
	//ft_printf("%d %s", 123, "coucou");
	ft_printf("", "salut");
	printf("%d %s", 123, "coucou");
	return (0);
}
