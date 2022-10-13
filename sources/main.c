/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:39:10 by mvavasso          #+#    #+#             */
/*   Updated: 2022/10/13 15:04:28 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// void	lines()

// void	input_errors(int argc, char *argv[])
// {
// 	if (argc != 2)
// 	{
// 		ft_putstr_fd("Invalid syntax!\n", 1);
// 		exit (1);
// 	}
// 	else
// 	{
// 		if (ft_strncmp(argv[1], "Julia", sizeof(argv[1])) != 0 && ft_strncmp(argv[1], "Mandelbrot", sizeof(argv[1])) != 0)
// 		{
// 			ft_putstr_fd("You should use Julia or Mandelbrot set!\n", 1);
// 			exit (1);
// 		}
// 		else
// 		{
// 			ft_putstr_fd("Good job!\n", 1);
// 			exit (0);
// 		}
// 	}
// }
void	mandelbrot(t_vars *f, int x, int y, double cr, double ci)
{
	int	n;
	double	zr;
	double	zi;
	double	tmp;
	int	is_in_set; 

	zr = 0;
	zi = 0;
	n = -1;
	is_in_set = 1;
	while (++n < MAX_ITERATIONS)
	{
		if ((zr * zr + zi * zi) > 4.0)
		{
			is_in_set = 0;
			break ;
		}
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
	}
	if (is_in_set == 1)
		mlx_pixel_put(f->mlx, f->win, x, y, 0xFF0000);
	else
		mlx_pixel_put(f->mlx, f->win, x, y, 0x0000FF);
}

void	draw_fractal(t_vars *f)
{
	int	x;
	int	y;
	double	pr;
	double	pi;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pr = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
			pi = f->min_i + (double)y * (f->max_i - f->min_i) / HEIGHT;
			mandelbrot(f, x, y, pr, pi);
		}
	}
}

int	main(void)
{
	t_vars  f;
	// t_data 	mlx_img;

	f.mlx = mlx_init();
	f.min_r = -2.0;
	f.max_r = 1.0;
	f.min_i = -1.5;
	f.max_i = f.min_i + (f.max_r - f.min_r) * HEIGHT / WIDTH;
	f.win = mlx_new_window(f.mlx, WIDTH, HEIGHT, "Fract'ol test");
	// mlx_img.img = mlx_new_image(f.mlx, WIDTH, HEIGHT);
	// mlx_img.addr = mlx_get_data_addr(mlx_img.img, &mlx_img.bits_per_pixel, &mlx_img.line_length, &mlx_img.endian);
	draw_fractal(&f);
	mlx_loop(f.mlx);
	// mlx_destroy_image(f.mlx, mlx_img.img);
	// mlx_destroy_display(f.mlx);
	free(f.mlx);
}
