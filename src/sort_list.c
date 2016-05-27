/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 13:36:38 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/23 17:32:10 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		sort_ascii_2(t_path **head, t_path *node, t_path *current, t_path *prev)
{
	if (ft_strcmp(current->path, node->path) > 0)
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
	else if (current->next == NULL)
	{
		current->next = node;
		return (1);
	}
	return (0);
}

void	sort_ascii(t_path **head, t_path *node)
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
			if (sort_ascii_2(head, node, current, previous) == 1)
				return ;
			else
				previous = current;
			current = current->next;
		}
	}
}

void	ins_sort(char *str, t_path **head, struct dirent *dir, t_args *ls)
{
	t_path		*node;
	struct stat	sta;

	if (lstat(str, &sta) != 0)
		ft_printf("%s\n", strerror(errno));
	node = init_node(str, sta, dir);
	if (ls->r == 0 && ls->t == 0)
		sort_ascii(head, node);
	else if (ls->r == 0 && ls->t == 1)
		sort_time(head, node);
	else if (ls->r == 1 && ls->t == 1)
		sort_rev_time(head, node);
	else if (ls->r == 1 && ls->t == 0)
		sort_rev_ascii(head, node);
}
