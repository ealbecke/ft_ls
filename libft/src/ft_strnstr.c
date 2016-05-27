/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:32:52 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/18 10:32:59 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int x;
	unsigned int y;

	x = 0;
	if (s2[0] == '\0')
		return ((char*)s1);
	while (s1[x] != '\0' && (size_t)x < n)
	{
		y = 0;
		while (s2[y] == s1[x + y] && (size_t)(x + y) < n)
		{
			if (s2[y + 1] == '\0')
				return ((char*)(s1 + x));
			y++;
		}
		x++;
	}
	return (NULL);
}
