/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_use_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 10:35:02 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/17 16:39:57 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_print_name(uid_t st_uid, gid_t st_gid, int *max)
{
	char			*str;

	str = malloc(ft_strlen(ft_itoa(max[1])) + 5);
	str[0] = '\0';
	ft_strcat(str, " %-");
	ft_strcat(str, ft_itoa(max[1]));
	ft_strcat(str, "s");
	ft_printf(str, get_user_name(st_uid));
	free(str);
	str = malloc(max[2] + 5);
	str[0] = '\0';
	ft_strcat(str, "  %-");
	ft_strcat(str, ft_itoa(max[2]));
	ft_strcat(str, "s");
	ft_printf(str, get_group_name(st_gid));
	free(str);
}

char			*ft_print_date(time_t mtime)
{
	char			*time_string;
	char			*time_month;
	char			*time_year;

	time_month = NULL;
	time_year = NULL;
	time_string = NULL;
	if ((mtime > (time(0) - 15778458))
			&& (mtime < (time(0) + 15778458)))
		time_string = ft_strsub(ctime(&mtime), 4, 12);
	else
	{
		time_month = ft_strsub(ctime(&mtime), 4, 7);
		time_year = ft_strsub(ctime(&mtime), 19, 5);
		time_string = ft_strjoin(time_month, time_year);
	}
	free(time_month);
	free(time_year);
	return (time_string);
}

void			ft_use_l2(struct stat *res_stat, char **str, int *max)
{
	free(*str);
	*str = malloc(ft_strlen(ft_itoa(max[3] + max[4])) + 5);
	(*str)[0] = '\0';
	ft_strcat(*str, "  %");
	ft_strcat(*str, ft_itoa(max[3] + max[4]));
	ft_strcat(*str, "D");
	ft_printf(*str, res_stat->st_size);
}

void			ft_use_l(struct stat *res_stat, t_args *ls, int *max)
{
	char *str;

	str = malloc(ft_strlen(ft_itoa(max[0])) + 5);
	str[0] = '\0';
	ft_strcat(str, "  %");
	ft_strcat(str, ft_itoa(max[0]));
	ft_strcat(str, "d");
	ft_print_type(res_stat->st_mode);
	ft_print_status(res_stat->st_mode);
	ft_printf(str, res_stat->st_nlink);
	ft_print_name(res_stat->st_uid, res_stat->st_gid, max);
	if (ls->path != NULL && (S_ISBLK(res_stat->st_mode)
				|| S_ISCHR(res_stat->st_mode)))
		ft_print_maj_min(*res_stat, max);
	else
		ft_use_l2(res_stat, &str, max);
	free(str);
	str = malloc(ft_strlen(ft_itoa(max[5])) + 5);
	str[0] = '\0';
	ft_strcat(str, " %");
	ft_strcat(str, ft_itoa(max[5]));
	ft_strcat(str, "s ");
	ft_printf(str, ft_print_date(res_stat->st_mtime));
}
