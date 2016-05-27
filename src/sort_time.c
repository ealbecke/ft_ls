/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 09:53:02 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/25 14:13:26 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		sort_time2(t_path **head, t_path *node,
		t_path *previous, t_path *current)
{
	if (current->res_stat.st_mtime < node->res_stat.st_mtime)
	{
		if (previous != NULL)
		{
			previous->next = node;
			node->next = current;
		}
		else
		{
			node->next = current;
			*head = node;
		}
		return (1);
	}
	return (0);
}

int		sort_time3(t_path **head, t_path *node, t_path *prev, t_path *current)
{
	if (current->res_stat.st_mtime == node->res_stat.st_mtime)
	{
		if (current->res_stat.st_mtimespec.tv_nsec
				< node->res_stat.st_mtimespec.tv_nsec)
		{
			if (prev != NULL)
			{
				prev->next = node;
				node->next = current;
			}
			else
			{
				node->next = current;
				*head = node;
			}
			return (1);
		}
		else if (current->res_stat.st_mtimespec.tv_nsec
				== node->res_stat.st_mtimespec.tv_nsec)
			return (sort_ascii_2(head, node, current, prev));
	}
	return (0);
}

void	sort_time(t_path **head, t_path *node)
{
	t_path		*previous;
	t_path		*current;

	previous = NULL;
	current = *head;
	if (*head == NULL)
		*head = node;
	else
	{
		while (current != NULL)
		{
			if (sort_time2(head, node, previous, current))
				return ;
			if (sort_time3(head, node, previous, current))
				return ;
			else if (current->next == NULL)
			{
				current->next = node;
				return ;
			}
			previous = current;
			current = current->next;
		}
	}
}
