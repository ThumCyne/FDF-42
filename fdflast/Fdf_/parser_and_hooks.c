/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_and_hooks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbentouy <sbentouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 03:50:20 by sbentouy          #+#    #+#             */
/*   Updated: 2021/11/19 04:28:32 by sbentouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	get_height(char *file_name)
{
	int		fd;
	char	*line;
	int		height;

	height = 0;
	fd = open(file_name, O_RDONLY, 0777);
	while (get_next_line(fd, &line) > 0)
	{
		height++;
		free (line);
	}
	if (line)
		free (line);
	close (fd);
	return (height);
}

int	get_width(char *file_name)
{
	int		fd;
	char	*line;
	int		width;

	width = 0;
	fd = open(file_name, O_RDONLY, 0777);
	get_next_line(fd, &line);
	if (line)
	{
		width = ft_wdcounter(line, ' ');
		free (line);
	}
	close (fd);
	return (width);
}

void	init_shift(t_fdf *fdf)
{
	fdf->shift_x = 0;
	fdf->shift_y = 0;
	fdf->scale = 20;
}

t_fdf	parser(char *file_name)
{
	t_fdf	fdf;
	int		i;
	int		fd;
	char	*line;

	init_shift(&fdf);
	fd = open(file_name, O_RDONLY, 0777);
	if (fd == -1)
	{
		perror("Error: ");
		exit (1);
	}
	fdf.height = get_height(file_name);
	fdf.width = get_width(file_name);
	fdf.matrix = malloc(sizeof(char **) * (fdf.height + 1));
	i = 0;
	while (i < fdf.height)
	{
		get_next_line(fd, &line);
		fdf.matrix[i++] = ft_split(line, ' ');
		free (line);
	}
	fdf.matrix[i] = NULL;
	return (fdf);
}

int	ft_presskey(int key, t_fdf *fdf)
{
	(void)fdf;
	if (key == 53)
		ft_destroywindown();
	return (0);
}
