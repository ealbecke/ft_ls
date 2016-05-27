/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 10:18:55 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/17 10:29:17 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_list_recur(t_path *cur, t_args *ls, struct stat sta)
{
	if (ls->a)
	{
		if ((ft_strcmp(cur->r_dir.d_name, ".") != 0
					|| ft_strcmp(cur->r_dir.d_name, "..") != 0))
		{
			ft_printf("\n%s:\n", cur->path);
			if (ft_permission(sta) == 1 && S_ISDIR(sta.st_mode))
				ft_list_folder(cur->path, ls);
			else
				ft_putstr_fd(2, "ls: ", cur->r_dir.d_name,
						": Permission denied\n\n", NULL);
		}
	}
	else if (((cur->r_dir.d_name[0] != '.') || (ls->a)) && S_ISDIR(sta.st_mode))
	{
		if (cur->r_dir.d_name[0] != '.')
		{
			ft_printf(" \n%s:\n", cur->path);
			ft_permission(sta) == 1 && S_ISDIR(sta.st_mode) ?
				ft_list_folder(cur->path, ls) : ft_putstr_fd(2, "ls: ",
						cur->r_dir.d_name, ": Permission denied\n\n", NULL);
		}
	}
	if (ft_strcmp(cur->r_dir.d_name, "..") == 0 && is_empty(ls->all_files))
		ft_printf("\n");
}

void		reduce_use_recursive(struct stat stat, t_path *cur, t_args *ls)
{
	if ((stat.st_mode & S_IFMT) && (stat.st_mode & S_IRUSR))
	{
		if ((ft_strcmp(cur->r_dir.d_name, ".") == 0
					|| ft_strcmp(cur->r_dir.d_name, "..") == 0) && ls->a)
			ft_printf("");
		else
		{
			ft_list_recur(cur, ls, stat);
		}
	}
	else
		ft_putstr_fd(2, "\n", cur->path, ":\n", "ls: ", cur->r_dir.d_name,
				": Permission denied\n", NULL);
}

void		ft_use_recursive(t_args *ls)
{
	t_path			*current;
	struct stat		res_stat;

	current = ls->directory;
	if (current != NULL)
	{
		while (current != NULL)
		{
			if (lstat(current->path, &res_stat) == 0)
			{
				reduce_use_recursive(res_stat, current, ls);
				current = current->next;
			}
			else
			{
				if (ft_strcmp(current->path, "/dev/fd/3") == 0)
				{
					print_dev_fd(current->path);
				}
				else
					ft_putstr_fd(2, strerror(errno), "\n", NULL);
				current = current->next;
			}
		}
	}
}
