/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 15:29:08 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/23 14:02:54 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_print_total(t_path *head, t_args *ls)
{
	t_path	*current;
	int		total;

	current = head;
	total = 0;
	while (current)
	{
		if (ls->a && ls->l)
			total = total + current->res_stat.st_blocks;
		else if (ls->l)
		{
			if (current->r_dir.d_name[0] != '.')
				total = total + current->res_stat.st_blocks;
		}
		current = current->next;
	}
	if ((ls->a == 0) && (ft_count_dir(ls->all_files) == 2))
		return ;
	else
		ft_printf("total %d\n", total);
}

void			ft_print_link(t_path *current, t_args *ls)
{
	char			*linkname;
	ssize_t			r;

	linkname = NULL;
	if (S_ISLNK(current->res_stat.st_mode) && ls->l == 1)
	{
		linkname = ft_memalloc(sizeof(current->res_stat));
		r = readlink(current->path, linkname, sizeof(current->res_stat));
		ft_printf("%s -> %s\n", current->r_dir.d_name, linkname);
		free(linkname);
	}
	else
	{
		if (ft_strcmp(&current->r_dir.d_name[0], "") != 0)
			ft_printf("%s\n", current->r_dir.d_name);
		else
			ft_printf("%s\n", current->path);
	}
}

void			ft_count_print(t_path *head, int *max, t_args *ls)
{
	max[0] < (int)ft_strlen(ft_itoa(head->res_stat.st_nlink)) ?
		max[0] = ft_strlen(ft_itoa(head->res_stat.st_nlink)) : 0;
	max[1] < (int)(ft_strlen(get_user_name(head->res_stat.st_uid))) ?
		max[1] = (int)(ft_strlen(get_user_name(head->res_stat.st_uid))) : 0;
	max[2] < (int)(ft_strlen(get_group_name(head->res_stat.st_gid))) ?
		max[2] = (int)(ft_strlen(get_group_name(head->res_stat.st_gid))) : 0;
	if (ls->path != NULL && (S_ISBLK(head->res_stat.st_mode)
				|| S_ISCHR(head->res_stat.st_mode)))
	{
		max[4] < (int)ft_strlen(ft_itoa(minor(head->res_stat.st_rdev))) ?
			max[4] = ft_strlen(ft_itoa(minor(head->res_stat.st_rdev))) : 0;
		max[3] < (int)ft_strlen(ft_itoa(major(head->res_stat.st_rdev))) ?
			max[3] = ft_strlen(ft_itoa(major(head->res_stat.st_rdev))) : 0;
	}
	else
		max[3] < (int)(ft_strlen(ft_itoa_long(head->res_stat.st_size))) ?
			max[3] = (int)(ft_strlen(ft_itoa_long(head->res_stat.st_size))) : 0;
	max[5] < (int)ft_strlen(ft_print_date(head->res_stat.st_mtime)) ?
		max[5] = ft_strlen(ft_print_date(head->res_stat.st_mtime)) : 0;
}

void			ft_print_list2(t_path *head, t_args *ls, int *max)
{
	if (head->r_dir.d_name[0] != '.' || (ls->a == 1))
		ft_count_print(head, max, ls);
}

void			ft_print_list(t_path *head, t_args *ls)
{
	t_path		*curre;
	char		*str;
	int			max[6];

	curre = head;
	str = NULL;
	ft_init_max(max);
	while (head != NULL)
	{
		ft_print_list2(head, ls, max);
		head = head->next;
	}
	max[3]--;
	while (curre != NULL)
	{
		if (curre->r_dir.d_ino && curre->r_dir.d_name[0] == '.' && (ls->a == 0))
			ft_printf("");
		else
		{
			if (ls->l == 1)
				ft_use_l(&curre->res_stat, ls, max);
			ft_print_link(curre, ls);
		}
		curre = curre->next;
	}
}
