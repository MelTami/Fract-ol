/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 02:36:20 by mvavasso          #+#    #+#             */
/*   Updated: 2022/10/15 16:14:18 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	exit_hook(t_vars *f)
{
	mlx_destroy_window(f->mlx, f->win);
	f->win = NULL;
	return (0);
}

void	zoom(t_vars *f, double zoom)
{
	double	middle_r;
	double	middle_i;

	middle_r = f->min_r - f->max_r;
	middle_i = f->max_i - f->min_i;
	f->max_r = f->max_r + (middle_r - zoom * middle_r) / 2;
	f->min_r = f->max_r + zoom * middle_r;
	f->min_i = f->min_i + (middle_i - zoom * middle_i) / 2;
	f->max_i = f->min_i + zoom * middle_i;
}

void	move_mouse(t_vars *f, double distance, char where)
{
	double	middle_r;
	double	middle_i;

	middle_r = f->max_r - f->min_r;
	middle_i = f->max_i - f->min_i;
	if (where == 'r')
	{
		f->min_r += middle_r * distance;
		f->max_r += middle_r * distance;
	}
	else if (where == 'l')
	{
		f->min_r -= middle_r * distance;
		f->max_r -= middle_r * distance;
	}
	else if (where == 'u')
	{
		f->min_i -= middle_i * distance;
		f->max_i -= middle_i * distance;
	}
	else if (where == 'd')
	{
		f->min_i += middle_i * distance;
		f->max_i += middle_i * distance;
	}
}

int	mouse_hook(int keycode, int x, int y, t_vars *f)
{
	if (keycode == 4)
	{
		zoom(f, 0.5);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		if (x < 0)
			move_mouse(f, (double)x * -1 / WIDTH, 'l');
		else if (x > 0)
			move_mouse(f, (double)x / WIDTH, 'r');
		if (y < 0)
			move_mouse(f, (double)y * -1 / HEIGHT, 'u');
		else if (y > 0)
			move_mouse(f, (double)y / HEIGHT, 'd');
	}
	else if (keycode == 5)
		zoom(f, 1.11);
	return (0);
}
