/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:34:27 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/18 10:34:31 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		x;
	int		y;
	char	*str;

	x = 0;
	y = ft_strlen(s) - 1;
	if (s == NULL)
		return (NULL);
	while (s[x] == ' ' || s[x] == '\t' || s[x] == '\n')
	{
		x++;
	}
	while ((s[y] == ' ' || s[y] == '\t' || s[y] == '\n') && y > x)
	{
		y--;
	}
	str = ft_strsub(s, x, y - x + 1);
	return (str);
}
