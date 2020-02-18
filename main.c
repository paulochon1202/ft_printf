/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:52:11 by paboutel          #+#    #+#             */
/*   Updated: 2020/02/18 11:41:36 by paboutel         ###   ########.fr       */
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
	ft_printf("%-11.4xq67Ok71R4pDNZD0%-.4i\n", 2147483647, 0);
	printf("%-11.4xq67Ok71R4pDNZD0%-.4i\n", 2147483647, 0);
	ft_printf("3cMM1mphLNtiD8AVJTshgb%%\n");
	printf("3cMM1mphLNtiD8AVJTshgb%%\n");
	ft_printf("%c%ud\n", '\0', 0);
	printf("%c%ud\n", '\0', 0);
	ft_printf("H%0.2Xzwi%cDqBl0sr\n", -711400962, '\0');
	printf("H%0.2Xzwi%cDqBl0sr\n", -711400962, '\0');
	ft_printf("MFJi2aoDf2e\n");
	printf("MFJi2aoDf2e\n");
	ft_printf("a%XGMD\n", -2147483647);
	printf("a%XGMD\n", -2147483647);
	ft_printf("gZaTaktLz6CTU4emShva%-17x\n", -2147483647);
	printf("gZaTaktLz6CTU4emShva%-17x\n", -2147483647);
	ft_printf("%6s%010x0af9w%%%c\n", "", -2147483647, '\0');
	printf("%6s%010x0af9w%%%c\n", "", -2147483647, '\0');
	ft_printf("%0.2u%-*sl7MB%-.0uFwApn3%%%8c\n", 0, -4, "vUYOJhnwfB4RgmDr6NoyhkRd3D2Px4qEorXl", -1489152916, '\0');
	printf("%0.2u%-*sl7MB%-.0uFwApn3%%%8c\n", 0, -4, "vUYOJhnwfB4RgmDr6NoyhkRd3D2Px4qEorXl", -1489152916, '\0');
	ft_printf("3bEne%-.3XR%-17.*iZ7ZeD6nK0da2kmk\n", 2147483647, -8, 2147483647);
	printf("3bEne%-.3XR%-17.*iZ7ZeD6nK0da2kmk\n", 2147483647, -8, 2147483647);
	ft_printf(" j0OI2CDUVCQQiNB3eYAzDxYK0qFN%i\n", 0);
	printf(" j0OI2CDUVCQQiNB3eYAzDxYK0qFN%i\n", 0);
	ft_printf("LhJ8z\n");
	printf("LhJ8z\n");
	ft_printf("uY%x%x%.2d%%JLMPa\n", 2147483647, 0, -2147483647);
	printf("uY%x%x%.2d%%JLMPa\n", 2147483647, 0, -2147483647);
	ft_printf("Y79ARH7JF3mQWNVE0\n");
	printf("Y79ARH7JF3mQWNVE0\n");
	ft_printf("%014XE EaWqtq7jik%-isYwYjb6o8Rfl\n", 0, 1518101114);
	printf("%014XE EaWqtq7jik%-isYwYjb6o8Rfl\n", 0, 1518101114);
	ft_printf("vA%0*i5OO%-6.*x\n", 3, 0, -10, 2147483647);
	printf("vA%0*i5OO%-6.*x\n", 3, 0, -10, 2147483647);
	ft_printf("8ntIRoSkCodX2%%hOXpaltwoOe\n");
	printf("8ntIRoSkCodX2%%hOXpaltwoOe\n");
	ft_printf("\n");
	printf("\n");
	ft_printf("nfUksO05%-*s38lP l2%7X\n", 2, "jQeO6dTuhhfILyumpt1QDKH", -1395957496);
	printf("nfUksO05%-*s38lP l2%7X\n", 2, "jQeO6dTuhhfILyumpt1QDKH", -1395957496);
	ft_printf("%d%-8dqigNDPjdWl7%-7cdgU\n", -2147483647, 2147483647, '\0');
	printf("%d%-8dqigNDPjdWl7%-7cdgU\n", -2147483647, 2147483647, '\0');
	ft_printf("VZl8%0X%019.3x%%%0u2yb\n", 0, 0, 867896671);
	printf("VZl8%0X%019.3x%%%0u2yb\n", 0, 0, 867896671);
	ft_printf("ZArAmxgEwWk%-16c6zjGa5ZciXPsqcIod\n", '\0');
	printf("ZArAmxgEwWk%-16c6zjGa5ZciXPsqcIod\n", '\0');
	ft_printf("CqaX1V\n");
	printf("CqaX1V\n");
	ft_printf("%-.4s\n", NULL);
	printf("%-.4s\n", NULL);
	ft_printf("GuwUCvBVqXSc%c%-14x\n", '\0', 0);
	printf("GuwUCvBVqXSc%c%-14x\n", '\0', 0);
	ft_printf("4cuECM%04u4%-X%cwWYU%3cu5\n", -2147483647, 2106589664, '4', '2');
	printf("4cuECM%04u4%-X%cwWYU%3cu5\n", -2147483647, 2106589664, '4', '2');
	ft_printf("GgfJ\n");
	printf("GgfJ\n");
	ft_printf("a8XMYYNnWx%19cdHIhMYB7z%-13.4xN\n", '\0', 2147483647);
	printf("a8XMYYNnWx%19cdHIhMYB7z%-13.4xN\n", '\0', 2147483647);
	ft_printf("JZRSa%-.2x%13cl9HA%-.0x%*.4sJi\n", 0, 'V', -2147483647, 5, "fdTR4vaVPBsAzV1Eq6EzIfIYySfVlf4fk4tDFkK9omhAGXAWSVGZXoijP9ssymKHLvSM2KvxO56gg2fIQiKZLrJAwxD5zH1Qfn");
	printf("JZRSa%-.2x%13cl9HA%-.0x%*.4sJi\n", 0, 'V', -2147483647, 5, "fdTR4vaVPBsAzV1Eq6EzIfIYySfVlf4fk4tDFkK9omhAGXAWSVGZXoijP9ssymKHLvSM2KvxO56gg2fIQiKZLrJAwxD5zH1Qfn");
	ft_printf("3U%0.5XX4%XmxVoz5hj\n", -2147483647, 0);
	printf("3U%0.5XX4%XmxVoz5hj\n", -2147483647, 0);
	ft_printf("%%%0i%cyM%cjl%2i%.1X\n", 1657240681, '\0', '\0', 2147483647, -2147483647);
	printf("%%%0i%cyM%cjl%2i%.1X\n", 1657240681, '\0', '\0', 2147483647, -2147483647);
	ft_printf("%-.3d%5cLE6joC%-c%0.*x%c\n", 0, '\0', '\0', -6, 0, '\0');
	printf("%-.3d%5cLE6joC%-c%0.*x%c\n", 0, '\0', '\0', -6, 0, '\0');
	ft_printf("%-iAN3S%-3X%019i\n", 0, -2147483647, -2147483647);
	printf("%-iAN3S%-3X%019i\n", 0, -2147483647, -2147483647);
	ft_printf("hGjMi%%9xLSZju\n");
	printf("hGjMi%%9xLSZju\n");
	ft_printf("%0.3i\n", 0);
	printf("%0.3i\n", 0);
	ft_printf("la aussi : %011ifnmS9bV\n", 1977502330);
	printf("la aussi : %011ifnmS9bV\n", 1977502330);
	ft_printf("Uf5PE%-.2x\n", 2147483647);
	printf("Uf5PE%-.2x\n", 2147483647);
	ft_printf("vry%c%%EFbXPUJQ%-.3xgyZsj\n", 'D', 0);
	printf("vry%c%%EFbXPUJQ%-.3xgyZsj\n", 'D', 0);
	ft_printf("7Yz6BgK\n");
	printf("7Yz6BgK\n");
	ft_printf("ICI : 1J0NWJ%019.*uqmu\n", -10, 2147483647);
	printf("ICI : 1J0NWJ%019.*uqmu\n", -10, 2147483647);
	ft_printf("vPIE%-.4d3x5Hvq4\n", 870546998);
	printf("vPIE%-.4d3x5Hvq4\n", 870546998);
	ft_printf("RaYm\n");
	printf("RaYm\n");
	ft_printf("%-7i%s%i%XjRytUtYR\n", 2147483647, "", -2147483647, -2147483647);
	printf("%-7i%s%i%XjRytUtYR\n", 2147483647, "", -2147483647, -2147483647);
	ft_printf("%%%.0x%07.3X2D NttpnNkcpfEOFnzE0u\n", 2147483647, 928565261);
	printf("%%%.0x%07.3X2D NttpnNkcpfEOFnzE0u\n", 2147483647, 928565261);
	printf("\n");
	return (0);
}
