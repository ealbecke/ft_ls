/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:34:14 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/18 10:34:19 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	n;

	n = 0;
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (str);
	if (start >= ft_strlen(s))
	{
		str[0] = '\0';
		return (str);
	}
	if (!s)
		return (str);
	while (n < len)
	{
		str[n] = s[start + n];
		n++;
	}
	str[len] = '\0';
	return (str);
}
