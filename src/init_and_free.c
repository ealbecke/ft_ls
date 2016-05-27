/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 10:21:12 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/20 10:06:48 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_initialize(t_path **d, t_path **fil)
{
	*fil = NULL;
	*d = NULL;
}

t_path		*init_node(char *str, struct stat sta, struct dirent *dir)
{
	t_path		*node;

	if ((node = (t_path *)malloc(sizeof(t_path))) == NULL)
		exit(EXIT_FAILURE);
	node->path = ft_strdup(str);
	node->r_dir.d_ino = dir->d_ino;
	node->r_dir.d_reclen = dir->d_reclen;
	node->r_dir.d_type = dir->d_type;
	ft_strcpy(node->r_dir.d_name, dir->d_name);
	node->res_stat = sta;
	node->next = NULL;
	return (node);
}

t_path		*init_node_args(char *str, struct stat sta)
{
	t_path		*node;

	if ((node = (t_path *)malloc(sizeof(t_path))) == NULL)
		exit(EXIT_FAILURE);
	node->path = ft_strdup(str);
	node->res_stat = sta;
	node->next = NULL;
	return (node);
}

void		init_option_and_linkedlist(t_args *ls)
{
	ls->path = (t_path *)malloc(sizeof(t_path));
	ls->directory = (t_path *)malloc(sizeof(t_path));
	ls->all_files = (t_path *)malloc(sizeof(t_path));
	ls->file = (t_path *)malloc(sizeof(t_path));
	ls->no_exist_file = (t_path *)malloc(sizeof(t_path));
	ls->just_file = (t_path *)malloc(sizeof(t_path));
	ls->just_dir = (t_path *)malloc(sizeof(t_path));
	ls->path = NULL;
	ls->directory = NULL;
	ls->all_files = NULL;
	ls->file = NULL;
	ls->no_exist_file = NULL;
	ls->just_file = NULL;
	ls->just_dir = NULL;
	ls->a = 0;
	ls->r = 0;
	ls->t = 0;
	ls->rmaj = 0;
	ls->l = 0;
	ls->nb_path = 0;
}

void		ft_init_max(int *max)
{
	max[0] = 0;
	max[1] = 0;
	max[2] = 0;
	max[3] = 0;
	max[4] = 0;
	max[5] = 0;
}
