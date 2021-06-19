/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 18:09:50 by hyunlee           #+#    #+#             */
/*   Updated: 2021/06/19 18:09:51 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
