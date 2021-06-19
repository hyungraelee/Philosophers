/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 18:05:59 by hyunlee           #+#    #+#             */
/*   Updated: 2021/06/19 18:06:00 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return (0);
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
	if (fd == 2)
		return (-1);
	else
		return (1);
}
