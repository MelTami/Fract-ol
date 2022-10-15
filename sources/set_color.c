/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 03:58:34 by mvavasso          #+#    #+#             */
/*   Updated: 2022/10/15 05:02:34 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	set_color(t_vars *f, int n)
{
	if (f->color % 5 == 0)
		color_1(f, n);
	else if (f->color % 5 == 1)
		color_2(f, n);
	else if (f->color % 5 == 2)
		color_3(f, n);
	else if (f->color % 5 == 3)
		color_4(f, n);
	else if (f->color % 5 == 4)
		color_5(f, n);
}

void	color_1(t_vars *f, int n)
{
	int	color;

	color = 0x00000000;
	if (n == MAX_ITERATIONS)
		color = 0x00000000;
	else if (n % 8 == 7)
		color = 0x00C9BF63;
	else if (n % 8 == 6)
		color = 0x008F00FF;
	else if (n % 8 == 5)
		color = 0x4B0082;
	else if (n % 8 == 4)
		color = 0x000000FF;
	else if (n % 8 == 3)
		color = 0x0000FF00;
	else if (n % 8 == 2)
		color = 0x00FFFF00;
	else if (n % 8 == 1)
		color = 0x00FF7F00;
	else if (n % 8 == 0)
		color = 0x00FF0000;
	my_mlx_pixel_put(f, f->x, f->y, color);
}

void	color_2(t_vars *f, int n)
{
	int	color;

	color = 0x00000000;
	if (n == MAX_ITERATIONS)
		color = 0x00000000;
	else if (n % 8 == 7)
		color = 0x00FF0000;
	else if (n % 8 == 6)
		color = 0x00FF0381;
	else if (n % 8 == 5)
		color = 0x00FFCC00;
	else if (n % 8 == 4)
		color = 0x00D1F40B;
	else if (n % 8 == 3)
		color = 0x00FB9AC0;
	else if (n % 8 == 2)
		color = 0x00EAF49D;
	else if (n % 8 == 1)
		color = 0x0053E3EA;
	else if (n % 8 == 0)
		color = 0x006BB6F7;
	my_mlx_pixel_put(f, f->x, f->y, color);
}

void	color_3(t_vars *f, int n)
{
	int	color;

	color = 0x00000000;
	if (n == MAX_ITERATIONS)
		color = 0x00000000;
	else if (n % 8 == 7)
		color = 0x00fafa6e;
	else if (n % 8 == 6)
		color = 0x00b5e877;
	else if (n % 8 == 5)
		color = 0x0077d183;
	else if (n % 8 == 4)
		color = 0x003fb78d;
	else if (n % 8 == 3)
		color = 0x00009c8f;
	else if (n % 8 == 2)
		color = 0x00007f86;
	else if (n % 8 == 1)
		color = 0x001c6373;
	else if (n % 8 == 0)
		color = 0x002a4858;
	my_mlx_pixel_put(f, f->x, f->y, color);
}

void	color_4(t_vars *f, int n)
{
	int	color;

	color = 0x00000000;
	if (n == MAX_ITERATIONS)
		color = 0x00000000;
	else if (n % 8 == 1)
		color = 0x00f51b4e;
	else if (n % 8 == 2)
		color = 0x00ff3363;
	else if (n % 8 == 3)
		color = 0x00f25076;
	else if (n % 8 == 4)
		color = 0x00f26f8e;
	else if (n % 8 == 5)
		color = 0x00f28aa2;
	else if (n % 8 == 6)
		color = 0x00f5a6b8;
	else if (n % 8 == 7)
		color = 0x00f7bac8;
	else if (n % 8 == 0)
		color = 0x00d40233;
	my_mlx_pixel_put(f, f->x, f->y, color);
}

void	color_5(t_vars *f, int n)
{
	int	color;

	color = 0x00000000;
	if (n == MAX_ITERATIONS)
		color = 0x000b0430;
	else if (n % 8 == 7)
		color = 0x00b9adf7;
	else if (n % 8 == 6)
		color = 0x000351fab;
	else if (n % 8 == 5)
		color = 0x008a62f8;
	else if (n % 8 == 4)
		color = 0x00c1b5ff;
	else if (n % 8 == 3)
		color = 0x007551e5;
	else if (n % 8 == 2)
		color = 0x001f0f75;
	else if (n % 8 == 1)
		color = 0x004a30be;
	else if (n % 8 == 0)
		color = 0x006041d2;
	my_mlx_pixel_put(f, f->x, f->y, color);
}