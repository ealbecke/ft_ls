/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:24:05 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/18 10:24:11 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*str;
	int		n;
	int		v;

	str = malloc(size);
	if (str == NULL)
		return (NULL);
	n = (int)size;
	v = 0;
	while (v < n)
	{
		str[v] = '\0';
		v++;
	}
	return ((void*)str);
}
