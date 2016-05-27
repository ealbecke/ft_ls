/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:29:35 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/18 10:29:39 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int n;

	n = 0;
	if (!s || !f)
		return ;
	while (s[n] != '\0')
	{
		f(n, s + n);
		n++;
	}
}