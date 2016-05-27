/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 15:56:12 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/20 14:34:12 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_list(t_path *list)
{
	t_path	*tmp;

	while (list)
	{
		free(list->path);
		tmp = list->next;
		free(list);
		list = tmp;
	}
}

void	free_linkedlist(t_args *ls)
{
	free_list(ls->path);
	free_list(ls->directory);
	free_list(ls->all_files);
	free_list(ls->file);
	free_list(ls->no_exist_file);
	free_list(ls->just_file);
}

int		ft_count_no_exist_file(t_path *head)
{
	int		nb_no_exist_file;
	t_path	*current;

	nb_no_exist_file = 0;
	current = head;
	while (current != NULL)
	{
		nb_no_exist_file++;
		current = current->next;
	}
	return (nb_no_exist_file);
}

int		ft_valid_path(int ac, char **av, t_args *ls)
{
	int		nb_path;
	int		nb_no_exist;

	nb_path = ft_count_path(ac, av);
	nb_no_exist = ft_count_no_exist_file(ls->no_exist_file);
	if ((nb_path > 0 && nb_path == nb_no_exist)
	|| (ls->nb_path > 0 && nb_no_exist > 0
		&& (ft_strcmp(ls->no_exist_file->path, "-") == 0)))
		return (1);
	else
		return (0);
}

int		main(int ac, char **av)
{
	t_args	*ls;

	ls = (t_args *)malloc(sizeof(t_args));
	init_option_and_linkedlist(ls);
	ft_check_arguments(ac, av, ls);
	ft_check_path(ac, av, ls);
	ft_sort_elem(ls);
	ft_print_file(ls);
	if (ft_valid_path(ac, av, ls))
		exit(EXIT_FAILURE);
	if ((ls->just_dir != NULL) ||
			((ls->just_dir == NULL) && (ls->just_file == NULL)))
	{
		ft_analyse_path(ls->just_dir, ls);
		ft_print_list(ls->file, ls);
	}
	free_linkedlist(ls);
	return (0);
}
