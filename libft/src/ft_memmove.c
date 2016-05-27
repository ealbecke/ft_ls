/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:25:13 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/18 10:25:18 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*tmp;

	if (dst == NULL || src == NULL)
		return (NULL);
	tmp = malloc(n * sizeof(char));
	ft_memcpy(tmp, src, n);
	ft_memcpy(dst, tmp, n);
	free(tmp);
	return (dst);
}
