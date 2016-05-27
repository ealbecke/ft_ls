/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 12:44:33 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/25 15:08:08 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char				*ft_check_options(int ac, char **av)
{
	char	*str;
	int		i;

	i = 1;
	str = NULL;
	while (i < ac)
	{
		if (av[i][0] == '-')
		{
			str = (char*)malloc(sizeof(char*) * ft_strlen(av[i]) + 1);
			if (str == NULL)
				exit(EXIT_FAILURE);
			ft_strcpy(str, av[1]);
			i++;
			while (i < ac && av[i][0] == '-')
			{
				str = ft_strjoin(str, av[i]);
				i++;
			}
			return (ft_trim_option(str));
		}
		return (NULL);
	}
	return (NULL);
}

void				is_option_match(char *str)
{
	int		len;
	int		i;

	len = ft_strlen(str);
	i = 0;
	while (str[i])
	{
		if (str[i] != 'a' && str[i] != 'r' && str[i] != 't'
				&& str[i] != 'R' && str[i] != 'l' && str[i] != '1')
		{
			ft_putstr_fd(2, "ls: illegal option -- ", NULL);
			write(2, &str[i], 1);
			ft_putstr_fd(2, "\n", NULL);
			ft_putstr_fd(2, "Usage: ls [1Ralrt] [file ...]\n", NULL);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return ;
}

void				is_option_true(t_args *ls)
{
	int			i;

	i = 0;
	while (ls->args_options[i] != '\0')
	{
		if (ls->args_options[i] == 'a')
			ls->a = 1;
		else if (ls->args_options[i] == 'r')
			ls->r = 1;
		else if (ls->args_options[i] == 't')
			ls->t = 1;
		else if (ls->args_options[i] == 'R')
			ls->rmaj = 1;
		else if (ls->args_options[i] == 'l')
			ls->l = 1;
		else if (ls->args_options[i] == '1')
			ls->one = 1;
		i++;
	}
}
