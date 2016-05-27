/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 18:02:51 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/18 10:12:16 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				ft_check_arguments(int ac, char **av, t_args *ls)
{
	ls->args_options = ft_check_options(ac, av);
	if (ls->args_options != NULL && ft_strcmp(av[1], "-") != 0)
	{
		is_option_true(ls);
		is_option_match(ls->args_options);
	}
}

int					ft_count_letters(char *str)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '-')
			x++;
		i++;
	}
	return (x);
}

char				*ft_trim_option(char *str)
{
	char	*tmp;
	int		i;
	int		x;

	i = 0;
	x = 0;
	tmp = (char*)malloc(sizeof(char*) * ft_count_letters(str) + 1);
	while (str[i] != '\0')
	{
		if (str[i] != '-')
		{
			tmp[x] = str[i];
			x++;
		}
		i++;
	}
	tmp[x] = '\0';
	free(str);
	return (tmp);
}
