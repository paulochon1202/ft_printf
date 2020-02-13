/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 03:02:07 by paboutel          #+#    #+#             */
/*   Updated: 2020/02/13 13:18:53 by paboutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (i != -1)
	{
		write(1, &str[i], 1);	
		i--;
	}
}


char	ft_ext(int d, char c)
{
	char	a;

	if (c == 'X')
		a = 'A';
	if (c == 'x')
		a = 'a';
	while (d > 0)
	{
		a++;
		d--;
	}
	return (a);
}

int		ft_hexlen(unsigned int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int		ft_hexa(unsigned long int t, char c)
{
	int		nbr;
	int		d;
	char	*str;

	d = -1;
	if (!(str = malloc(sizeof(char) * (ft_hexlen(t) + 1))))
		return (0);
	while (t > 0)
	{
		nbr = t % 16;
		t = t / 16;
		if (nbr > 9)
			str[++d] = ft_ext(nbr % 10, c);
		else
			str[++d] = nbr + '0';
	}
	ft_putstr(str);
	return (0);
}

void	ft_puthexa(char c, int i)
{
	while (i > 0)
	{
		write(1, &c, 1);
		i--;
	}
}

void	ft_put_esphexa(long int nb, int n, int m, char c)
{
	int		i;

	i = ft_hexlen(nb);
	n = n - i;
	if (m == 0)
	{
		ft_puthexa(' ', n);
		ft_hexa(nb, c);
	}
	if (m == 1)
	{
		ft_hexa(nb, c);
		ft_puthexa(' ', n);
	}
}

int		ft_put_0hexa(long int nb, int n, char c)
{
	int		i;

	i = ft_hexlen(nb);
	if (nb == 0 && n == 0)
		return (0);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	n = n - i;
	ft_puthexa('0', n);
	ft_hexa(nb, c);
	return (0);
}

int		ft_preci2hexa(long int nb, int n, int t, int m, char c)
{
	n = n - t;
	if (nb < 0)
		n--;
	if (m == 0)
		ft_puthexa(' ', n);
	if (nb == 0 && t == 0)
		return (0);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	ft_puthexa('0', t);
	ft_hexa(nb, c);
	if (m == 1)
		ft_puthexa(' ', n);
	return (0);
}

int		ft_precihexa(long int nb, int n, int t, int m, char c)
{
	int	i;

	i = ft_hexlen(nb);
	n = n - i;
	t = t - i;
	if (n <= t)
	{
		ft_puthexa('0', t);
		ft_hexa(nb, c);
	}
	else
		ft_preci2hexa(nb, n, t, m, c);
	return (0);
}

void	ft_printhexa(int tab[7], long int nb, char c)
{
	if (tab[2] == 0)
	{
		if (tab[3] == 0)
			ft_hexa(nb, c);
		else
			ft_put_0hexa(nb, tab[5], c);
	}
	else
	{
		if (tab[3] == 0 && tab[1] == 0)
			ft_put_esphexa(nb, tab[4], tab[0], c);
		if (tab[3] == 0 && tab[1] == 1)
			ft_put_0hexa(nb, tab[4], c);
		if (tab[3] == 1)
			ft_precihexa(nb, tab[4], tab[5], tab[0], c);
	}
}

void	ft_printpoint(int tab[7], void *vo, char c)
{
	long int	nb;

	nb = (long int) vo;
	write(1, "0x", 2);
	ft_put_esphexa(nb, tab[4], tab[0], c);
}

/*int		main()
{
	int	tab[7];
	char	*str;

	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = 0;
	tab[4] = 0;
	tab[5] = 0;
	tab[6] = 0;

	str = "poulet";
	ft_printpoint(tab, str, 'x');
	printf("finis");
	printf("\n");
	printf("%p", str);
	printf("finis");
	return (0);
}*/


