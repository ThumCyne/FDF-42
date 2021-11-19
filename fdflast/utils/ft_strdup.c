/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbentouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 03:51:20 by sbentouy          #+#    #+#             */
/*   Updated: 2021/11/19 03:51:21 by sbentouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	size_t	len;

	len = ft_strlen(s1);
	ret = malloc(sizeof(char) * len + 1);
	if (!ret)
		return (NULL);
	ft_memcpy(ret, s1, len);
	ret[len] = 0;
	return (ret);
}
