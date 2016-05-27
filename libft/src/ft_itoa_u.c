/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:22:18 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/18 10:22:23 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_calc_u(unsigned int n, int *len)
{
	unsigned int	k;

	k = n;
	while (k)
	{
		k /= 10;
		len[0]++;
	}
	return (n);
}

void			fln_u(char *str, int *len)
{
	if (len[1])
		str[0] = '-';
	str[len[0] + len[1]] = '\0';
}

char			*jedoismlloc_u(unsigned int n)
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

char			*ft_itoa_u(unsigned int n)
{
	int		len[2];
	char	*str;

	len[0] = 0;
	len[1] = 0;
	if (n == 0)
	{
		str = jedoismlloc_u(n);
		return (str);
	}
	n = ft_calc_u(n, len);
	if (!(str = malloc(len[0] * sizeof(char) + 1 + len[1])))
		return (NULL);
	fln_u(str, len);
	while (n)
	{
		str[len[0] - 1 + len[1]] = n % 10 + '0';
		n /= 10;
		len[0]--;
	}
	return (str);
}
