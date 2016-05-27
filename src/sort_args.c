/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 10:07:06 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/17 14:00:32 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		sort_rev_time_args2(t_path **head, t_path *node,
		t_path *previous, t_path *current)
{
	if (current->res_stat.st_mtime > node->res_stat.st_mtime)
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

void	sort_rev_time_args(t_path **head, t_path *node)
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
			if (sort_rev_time_args2(head, node, previous, current))
				return ;
			previous = current;
			current = current->next;
		}
	}
}

int		sort_rev_ascii_path2(t_path **head, t_path *node,
		t_path *previous, t_path *current)
{
	if (ft_strcmp(current->path, node->path) < 0)
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

void	sort_rev_ascii_path(t_path **head, t_path *node)
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
			if (sort_rev_ascii_path2(head, node, previous, current))
				return ;
			previous = current;
			current = current->next;
		}
	}
}

void	ins_sort_no_file(char *str, t_path **head, struct stat sta, t_args *ls)
{
	t_path		*node;

	node = init_node_args(str, sta);
	if (ls->r == 0 && ls->t == 0)
		sort_ascii_args(head, node);
}
