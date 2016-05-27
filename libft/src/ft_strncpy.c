/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:31:05 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/18 10:31:09 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	c;
	int		d;

	c = 0;
	d = 0;
	while (src[d] != '\0' && c < n)
	{
		dest[d] = src[d];
		d++;
		c++;
	}
	if (src[d] == '\0')
	{
		while (c < n)
		{
			dest[d] = '\0';
			d++;
			c++;
		}
	}
	return (dest);
}
