/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_maj_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 10:29:59 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/16 10:31:07 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_print_major(struct stat res_stat, int *max)
{
	char	*major;
	char	*str_major;
	char	*str;

	major = ft_itoa(major(res_stat.st_rdev));
	str = malloc(ft_strlen(ft_itoa(max[3])) + 6);
	str[0] = '\0';
	ft_strcat(str, "  %");
	ft_strcat(str, ft_itoa(max[3] + 1));
	ft_strcat(str, "s");
	str_major = ft_strjoin(major, ",");
	free(major);
	ft_printf(str, str_major);
}

void			ft_print_minor(struct stat res_stat, int *max)
{
	char	*str_minor;
	char	*str;

	str_minor = ft_itoa(minor(res_stat.st_rdev));
	str = malloc(ft_strlen(ft_itoa(max[4])) + 4);
	str[0] = '\0';
	ft_strcat(str, " %");
	ft_strcat(str, ft_itoa(max[4]));
	ft_strcat(str, "s");
	ft_printf(str, str_minor);
}

void			ft_print_maj_min(struct stat res_stat, int *max)
{
	ft_print_major(res_stat, max);
	ft_print_minor(res_stat, max);
}
