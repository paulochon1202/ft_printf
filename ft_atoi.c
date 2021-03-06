/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:03:07 by paboutel          #+#    #+#             */
/*   Updated: 2020/02/13 14:31:28 by paboutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoiptr(const char *str, int *i)
{
	int	nb;
	int	n;

	nb = 0;
	n = 1;
	while (str[*i] == '\t' || str[*i] == '\n' || str[*i] == '\v'
			|| str[*i] == '\f' || str[*i] == '\r' || str[*i] == ' ')
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			n = -n;
		(*i)++;
	}
	while (str[(*i)] <= '9' && str[(*i)] >= '0')
	{
		nb = nb * 10 + str[*i] - '0';
		(*i)++;
	}
	return (nb * n);
}
