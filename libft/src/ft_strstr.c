/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:33:46 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/18 10:34:08 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int x;
	int y;

	x = 0;
	if (s2[0] == '\0')
		return ((char*)s1);
	while (s1[x] != '\0')
	{
		y = 0;
		while (s2[y] == s1[x + y])
		{
			if (s2[y + 1] == '\0')
				return ((char*)(s1 + x));
			y++;
		}
		x++;
	}
	return (NULL);
}
