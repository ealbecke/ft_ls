/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:30:35 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/18 10:30:43 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, char *src, size_t n)
{
	int		c;
	size_t	d;
	int		f;

	d = 0;
	c = 0;
	f = 0;
	while (dest[c] != '\0')
		c++;
	while (src[f] != '\0' && n > d)
	{
		dest[c] = src[f];
		c++;
		d++;
		f++;
	}
	dest[c] = '\0';
	return (dest);
}
