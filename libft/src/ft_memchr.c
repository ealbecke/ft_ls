/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:24:31 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/18 10:24:36 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*str;
	size_t				i;

	i = 0;
	str = (unsigned const char*)s;
	while (n > i)
	{
		if (str[i] == (unsigned const char)c)
			return ((void*)(str + i));
		i++;
	}
	return (NULL);
}
