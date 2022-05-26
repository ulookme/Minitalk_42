/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gearbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:50:38 by chajjar           #+#    #+#             */
/*   Updated: 2022/05/26 13:30:35 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_2_power(int nb)
{
	int	res;

	res = 1;
	while (nb > 0)
	{
		res = res * 2;
		nb--;
	}
	return (res);
}

char	*ft_char_to_bytes(unsigned char octet)
{
	int		i;
	int		j;
	char	*tab;

	i = 7;
	j = 0;
	tab = (char *)malloc(sizeof(char) * (9));
	while (i >= 0)
	{
		if (ft_2_power(i) <= octet)
		{
			tab[j] = '1';
			octet = octet - ft_2_power(i);
		}
		else
			tab[j] = '0';
		j++;
		i--;
	}
	tab[8] = '\0';
	return (tab);
}

unsigned char	ft_bytes_to_char(char *str)
{
	int				i;
	int				j;
	unsigned char	octet;

	i = 0;
	j = 7;
	octet = 0;
	while (i <= 7 && str[i])
	{
		if (str[i] == '1')
			octet = octet + ft_2_power(j);
		i++;
		j--;
	}
	return (octet);
}

int	ft_atoi(const char *str)
{
	long int	res;
	int			negative;

	negative = 1;
	res = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (res * negative);
}
