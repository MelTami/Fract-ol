/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:32:58 by mvavasso          #+#    #+#             */
/*   Updated: 2022/10/27 00:04:17 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_vars *f, int x, int y, int color)
{
	char	*dst;

	dst = f->img.addr + (y * f->img.ll + x * (f->img.bpp / 8));
	*(int *)dst = color;
}

void	draw_fractal(t_vars *f)
{
	double	pr;
	double	pi;
	int		count;

	f->y = 0;
	count = 0;
	while (f->y++ < HEIGHT)
	{
		f->x = 0;
		while (f->x++ < WIDTH)
		{
			pr = f->min_r + (double)f->x * (f->max_r - f->min_r) / WIDTH;
			pi = f->min_i + (double)f->y * (f->max_i - f->min_i) / HEIGHT;
			if (f->name == 1)
				count = mandelbrot(pr, pi);
			else if (f->name == 2)
				count = julia(f, pr, pi);
			set_color(f, count);
		}
	}
}

void	set_vars(t_vars *f, char **argv)
{
	double	kr;
	double	ki;

	kr = 0;
	ki = 0;
	if (f->name == 2)
	{
		kr = ft_atof(argv[2]);
		ki = ft_atof(argv[3]);
		f->min_r = -2.0;
		f->max_r = 2.0;
		f->min_i = -2.0;
		f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
	else
	{
		f->min_r = -2.0;
		f->max_r = 1.0;
		f->min_i = -1.5;
		f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
	f->img.img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->kr = kr;
	f->ki = ki;
	f->color = 9;
}

int	render(t_vars *f)
{
	if (f->win == NULL)
		return (1);
	mlx_clear_window(f->mlx, f->win);
	draw_fractal(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
	return (0);
}
