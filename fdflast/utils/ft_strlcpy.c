/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbentouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 03:52:24 by sbentouy          #+#    #+#             */
/*   Updated: 2021/11/19 03:52:25 by sbentouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = ft_strlen(src);
	if (size > 0)
	{
		while (--size && *src != 0)
		{
			ft_memset(dst, *(char *)src, 1);
			dst++;
			src++;
		}
		*dst = 0;
	}
	return (len);
}
