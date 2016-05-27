/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:32:37 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/18 10:32:47 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	int		n;

	n = (int)size;
	str = malloc(size);
	if (str == NULL)
		return (NULL);
	while (n < (int)size - 1)
	{
		str[n] = '\0';
		n++;
	}
	return (str);
}
