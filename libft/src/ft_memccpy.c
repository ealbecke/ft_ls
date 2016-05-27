/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:24:18 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/18 10:24:25 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*curdst;
	unsigned char	*cursrc;
	int				i;

	curdst = (unsigned char *)dst;
	cursrc = (unsigned char *)src;
	i = 0;
	while (i < (int)n)
	{
		*curdst = *cursrc;
		if (*cursrc == (unsigned char)c)
			return (curdst + 1);
		i++;
		curdst++;
		cursrc++;
	}
	return (NULL);
}
