/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:30:06 by paboutel          #+#    #+#             */
/*   Updated: 2020/02/24 12:35:04 by paboutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_atoiptr(const char *str, int *tab);
void	ft_printnbr(int tab[8], int nb);
void	ft_printunsigned(int tab[8], unsigned int nb);
int		ft_printstr(int tab[8], char *str);
int		ft_printchar(int *tab, int n);
void	ft_printpoint(int tab[8], unsigned long int nb, char c);
void	ft_printhexa(int tab[8], unsigned int nb, char c);
void	ft_putstr(char *str, int *tab);
char	ft_ext(int d, char c);
int		ft_hexlen(long int n, int *tab);
int		ft_hexa(unsigned long int t, char c, int *tab);
void	ft_puthexa(char c, int i, int *tab);
void	ft_putstrpoint(char *str, int *tab);
char	ft_extpoint(int d, char c);
int		ft_hexlenpoint(long int n, int *tab);
int		ft_point(unsigned long int t, char c, int *tab);
void	ft_putpoint(char c, int i, int *tab);
void	ft_putcharunsign(char c, int fd, int *tab);
void	ft_putnbr_fdunsign(unsigned int nb, int fd, int *tab);
void	ft_putchar_fd(char c, int fd, int *tab);
void	ft_putnbr_fd(long int nb, int fd, int *tab);
void	ft_putunsign(char c, int i, int *tab);
void	ft_put(char c, int i, int *tab);
int		ft_printf(const char *format, ...);

#endif
