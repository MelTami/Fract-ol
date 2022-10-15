/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_sets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:28:53 by mvavasso          #+#    #+#             */
/*   Updated: 2022/10/15 15:29:38 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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
		color = 0x00000000;
	else if (n % 8 == 7)
		color = 0x00480dff;
	else if (n % 8 == 6)
		color = 0x006736ff;
	else if (n % 8 == 5)
		color = 0x007a4fff;
	else if (n % 8 == 4)
		color = 0x008c68fc;
	else if (n % 8 == 3)
		color = 0x009d7efc;
	else if (n % 8 == 2)
		color = 0x00ab91fa;
	else if (n % 8 == 1)
		color = 0x00b8a2fc;
	else if (n % 8 == 0)
		color = 0x00bfacfa;
	my_mlx_pixel_put(f, f->x, f->y, color);
}
