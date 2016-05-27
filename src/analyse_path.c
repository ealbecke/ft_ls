/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 11:36:16 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/25 14:06:16 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		red_lis(char *str, struct dirent *r_dir, t_args *ls)
{
	char			*complete_path;
	struct stat		st;

	complete_path = NULL;
	complete_path = ft_strjoin(ft_strjoin(str, "/"), r_dir->d_name);
	if (lstat(complete_path, &st) == 0)
	{
		ins_sort(complete_path, &ls->all_files, r_dir, ls);
		if ((st.st_mode & S_IFMT) & S_IFDIR)
		{
			if ((ft_strcmp(r_dir->d_name, ".") != 0)
					|| (ft_strcmp(r_dir->d_name, "..") != 0))
				ins_sort(complete_path, &ls->directory, r_dir, ls);
		}
	}
	else
		ft_putstr_fd(2, strerror(errno), "\n", NULL);
	free(complete_path);
}

void		ft_list_folder(char *str, t_args *ls)
{
	DIR				*dir;
	struct dirent	*res_dir;

	ft_initialize(&ls->directory, &ls->all_files);
	dir = opendir(str);
	if (dir == NULL)
		ft_putstr_fd(2, "ls: ", ft_strrchr(str, '/') + 1,
				": ", strerror(errno), "\n", NULL);
	else
	{
		while ((res_dir = readdir(dir)) != NULL && dir != NULL)
			red_lis(str, res_dir, ls);
		closedir(dir);
		ft_list_and_print_folder(ls);
		ft_check_fd(str, ls);
		free(res_dir);
	}
}

void		ft_folder_is_link(t_path *path, struct stat st_result, t_args *ls)
{
	char		*linkname;
	int			max[6];
	ssize_t		r;

	ft_init_max(max);
	linkname = NULL;
	if (ls->l == 0)
		ft_list_folder(path->path, ls);
	else if (ls->l)
	{
		ft_count_print(path, max, ls);
		ft_use_l(&st_result, ls, max);
		linkname = ft_memalloc(sizeof(st_result));
		r = readlink(path->path, linkname, sizeof(st_result));
		ft_printf(" %s -> %s\n", path->path, linkname);
		free(linkname);
	}
}

void		reduce_analyse_path(t_args *ls, struct stat st, t_path *head)
{
	if (ls->a == 0)
	{
		if ((st.st_mode & S_IFMT) && (st.st_mode & S_IRUSR))
			ft_list_folder(head->path, ls);
		else
		{
			ft_putstr_fd(2, "ls: ", ft_strrchr(head->path, '/') + 1,
					": Permission denied\n", NULL);
		}
	}
	else if (ls->a == 1)
	{
		if ((st.st_mode & S_IFMT) && (st.st_mode & S_IRUSR))
		{
			ft_list_folder(head->path, ls);
		}
		else
			ft_putstr_fd(2, "ls: ", ft_strrchr(head->path, '/') + 1,
		": Permission denied\n", NULL);
	}
}

void		ft_analyse_path(t_path *head, t_args *ls)
{
	struct stat		st_res;

	if (head == NULL)
		ft_list_folder(".", ls);
	while (head != NULL)
	{
		if (ft_check_perm(head))
		{
			if (ft_count_dir(ls->just_dir) > 1)
				ft_printf("\n%s:\n", head->path);
			if (lstat(head->path, &st_res) == 0)
			{
				if (S_ISLNK(st_res.st_mode))
					ft_folder_is_link(head, st_res, ls);
				else if ((st_res.st_mode & S_IFMT) & S_IFDIR)
					reduce_analyse_path(ls, st_res, head);
			}
			else
				ft_print_error_path(strerror(errno), head->path);
		}
		else
			ft_anal_print_perm(head->path, ls);
		head = head->next;
	}
	ft_print_list(head, ls);
}
