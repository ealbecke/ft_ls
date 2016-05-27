/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:28:14 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/18 10:28:19 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int q;

	q = 0;
	if (s == NULL)
		return ;
	while (s[q] != '\0')
	{
		s[q] = '\0';
		q++;
	}
}