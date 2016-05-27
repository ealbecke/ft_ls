/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:29:44 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/18 10:29:49 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		x;
	int		y;
	char	*str;

	x = 0;
	y = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[x])
	{
		str[x] = s1[x];
		x++;
	}
	while (s2[y])
	{
		str[x + y] = s2[y];
		y++;
	}
	str[x + y] = '\0';
	return (str);
}
