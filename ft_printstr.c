/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:41:55 by paboutel          #+#    #+#             */
/*   Updated: 2020/02/11 18:51:49 by paboutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_str(char *str, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, &str[i], 1);
		i++;
	}
}


int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_printesp(nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		write(1, " ", 1);
		i++;
	}
}

int	ft_nopreci(int tab[7], int t, char *str)
{
	if (tab[0] == 0)
	{
		if (tab[2] == 1)
			ft_printesp(tab[4] - t);
		ft_str(str, t);
		return (0);
	}
	if (tab[0] == 1)
	{
		ft_str(str, t);
		if (tab[2] == 1)
			ft_printesp(tab[4] - t);
		return (0);
	}
	return (0);
}
int	ft_printstr(int tab[7], char *str)
{
	int	i;
	int	t;

	i = 0;
	t = ft_strlen(str);
	if (tab[3] == 0)
		ft_nopreci(tab, t, str);	
	if (tab[3] == 1)
	{
		if (tab[5] > t)
			ft_nopreci(tab, t, str);
		else 
			ft_nopreci(tab, tab[5], str);
	}
	return (0);
}

int	main()
{
	int	tab[7];

	tab[0] = 1; 
	tab[1] = 0;
	tab[2] = 1;
	tab[3] = 1;
	tab[4] = 0;
	tab[5] = 10;
	tab[6] = 100;
	ft_printstr(tab, "poulet");
	printf("finis");
	printf("\n");
	printf("%-.10s", "poulet");
	printf("finis");
}
