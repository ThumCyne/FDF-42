/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbentouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 03:52:11 by sbentouy          #+#    #+#             */
/*   Updated: 2021/11/19 03:52:15 by sbentouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	slen;

	slen = len;
	while (len--)
		*(unsigned char *)b++ = (unsigned char)c;
	return (b - slen);
}
