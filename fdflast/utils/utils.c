/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbentouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 03:51:48 by sbentouy          #+#    #+#             */
/*   Updated: 2021/11/19 03:51:49 by sbentouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

char	*ft_strchr(const char *s, int c)
{
	while (*(char *)s != '\0' && *s != (char)c)
		s++;
	if (*(char *)s == (char)c)
		return ((char *)s);
	return (0);
}
