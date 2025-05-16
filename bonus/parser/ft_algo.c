/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:30:18 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/16 11:34:15 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_cell_pixels(t_game_data *data, t_cell *cell)
{
	int	j;

	cell->i = 0;
	while (cell->i < cell->size)
	{
		j = 0;
		while (j < cell->size)
		{
			put_pixel_to_mlx(data, \
				cell->offset_x + cell->x * cell->size + cell->i,
				cell->offset_y + cell->y * cell->size + j, cell->color);
			j++;
		}
		cell->i++;
	}
}

static void	init_line_params(t_point start, t_point end, t_line *line)
{
	line->dx = (int)fabs(end.x_p - start.x_p);
	line->dy = -(int)fabs(end.y_p - start.y_p);
	line->err = line->dx + line->dy;
	if (start.x_p < end.x_p)
		line->sx = 1;
	else
		line->sx = -1;
	if (start.y_p < end.y_p)
		line->sy = 1;
	else
		line->sy = -1;
}

void	draw_line(t_game_data *data, t_point start, t_point end, int color)
{
	t_line	line;
	int		e2;

	init_line_params(start, end, &line);
	while (1)
	{
		put_pixel_to_mlx(data, (int)start.x_p, (int)start.y_p, color);
		if (start.x_p == end.x_p && start.y_p == end.y_p)
			break ;
		e2 = 2 * line.err;
		if (e2 >= line.dy)
		{
			line.err += line.dy;
			start.x_p += line.sx;
		}
		if (e2 <= line.dx)
		{
			line.err += line.dx;
			start.y_p += line.sy;
		}
	}
}
