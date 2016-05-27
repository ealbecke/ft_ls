/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 09:47:36 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/25 13:49:48 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_print_type(mode_t st_mode)
{
	if (S_ISBLK(st_mode))
		ft_printf("b");
	else if (S_ISCHR(st_mode))
		ft_printf("c");
	else if (S_ISDIR(st_mode))
		ft_printf("d");
	else if (S_ISFIFO(st_mode))
		ft_printf("f");
	else if (S_ISLNK(st_mode))
		ft_printf("l");
	else if (S_ISREG(st_mode))
		ft_printf("-");
	else if (S_ISSOCK(st_mode))
		ft_printf("s");
	else
		ft_printf("PB");
}

void			ft_print_status_usr(mode_t st_mode)
{
	ft_printf("%s", (st_mode & S_IRUSR) ? "r" : "-");
	ft_printf("%s", (st_mode & S_IWUSR) ? "w" : "-");
	if (st_mode & S_ISUID && !(st_mode & S_IXUSR))
		ft_printf("S");
	else if (st_mode & S_ISUID && st_mode & S_IXUSR)
		ft_printf("s");
	else if (st_mode & S_IXUSR)
		ft_printf("x");
	else
		ft_printf("-");
}

void			ft_print_status_grp(mode_t st_mode)
{
	ft_printf("%s", (st_mode & S_IRGRP) ? "r" : "-");
	ft_printf("%s", (st_mode & S_IWGRP) ? "w" : "-");
	if (st_mode & S_ISGID && !(st_mode & S_IXGRP))
		ft_printf("S");
	else if (st_mode & S_ISGID && st_mode & S_IXGRP)
		ft_printf("s");
	else if (st_mode & S_IXGRP)
		ft_printf("x");
	else
		ft_printf("-");
}

void			ft_print_status_oth(mode_t st_mode)
{
	ft_printf("%s", (st_mode & S_IROTH) ? "r" : "-");
	ft_printf("%s", (st_mode & S_IWOTH) ? "w" : "-");
	if (st_mode & S_ISVTX && !(st_mode & S_IXOTH))
		ft_printf("T");
	else if (st_mode & S_ISVTX && st_mode & S_IXOTH)
		ft_printf("t");
	else if (st_mode & S_IXOTH)
		ft_printf("x");
	else
		ft_printf("-");
}

void			ft_print_status(mode_t st_mode)
{
	ft_print_status_usr(st_mode);
	ft_print_status_grp(st_mode);
	ft_print_status_oth(st_mode);
}
