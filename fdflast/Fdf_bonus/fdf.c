/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbentouy <sbentouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 03:50:13 by sbentouy          #+#    #+#             */
/*   Updated: 2021/11/19 04:20:23 by sbentouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	isometric(float *x, float *y, float z)
{
	*x = (*x - *y) * cos(0.7);
	*y = (*x + *y) * sin(0.7) - z;
}

void	rendring(float x, float y, t_fdf *fdf)
{
	int	max;

	max = ft_max(ft_abs(fdf->x_step), ft_abs(fdf->y_step));
	fdf->x_step /= max;
	fdf->y_step /= max;
	while ((int)(x - fdf->x1) || (int)(y - fdf->y1))
	{
		mlx_pixel_put(fdf->mlx, fdf->win, x + 850, y + 250, fdf->color);
		x += fdf->x_step;
		y += fdf->y_step;
	}
}

void	draw_line(float x, float y, t_fdf *fdf)
{
	int		z;
	int		z1;
	char	*color1;

	z = ft_atoi(fdf->matrix[(int)y][(int)x]);
	z1 = ft_atoi(fdf->matrix[(int)fdf->y1][(int)fdf->x1]);
	fdf->color = 16777215 - (z * (3000 * z));
	color1 = ft_strchr(fdf->matrix[(int)y][(int)x], ',');
	if (color1)
		fdf->color = ft_atoi_base(color1 + 1, 16);
	x *= fdf->scale;
	y *= fdf->scale;
	fdf->x1 *= fdf->scale;
	fdf->y1 *= fdf->scale;
	isometric(&x, &y, z);
	isometric(&fdf->x1, &fdf->y1, z1);
	x += fdf->shift_x;
	y += fdf->shift_y;
	fdf->x1 += fdf->shift_x;
	fdf->y1 += fdf->shift_y;
	fdf->x_step = fdf->x1 - x;
	fdf->y_step = fdf->y1 - y;
	rendring(x, y, fdf);
}

void	draw(t_fdf *fdf)
{
	int	y;
	int	x;

	y = -1;
	while (++y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			if (x < fdf->width - 1)
			{
				fdf->x1 = x + 1;
				fdf->y1 = y;
				draw_line(x, y, fdf);
			}
			if (y < fdf->height - 1)
			{
				fdf->x1 = x;
				fdf->y1 = y + 1;
				draw_line(x, y, fdf);
			}
			x++;
		}
	}
}

int	main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac != 2)
	{
		write(2, "Invalid arguments!\n", 19);
		exit(1);
	}	
	fdf = parser(av[1]);
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, 2000, 1200, "FDF");
	draw(&fdf);
	mlx_hook(fdf.win, BUTTONPRESS, 1, ft_presskey, &fdf);
	mlx_hook(fdf.win, DESTROYPRESS, 0,
		ft_destroywindown, NULL);
	mlx_loop(fdf.mlx);
	return (0);
}
