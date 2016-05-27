/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:30:11 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/18 10:30:16 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		n;

	str = malloc(sizeof(char) * ft_strlen(s));
	if (str == NULL)
		return (NULL);
	n = 0;
	while (s[n] != '\0')
	{
		str[n] = f(s[n]);
		n++;
	}
	return (str);
}
