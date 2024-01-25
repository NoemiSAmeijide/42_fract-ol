/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosilves <nosilves@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:16:31 by nosilves          #+#    #+#             */
/*   Updated: 2023/12/27 18:16:36 by nosilves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx/mlx.h"

int	exit_window(t_mlx *v)
{
	if (v)
		mlx_destroy_window(v->mlx, v->mlx_win);
	exit(EXIT_SUCCESS);
}

int	read_key(int press_key, t_mlx *v)
{
	if (press_key == KEY_ESC)
		exit_window(v);
	else if (press_key == KEY_B)
		v->lock_mov *= -1;
	else
	{
		if (press_key == KEY_L && v->iter > 100)
			v->iter = v->iter - 100;
		else if (press_key == KEY_M && v->iter < 2000)
			v->iter = v->iter + 100;
		else if (press_key == KEY_LEFT)
			v->rmove -= 20.0;
		else if (press_key == KEY_RIGHT)
			v->rmove += 20.0;
		else if (press_key == KEY_UP)
			v->imove -= 20.0;
		else if (press_key == KEY_DOWN)
			v->imove += 20.0;
		else if (press_key == KEY_SPC)
			v->color_change++;
		the_selector(v);
	}
	return (0);
}

int	mouse_hook(int x, int y, t_mlx *v)
{
	if (x < WIN_W && x >= 0 && y < WIN_H && y >= 0 && v->lock_mov == 1)
	{
		v->c.r = (((double)x + v->imove)
				/ (double)v->height * (v->y_max - v->y_min) + v->y_min);
		v->c.i = (((double)y + v->rmove)
				/ (double)v->width * (v->x_max - v->x_min) + v->x_min);
	}
	if (v->lock_mov == 1)
		the_selector(v);
	return (0);
}

int	mouse_handeler(int button, int x, int y, t_mlx *v)
{
	if (button == SC_UP)
	{
		v->x_max += ((double)(WIN_W - x)
				/ 8.0 * (v->x_max - v->x_min)) / (double)WIN_W;
		v->x_min -= ((double)x / 8.0 * (v->x_max - v->x_min)) / (double)WIN_W;
		v->y_max += ((double)(WIN_H - y)
				/ 8.0 * (v->y_max - v->y_min)) / (double)WIN_H;
		v->y_min -= ((double)y / 8.0 * (v->y_max - v->y_min)) / (double)WIN_H;
	}
	else if (button == SC_DOWN)
	{
		v->x_max -= ((double)(WIN_W - x)
				/ 8.0 * (v->x_max - v->x_min)) / (double)WIN_W;
		v->x_min += ((double)x / 8.0 * (v->x_max - v->x_min)) / (double)WIN_W;
		v->y_max -= ((double)(WIN_H - y)
				/ 8.0 * (v->y_max - v->y_min)) / (double)WIN_H;
		v->y_min += ((double)y / 8.0 * (v->y_max - v->y_min)) / (double)WIN_H;
	}
	the_selector(v);
	return (0);
}
