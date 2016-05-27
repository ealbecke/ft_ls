/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permission.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 09:26:05 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/25 14:06:10 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_permission(struct stat	res_stat)
{
	if ((res_stat.st_mode & S_IFMT) && (res_stat.st_mode & S_IRUSR))
		return (1);
	return (0);
}

int				ft_check_perm(t_path *head)
{
	DIR		*dir;
	t_path	*current;

	current = head;
	dir = opendir(current->path);
	if (dir == NULL)
		return (0);
	else
		return (1);
}

void			ft_print_error_path(char *error, char *path)
{
	ft_putstr_fd(2, "ls: ", path, ": ", error, "\n", NULL);
}
