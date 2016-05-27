/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:22:59 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/18 10:23:05 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if ((*alst)->next == NULL)
		ft_lstdelone(&(*alst), del);
	else
	{
		ft_lstdel(&(*alst)->next, del);
		ft_lstdelone(&(*alst), del);
	}
}
