/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosilves <nosilves@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:11:36 by nosilves          #+#    #+#             */
/*   Updated: 2023/12/27 18:10:48 by nosilves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx/mlx.h"

void	init(t_mlx *v)
{
	v->x_min = -2.0;
	v->x_max = 1.0;
	v->y_min = -1.5;
	v->y_max = 1.5;
	v->iter = DEF_ITER;
	v->height = WIN_H;
	v->width = WIN_W;
	v->rmove = 0;
	v->imove = 0;
	v->lock_mov = 0;
	v->color_change = 1;
	if (v->fractal == 1)
	{
		v->x_min = -1.5;
		v->x_max = 1.5;
		v->lock_mov = 1;
	}
}

void	the_selector(t_mlx *v)
{
	v->row = 0;
	if (v->fractal == 1)
		julia(v);
	else if (v->fractal == 2)
		mandelbrot(v);
	else if (v->fractal == 3)
		tricorn(v);
}

int	main(int argc, char **argv)
{
	t_mlx	v;

	validate_initial_aparams(argc, argv, &v);
	if (v.fractal == 0)
	{
		write(1, "Say:\n'Mandelbrot'\n'Julia'\n'Tricorn'\n", 36);
		return (0);
	}
	if (v.fractal == -1)
		return (0);
	init(&v);
	v.mlx = mlx_init();
	v.img = mlx_new_image(v.mlx, WIN_W, WIN_H);
	if (!v.mlx || !v.img)
		exit(1);
	v.addr = mlx_get_data_addr(v.img, &v.bits_per_pixel, &v.line_length,
			&v.endian);
	v.mlx_win = mlx_new_window(v.mlx, WIN_W, WIN_H, "My fract-ol");
	the_selector(&v);
	mlx_hook(v.mlx_win, KEYPRESS, 0, read_key, &v);
	mlx_hook(v.mlx_win, DESTROYNOTIFY, 0, exit_window, &v);
	mlx_hook(v.mlx_win, BUTTONPRESS, 0, mouse_handeler, &v);
	mlx_hook(v.mlx_win, MOTIONNOTIFY, 0, mouse_hook, &v);
	mlx_loop(v.mlx);
}
