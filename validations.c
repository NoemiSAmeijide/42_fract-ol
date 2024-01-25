/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosilves <nosilves@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:11:36 by nosilves          #+#    #+#             */
/*   Updated: 2023/12/27 18:09:35 by nosilves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	validate_julia(int argc, char **argv, t_mlx *v)
{
	write(1, "Julia\n", 6);
	if (argc == 2)
	{
		v->c.r = -0.8;
		v->c.i = 0.156;
	}
	else if (argc == 4)
	{
		ft_atod(argv[2], v);
		v->c.r = v->res;
		ft_atod(argv[3], v);
		v->c.i = v->res;
	}
	else
	{
		write(1, "valid params please!\n", 21);
		v->fractal = -1;
	}
}

void	validate_mandel(t_mlx *v)
{
	write(1, "Mandelbrot\n", 11);
	v->fractal = 2;
}

void	validate_trico(t_mlx *v)
{
	write(1, "Tricorn\n", 8);
	v->fractal = 3;
}

void	validate_initial_aparams(int argc, char **argv, t_mlx *v)
{
	v->i = 0;
	if (argc == 1)
		v->fractal = 0;
	else
	{
		while (argv[1][v->i++] != '\0')
			argv[1][v->i - 1] = ft_tolower(argv[1][v->i - 1]);
		if ((ft_strncmp(argv[1], "julia", ft_strlen(argv[1])) == 0)
			&& (ft_strlen(argv[1]) == 5) && argc > 1)
		{
			v->fractal = 1;
			validate_julia(argc, argv, v);
		}
		else if ((ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1])) == 0)
			&& (ft_strlen(argv[1]) == 10) && argc == 2)
			validate_mandel(v);
		else if ((ft_strncmp(argv[1], "tricorn", ft_strlen(argv[1])) == 0)
			&& (ft_strlen(argv[1]) == 7) && argc == 2)
			validate_trico(v);
		else
			v->fractal = 0;
	}
}
