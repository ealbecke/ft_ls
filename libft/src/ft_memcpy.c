/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:24:53 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/18 10:24:58 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*cur1;
	unsigned char	*curdent;
	int				i;

	i = 0;
	while (i < (int)n)
	{
		cur1 = (unsigned char *)dst + i;
		curdent = (unsigned char *)src + i;
		*cur1 = *curdent;
		i++;
	}
	return (dst);
}
