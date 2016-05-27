/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:30:25 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/18 10:30:30 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	n;

	n = 0;
	str = malloc(sizeof(char) * ft_strlen(s));
	if (str == NULL)
		return (NULL);
	while (s[n] != '\0')
	{
		str[n] = f(n, s[n]);
		n++;
	}
	return (str);
}
