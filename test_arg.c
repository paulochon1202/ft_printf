/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:31:29 by paboutel          #+#    #+#             */
/*   Updated: 2020/01/23 12:50:34 by paboutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int	ft_testspe(char	*s1, char *s2)
{
	printf("test\n");
	printf("%s\n", s1);
	printf("%s\n", s2);
	return (0);
}

int ft_test(const char *format, ...)
{
	va_list list;

	va_start(list, format);
	printf("%s\n", format);
	ft_testspe(va_arg(list, char *), va_arg(list, char *));
	printf("%s\n", va_arg(list, char *));
	va_end(list);
	return (0);
}

int	main()
{
	ft_test("numero0", "numero1", "numero2", "3", "4", "5");
	return (0);
}
