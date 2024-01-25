/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosilves <nosilves@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:08:22 by nosilves          #+#    #+#             */
/*   Updated: 2023/12/26 19:14:41 by nosilves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx/mlx.h"

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	the_color1(t_mlx *v)
{
	if (v->count < 1)
		my_mlx_pixel_put(v, v->col, v->row, BLACK);
	else if (v->count % 10 == 0)
		my_mlx_pixel_put(v, v->col, v->row, MIDNIGHT_BLUE);
	else if (v->count % 10 == 1)
		my_mlx_pixel_put(v, v->col, v->row, NAVY);
	else if (v->count % 10 == 2)
		my_mlx_pixel_put(v, v->col, v->row, DARK_BLUE);
	else if (v->count % 10 == 3)
		my_mlx_pixel_put(v, v->col, v->row, MEDIUM_BLUE);
	else if (v->count % 10 == 4)
		my_mlx_pixel_put(v, v->col, v->row, BLUE);
	else if (v->count % 10 == 5)
		my_mlx_pixel_put(v, v->col, v->row, ROYAL_BLUE);
	else if (v->count % 10 == 6)
		my_mlx_pixel_put(v, v->col, v->row, STEEL_BLUE);
	else if (v->count % 10 == 7)
		my_mlx_pixel_put(v, v->col, v->row, CORNFLOWER_BLUE);
	else if (v->count % 10 == 8)
		my_mlx_pixel_put(v, v->col, v->row, SKYBLU);
	else if (v->count % 10 == 9)
		my_mlx_pixel_put(v, v->col, v->row, LIGHT_BLUE);
}

void	the_color2(t_mlx *v)
{
	if (v->count < 1)
	{
		my_mlx_pixel_put(v, v->col, v->row, BLACK);
	}
	else if (v->count % 5 == 1)
	{
		my_mlx_pixel_put(v, v->col, v->row, YELLOW);
	}
	else if (v->count % 5 == 2)
	{
		my_mlx_pixel_put(v, v->col, v->row, ORANGE);
	}
	else if (v->count % 5 == 3)
	{
		my_mlx_pixel_put(v, v->col, v->row, PURPLE);
	}
	else if (v->count % 5 == 4)
	{
		my_mlx_pixel_put(v, v->col, v->row, CYAN);
	}
	else if (v->count % 5 == 0)
	{
		my_mlx_pixel_put(v, v->col, v->row, LIME);
	}
}

void	the_color3(t_mlx *v)
{
	if (v->count < 1)
	{
		my_mlx_pixel_put(v, v->col, v->row, BLACK);
	}
	else if (v->count % 5 == 1)
	{
		my_mlx_pixel_put(v, v->col, v->row, SILVER);
	}
	else if (v->count % 5 == 2)
	{
		my_mlx_pixel_put(v, v->col, v->row, TEAL);
	}
	else if (v->count % 5 == 3)
	{
		my_mlx_pixel_put(v, v->col, v->row, INDIGO);
	}
	else if (v->count % 5 == 4)
	{
		my_mlx_pixel_put(v, v->col, v->row, NAVY);
	}
	else if (v->count % 5 == 0)
	{
		my_mlx_pixel_put(v, v->col, v->row, OLIVE);
	}
}

void	color_iter(t_mlx *v)
{
	if (v->color_change % 3 == 1)
		the_color1(v);
	else if (v->color_change % 3 == 2)
		the_color2(v);
	else
		the_color3(v);
}
