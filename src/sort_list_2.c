/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 14:59:08 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/18 10:14:09 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		sort_ascii_argc2(t_path *current,
		t_path *node, t_path *previous, t_path **head)
{
	if (ft_strcmp(current->path, node->path) > 0)
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
	else if (current->next == NULL)
	{
		current->next = node;
		return (1);
	}
	return (0);
}

void	sort_ascii_args(t_path **head, t_path *node)
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
			if (sort_ascii_argc2(current, node, previous, head))
				return ;
			previous = current;
			current = current->next;
		}
	}
}

int		sort_time_args2(t_path **head, t_path *node,
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

int		sort_time_args3(t_path **head, t_path *node,
		t_path *previous, t_path *current)
{
	if (current->res_stat.st_mtime == node->res_stat.st_mtime)
	{
		if (ft_strcmp(current->path, node->path) > 0)
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
		else if (current->next == NULL)
		{
			current->next = node;
			return (1);
		}
	}
	return (0);
}

void	sort_time_args(t_path **head, t_path *node)
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
			if (sort_time_args2(head, node, previous, current))
				return ;
			if (sort_time_args3(head, node, previous, current))
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
