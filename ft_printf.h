/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:30:06 by paboutel          #+#    #+#             */
/*   Updated: 2020/02/13 14:28:39 by paboutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
#include <stdarg.h>

int     ft_atoiptr(const char *str, int *tab);
void	ft_printnbr(int tab[7], int nb);
void	ft_printunsigned(int tab[7], unsigned int nb);
int	ft_printstr(int tab[7], char *str);
int		ft_printchar(int m, int w, int nb, int n);
void	ft_printpoint(int tab[7], void *vo, char c);
void	ft_printhexa(int tab[7], long int nb, char c);

#endif

