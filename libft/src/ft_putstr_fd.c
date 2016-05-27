/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:27:32 by ealbecke          #+#    #+#             */
/*   Updated: 2016/05/18 10:27:37 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(int fd, ...)
{
	int		i;
	char	*str;
	va_list	ap;

	va_start(ap, fd);
	str = va_arg(ap, char*);
	while (str != NULL)
	{
		i = 0;
		while (str[i] != '\0')
		{
			write(fd, &(str[i]), 1);
			i++;
		}
		str = va_arg(ap, char*);
	}
	va_end(ap);
}
