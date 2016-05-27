/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_path2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 10:23:43 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/25 13:56:55 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_list_and_print_folder(t_args *ls)
{
	if (ls->l)
		ft_print_total(ls->all_files, ls);
	ft_print_list(ls->all_files, ls);
	if (ls->rmaj)
		ft_use_recursive(ls);
}

void		print_dev_fd(char *path)
{
	ft_putstr_fd(2, path,
		"\nls: 3: Not a directory\nls: 4: directory causes a cycle\n", NULL);
}

void		ft_anal_print_perm(char *path, t_args *ls)
{
	if (ft_count_no_exist_file(ls->just_dir) > 1)
		ft_printf("\n%s:\n", path);
	if (ft_strcmp(&path[ft_strlen(path) - 1], "/") == 0)
		ft_printf("ls: : Permission denied\n");
	else
		ft_printf("ls: %s: Permission denied\n", path);
}

int			is_empty(t_path *head)
{
	t_path		*current;
	int			i;

	i = 0;
	current = head;
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	if (i == 2)
		return (1);
	else
		return (0);
}

int			ft_count_dir(t_path *head)
{
	t_path	*current;
	int		i;

	i = 0;
	current = head;
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
}
