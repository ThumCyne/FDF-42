/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbentouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 03:50:40 by sbentouy          #+#    #+#             */
/*   Updated: 2021/11/19 03:50:41 by sbentouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <string.h>

# define BUTTONPRESS	2
# define DESTROYPRESS	17

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	char	***matrix;
	int		width;
	int		height;
	int		color;
	int		shift_x;
	int		shift_y;
	float	x1;
	float	y1;
	float	x_step;
	float	y_step;
	int		scale;
}	t_fdf;

int		get_next_line(int fd, char **line);
int		ft_wdcounter(char const *str, char c);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		ft_atoi(const char *str);
int		ft_atoi_base(const char *str, int str_base);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
int		ft_max(int a, int b);
int		ft_abs(int a);
char	*ft_strchr(const char *s, int c);
t_fdf	parser(char *file_name);
int		ft_destroywindown(void);
int		ft_presskey(int key, t_fdf *fdf);
void	draw(t_fdf *fdf);

#endif
