/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosilves <nosilves@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:48:51 by nosilves          #+#    #+#             */
/*   Updated: 2023/12/04 20:00:47 by nosilves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx/mlx.h"

void	julia(t_mlx *v)
{
	mlx_clear_window(v->mlx, v->mlx_win);
	while (v->row < v->height)
	{
		v->col = 0;
		while (v->col < v->width)
		{
			v->count = 0;
			v->z.r = (((double)v->col + v->rmove)
					/ (double)v->width * (v->x_max - v->x_min) + v->x_min);
			v->z.i = (((double)v->row + v->imove)
					/ (double)v->height * (v->y_max - v->y_min) + v->y_min);
			while ((v->count < v->iter)
				&& ((v->z.r * v->z.r) + (v->z.i * v->z.i) <= 4.0f))
			{
				v->temp = (v->z.r * v->z.r) - (v->z.i * v->z.i) + v->c.r;
				v->z.i = (2 * v->z.r * v->z.i) + v->c.i;
				v->z.r = v->temp;
				v->count++;
			}
			color_iter(v);
			v->col++;
		}
		v->row++;
	}
	mlx_put_image_to_window(v->mlx, v->mlx_win, v->img, 0, 0);
}

void	fract_help(t_mlx *v)
{
	v->c.r = (((double)v->col + v->rmove)
			/ (double)v->width * (v->x_max - v->x_min) + v->x_min);
	v->count = 0;
	v->z.r = 0;
	v->z.i = 0;
}

void	mandelbrot(t_mlx *v)
{
	mlx_clear_window(v->mlx, v->mlx_win);
	while (v->row < v->height)
	{
		v->col = 0;
		v->c.i = (((double)v->row + v->imove)
				/ (double)v->height * (v->y_max - v->y_min) + v->y_min);
		while (v->col < v->width)
		{
			fract_help(v);
			while ((v->count < v->iter)
				&& ((v->z.r * v->z.r) + (v->z.i * v->z.i) <= 4.0f))
			{
				v->temp = (v->z.r * v->z.r) - (v->z.i * v->z.i) + v->c.r;
				v->z.i = (2 * v->z.r * v->z.i) + v->c.i;
				v->z.r = v->temp;
				v->count++;
			}
			color_iter(v);
			v->col++;
		}
		v->row++;
	}
	mlx_put_image_to_window(v->mlx, v->mlx_win, v->img, 0, 0);
}

void	tricorn(t_mlx *v)
{
	mlx_clear_window(v->mlx, v->mlx_win);
	while (v->row < v->height)
	{
		v->col = 0;
		v->c.i = (((double)v->row + v->imove)
				/ (double)v->height * (v->y_max - v->y_min) + v->y_min);
		while (v->col < v->width)
		{
			fract_help(v);
			while ((v->count < v->iter)
				&& ((v->z.r * v->z.r) + (v->z.i * v->z.i) <= 4.0f))
			{
				v->temp = (v->z.r * v->z.r) - (v->z.i * v->z.i) + v->c.r;
				v->z.i = (-2 * v->z.r * v->z.i) + v->c.i;
				v->z.r = v->temp;
				v->count++;
			}
			color_iter(v);
			v->col++;
		}
		v->row++;
	}
	mlx_put_image_to_window(v->mlx, v->mlx_win, v->img, 0, 0);
}
