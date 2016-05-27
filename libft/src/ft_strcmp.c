/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:28:25 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/18 10:28:30 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int c;

	c = 0;
	while (s1[c] != '\0' && s2[c] != '\0')
	{
		if (s1[c] - s2[c] != 0)
			return ((int)((unsigned char)s1[c] - (unsigned char)s2[c]));
		c++;
	}
	return ((int)((unsigned char)s1[c] - (unsigned char)s2[c]));
}
