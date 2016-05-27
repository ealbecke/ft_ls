/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:29:00 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/18 10:29:06 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		x;
	char	*copie;

	x = 0;
	i = ft_strlen(s);
	if ((copie = malloc(sizeof(char) * (i + 1))) == NULL)
		return (0);
	while (x != i)
	{
		copie[x] = s[x];
		x++;
	}
	copie[x] = '\0';
	return (copie);
}
