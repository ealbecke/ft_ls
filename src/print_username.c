/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_username.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 13:46:20 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/17 16:47:21 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char				*get_user_name(uid_t user_id)
{
	struct passwd	*user_info;
	char			*user_name;

	user_info = getpwuid(user_id);
	if (user_info == NULL)
		user_name = ft_itoa(user_id);
	else
		user_name = user_info->pw_name;
	return (user_name);
}

char				*get_group_name(gid_t group_id)
{
	struct group	*group_info;
	char			*group_name;

	group_info = getgrgid(group_id);
	if (group_info == NULL)
		group_name = ft_itoa(group_id);
	else
		group_name = group_info->gr_name;
	return (group_name);
}

void				ft_check_fd(char *str, t_args *ls)
{
	if (ft_strcmp(str, "/dev/fd") == 0 && ls->rmaj)
		exit(EXIT_FAILURE);
}

void				ft_print_file(t_args *ls)
{
	t_path			*current;
	t_path			*tmp;
	struct stat		stat;

	current = ls->no_exist_file;
	while (current != NULL)
	{
		ft_putstr_fd(2, "ls: ", current->path,
				": No such file or directory\n", NULL);
		current = current->next;
	}
	tmp = ls->just_file;
	while (tmp != NULL)
	{
		if (lstat(tmp->path, &stat) == 0)
			tmp->res_stat = stat;
		tmp = tmp->next;
	}
	ft_print_list(ls->just_file, ls);
}

void				ins_sort_args(char *str, t_path **head,
		struct stat sta, t_args *ls)
{
	t_path			*node;

	node = init_node_args(str, sta);
	if (ls->r == 0 && ls->t == 0)
		sort_ascii_args(head, node);
	else if (ls->r == 0 && ls->t == 1)
		sort_time_args(head, node);
	else if (ls->r == 1 && ls->t == 1)
		sort_rev_time_args(head, node);
	else if (ls->r == 1 && ls->t == 0)
		sort_rev_ascii_path(head, node);
}
