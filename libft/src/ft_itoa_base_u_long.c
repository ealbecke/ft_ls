/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_u_long.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:21:56 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/18 10:22:03 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long int	ft_calc_base_u_long(unsigned long int n, int *len, int base)
{
	unsigned long int	k;

	k = n;
	while (k)
	{
		k /= base;
		len[0]++;
	}
	return (n);
}

void				fln_base_u_long(char *str, int *len)
{
	if (len[1])
		str[0] = '-';
	str[len[0] + len[1]] = '\0';
}

char				*jedoismlloc_base_u_long(unsigned long int n)
{
	char	*st;

	st = NULL;
	if (n == 0)
	{
		st = malloc(2);
		st[1] = '\0';
		st[0] = '0';
	}
	return (st);
}

char				*ft_itoa_base_u_long(unsigned long int n, int base)
{
	int		len[2];
	char	*str;

	len[0] = 0;
	len[1] = 0;
	if (n == 0)
	{
		str = jedoismlloc_base_u_long(n);
		return (str);
	}
	n = ft_calc_base_u_long(n, len, base);
	if (!(str = malloc(len[0] * sizeof(char) + 1 + len[1])))
		return (NULL);
	fln_base_u_long(str, len);
	while (n)
	{
		if (n % base < 10)
			str[len[0] - 1 + len[1]] = n % base + '0';
		else
			str[len[0] - 1 + len[1]] = n % base + 'a' - 10;
		n /= base;
		len[0]--;
	}
	return (str);
}
