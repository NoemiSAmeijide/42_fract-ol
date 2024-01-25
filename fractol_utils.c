/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosilves <nosilves@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:52:38 by nosilves          #+#    #+#             */
/*   Updated: 2023/12/27 19:52:43 by nosilves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	utils_atod(const char *str, t_mlx *v)
{
	if (str[v->i] == '.')
		v->decimal_part++;
	if (v->decimal_part == 0)
		v->res = v->res * 10.0 + (str[v->i] - '0');
	else if (v->decimal_part == 1 && str[v->i] != '.')
	{
		v->fraction /= 10.0;
		v->res = v->res + (str[v->i] - '0') * v->fraction;
	}
	v->i++;
}

void	ft_atod(const char *str, t_mlx *v)
{
	v->n = 1;
	v->fraction = 1.0;
	v->decimal_part = 0;
	v->i = 0;
	v->res = 0;
	while (str[v->i] == ' ' || str[v->i] == '\r' || str[v->i] == '\t'
		|| str[v->i] == '\n' || str[v->i] == '\v' || str[v->i] == '\f')
		v->i++;
	if (str[v->i] == '-' || str[v->i] == '+')
	{
		if (str[v->i++] == '-')
			v->n = -1;
	}
	while (((str[v->i] >= '0' && str[v->i] <= '9') || str[v->i] == '.')
		&& v->decimal_part < 2)
		utils_atod(str, v);
	if (str[v->i] != '\0' || v->decimal_part == 2)
	{
		write(1, "valid params please!\n", 21);
		v->fractal = -1;
	}
	v->res = v->res * v->n;
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i == n)
		return (0);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}
