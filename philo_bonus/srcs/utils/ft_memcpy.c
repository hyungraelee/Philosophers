/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 18:09:46 by hyunlee           #+#    #+#             */
/*   Updated: 2021/06/19 18:09:47 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*temp;
	const char	*s;

	if (dest == NULL && src == NULL)
		return (NULL);
	temp = dest;
	s = src;
	while (n--)
		*temp++ = *s++;
	return (dest);
}
