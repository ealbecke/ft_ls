/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 12:45:26 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/18 10:12:26 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_count_path(int ac, char **av)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		if (av[i][0] != '-')
		{
			while (i != ac)
			{
				i++;
				j++;
			}
			return (j);
		}
		i++;
	}
	return (0);
}

void		ft_push_folder(char *str, t_path **head)
{
	t_path		*node;
	t_path		*current;
	t_path		*previous;

	current = *head;
	previous = NULL;
	if ((node = (t_path *)malloc(sizeof(t_path))) == NULL)
		exit(EXIT_FAILURE);
	node->path = ft_strdup(str);
	node->next = NULL;
	if (*head == NULL)
		*head = node;
	else
	{
		while (current != NULL)
		{
			if (current->next == NULL)
			{
				current->next = node;
				return ;
			}
			previous = current;
			current = current->next;
		}
	}
}

int			ft_check_path2(int ac, char **av, t_args *ls)
{
	int				x;
	int				i;
	struct stat		stat;

	i = 1;
	x = 0;
	while (av[i] && av[i][0] == '-')
	{
		if (ft_strcmp(av[i], "-") == 0)
		{
			while (i < ac)
			{
				x++;
				if (lstat(av[i], &stat) == 0)
					ins_sort_args(av[i], &ls->path, stat, ls);
				else
					ins_sort_no_file(av[i], &ls->no_exist_file, stat, ls);
				i++;
			}
		}
		i++;
	}
	ls->nb_path = x;
	return (i);
}

void		ft_check_path(int ac, char **av, t_args *ls)
{
	int				nb;
	int				i;
	struct stat		stat;

	i = 1;
	nb = ft_count_path(ac, av);
	if (av[i] && av[i][0] == '-')
		i = ft_check_path2(ac, av, ls);
	if (i < ac)
	{
		while (i < ac)
		{
			if (lstat(av[i], &stat) == 0)
				ins_sort_args(av[i], &ls->path, stat, ls);
			else
				ins_sort_args(av[i], &ls->no_exist_file, stat, ls);
			i++;
		}
	}
}

void		ft_sort_elem(t_args *ls)
{
	t_path		*current;
	struct stat	stat;

	current = ls->path;
	while (current != NULL)
	{
		if (lstat(current->path, &stat) == 0)
		{
			if (S_ISREG(stat.st_mode))
				ft_push_folder(current->path, &ls->just_file);
			else
				ft_push_folder(current->path, &ls->just_dir);
		}
		else
			ft_push_folder(current->path, &ls->no_exist_file);
		current = current->next;
	}
}
