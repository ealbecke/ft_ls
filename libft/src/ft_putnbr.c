/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:26:52 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/18 10:27:03 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	thelse(int n, int k)
{
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-');
	}
	while (n / k == 0)
		k /= 10;
	if (n < 10)
		ft_putchar(n + '0');
	else
	{
		while (k != 1)
		{
			ft_putchar((n / k) + '0');
			n = n - (n / k) * k;
			k /= 10;
			if (k == 1)
				ft_putchar(n + '0');
		}
	}
}

void	ft_putnbr(int n)
{
	int k;

	k = 1000000000;
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n == 0)
		ft_putchar('0');
	else
		thelse(n, k);
}
