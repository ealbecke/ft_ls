/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:17:39 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/18 10:17:46 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int n;
	int signe;
	int result;

	n = 0;
	result = 0;
	signe = 1;
	while (nptr[n] == ' ' || nptr[n] == '\n' || nptr[n] == '\t'
			|| nptr[n] == '\v' || nptr[n] == '\f' || nptr[n] == '\r')
		n++;
	if (nptr[n] == '-')
	{
		signe = -1;
		n++;
	}
	else if (nptr[n] == '+')
		n++;
	while (nptr[n] > 47 && nptr[n] < 58)
	{
		result = result * 10 + (nptr[n] - 48);
		n++;
	}
	return (result * signe);
}
