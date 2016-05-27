/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_revers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 09:58:41 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/25 13:53:01 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		sort_rev_time2(t_path **head, t_path *node,
		t_path *current, t_path *previous)
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
	return (0);
}

int		sort_rev_time3(t_path **head, t_path *node, t_path *prev, t_path *curre)
{
	if (curre->res_stat.st_mtime == node->res_stat.st_mtime)
	{
		if (curre->res_stat.st_mtimespec.tv_nsec
				> node->res_stat.st_mtimespec.tv_nsec)
		{
			if (prev != NULL)
			{
				prev->next = node;
				node->next = curre;
			}
			else
			{
				node->next = curre;
				*head = node;
			}
			return (1);
		}
		else if (curre->res_stat.st_mtimespec.tv_nsec
				== node->res_stat.st_mtimespec.tv_nsec)
			return (sort_rev_ascii2(head, node, curre, prev));
	}
	return (0);
}

void	sort_rev_time(t_path **head, t_path *node)
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
			if (sort_rev_time2(head, node, current, previous))
				return ;
			if (sort_rev_time3(head, node, previous, current))
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

int		sort_rev_ascii2(t_path **head, t_path *node,
		t_path *current, t_path *previous)
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

void	sort_rev_ascii(t_path **head, t_path *node)
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
			if (sort_rev_ascii2(head, node, current, previous))
				return ;
			previous = current;
			current = current->next;
		}
	}
}
