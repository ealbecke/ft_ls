/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:20:44 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/18 10:21:17 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_calc_base(int n, int *len, int base)
{
	int k;

	k = n;
	if (n < 0)
	{
		len[1] = 1;
		n *= -1;
	}
	while (k)
	{
		k /= base;
		len[0]++;
	}
	return (n);
}

void	fln_base(char *str, int *len)
{
	if (len[1])
		str[0] = '-';
	str[len[0] + len[1]] = '\0';
}

char	*jedoismlloc_base(int n, int base)
{
	char	*st;

	st = NULL;
	if (n == 0)
	{
		st = malloc(2);
		st[1] = '\0';
		st[0] = '0';
	}
	else if (n == -2147483648)
	{
		st = ft_itoa_base_u((unsigned int)(n * -1), base);
		return (ft_strjoin("-", st));
	}
	return (0);
}

char	*ft_itoa_base(int n, int base)
{
	int		len[2];
	char	*str;

	len[0] = 0;
	len[1] = 0;
	if (n == 0 || n == -2147483648)
	{
		str = jedoismlloc_base(n, base);
		return (str);
	}
	n = ft_calc_base(n, len, base);
	if (!(str = malloc(len[0] * sizeof(char) + 1 + len[1])))
		return (NULL);
	fln_base(str, len);
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
