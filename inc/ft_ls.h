/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:36:20 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/25 15:29:33 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft.h"
# include <stdlib.h>
# include <sys/stat.h>
# include <dirent.h>
# include <errno.h>
# include <string.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <sys/types.h>
# include <sys/xattr.h>

typedef struct		s_path
{
	char			*path;
	struct dirent	r_dir;
	struct stat		res_stat;
	struct s_path	*next;
	struct passwd	*getpuid;
}					t_path;

typedef struct		s_args
{
	char			a;
	char			r;
	char			t;
	char			rmaj;
	char			l;
	char			one;
	char			*args_options;
	int				nb_path;
	t_path			*path;
	t_path			*directory;
	t_path			*all_files;
	t_path			*file;
	t_path			*no_exist_file;
	t_path			*just_file;
	t_path			*just_dir;
}					t_args;

void				free_list(t_path *list);
void				ft_anal_print_perm(char *path, t_args *ls);
void				ft_analyse_path(t_path *head, t_args *ls);
void				ft_browse_dir(char *str, t_args *ls);
void				ft_check_arguments(int ac, char **av, t_args *ls);
int					ft_count_path(int ac, char **av);
void				ft_count_print(t_path *head, int *max, t_args *ls);
int					ft_count_dir(t_path *head);
char				*ft_check_options(int ac, char **av);
void				ft_check_path(int ac, char **av, t_args *ls);
void				ft_check_fd(char *str, t_args *ls);
int					ft_check_perm(t_path *head);
int					ft_count_dir(t_path *head);
int					ft_count_letters(char *str);
int					ft_count_no_exist_file(t_path *head);
char				*ft_trim_option(char *str);
void				ft_extended_attr(struct stat *res_stat, t_path *current);
void				ft_init_max(int *max);
void				ft_initialize(t_path **d, t_path **fil);
int					is_empty(t_path *head);
void				ft_list_and_print_folder(t_args *ls);
void				ft_list_folder(char *str, t_args *ls);
int					ft_permission(struct stat res_stat);
char				*ft_print_date(time_t mtime);
void				ft_print_error_path(char *error, char *path);
void				ft_print_file(t_args *ls);
void				ft_print_link(t_path *current, t_args *ls);
void				ft_print_list(t_path *head, t_args *ls);
void				ft_print_maj_min(struct stat res_stat, int *max);
void				ft_print_status(mode_t st_mode);
void				ft_print_total(t_path *head, t_args *ls);
void				ft_print_type(mode_t st_mode);
void				ft_push_folder(char *str, t_path **head);
void				ft_recurs_2(t_args *ls);
void				ft_sort_elem(t_args *ls);
void				ft_use_l(struct stat *res_stat, t_args *ls, int *max);
void				ft_use_recursive(t_args *ls);
char				*get_user_name(uid_t user_id);
char				*get_group_name(gid_t group_id);
t_path				*init_node(char *str, struct stat sta, struct dirent *dir);
t_path				*init_node_args(char *str, struct stat sta);
void				init_option_and_linkedlist(t_args *ls);
void				ins_sort(char *str, t_path **head,
		struct dirent *dir, t_args *ls);
void				ins_sort_args(char *str, t_path **head,
		struct stat sta, t_args *ls);
void				ins_sort_no_file(char *str, t_path **head,
		struct stat sta, t_args *ls);
void				ins_sort_args(char *str, t_path **head,
		struct stat sta, t_args *ls);
void				is_option_match(char *str);
void				is_option_true(t_args *ls);
void				sort_ascii_args(t_path **head, t_path *node);
void				sort_rev_ascii(t_path **head, t_path *node);
int					sort_ascii_2(t_path **head, t_path *node,
		t_path *current, t_path *prev);
void				sort_rev_time_args(t_path **head, t_path *node);
void				sort_rev_ascii_path(t_path **head, t_path *node);
int					sort_rev_ascii2(t_path **head, t_path *node,
		t_path *current, t_path *previous);
void				sort_rev_time(t_path **head, t_path *node);
void				sort_time(t_path **head, t_path *node);
void				sort_time_args(t_path **head, t_path *node);
void				print_dev_fd(char *path);

#endif
