/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosilves <nosilves@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:42:59 by nosilves          #+#    #+#             */
/*   Updated: 2023/12/27 18:25:58 by nosilves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
# include "macro.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

typedef struct s_cmplx
{
	double	r;
	double	i;
}	t_cmplx;

typedef struct s_mlx
{
	void	*mlx;
	void	*img;
	void	*mlx_win;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		fractal;
	int		height;
	int		width;
	t_cmplx	z;
	t_cmplx	c;
	int		count;
	int		iter;
	double	res;
	int		col;
	int		row;
	int		color_change;
	double	x_max;
	double	x_min;
	double	y_max;
	double	y_min;
	double	rmove;
	double	imove;
	int		lock_mov;
	int		i;
	int		n;
	double	fraction;
	int		decimal_part;
	double	temp;
}				t_mlx;

void	ft_atod(const char *str, t_mlx *v);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_tolower(int c);
size_t	ft_strlen(const char *s);
void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);
void	color_iter(t_mlx *v);
void	julia(t_mlx *v);
void	mandelbrot(t_mlx *v);
void	tricorn(t_mlx *v);
int		exit_window(t_mlx *v);
int		read_key(int press_key, t_mlx *v);
int		mouse_hook(int x, int y, t_mlx *v);
int		mouse_handeler(int button, int x, int y, t_mlx *v);
int		main(int argc, char **argv);
void	the_selector(t_mlx *v);
void	validate_initial_aparams(int argc, char **argv, t_mlx *v);

#endif
