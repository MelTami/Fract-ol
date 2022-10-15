/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:39:10 by mvavasso          #+#    #+#             */
/*   Updated: 2022/10/15 05:17:20 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_vars *f, int x, int y, int color)
{
	char	*dst;

	dst = f->img.addr + (y * f->img.ll + x * (f->img.bpp / 8));
	*(int*)dst = color;
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
			if(f->name == 1)
				count = mandelbrot(pr, pi);
			else if(f->name == 2)
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
	if ((ft_strncmp(argv[1], "julia", sizeof(argv[1])) == 0) || (ft_strncmp(argv[1], "Julia", sizeof(argv[1])) == 0))
	{
		kr = ft_atod(argv[2]);
		ki = ft_atod(argv[3]);
	}
	f->img.img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->min_r = -2.0;
	f->max_r = 1.0;
	f->min_i = -1.5;
	f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
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

int	main(int argc, char *argv[])
{
	t_vars  f;

	if(argc < 2 || argc > 4)
		ft_putstr_fd("Invalid syntax!\n", 1);
	f.mlx = mlx_init();
	if (f.mlx == NULL)
		return (ft_putstr_fd("MLX ERROR!\n", 1));
	f.win = mlx_new_window(f.mlx, WIDTH, HEIGHT, "Fract'ol");
	if (f.win == NULL)
	{
		free(f.win);
		return (ft_putstr_fd("MLX ERROR!\n", 1));
	}
	f.name = ft_name(argv[1]);
	set_vars(&f, &*argv);
	f.img.addr = mlx_get_data_addr(f.img.img, &f.img.bpp, &f.img.ll, &f.img.endian);
	// draw_fractal(&f);
	mlx_loop_hook(f.mlx, &render, &f);
	mlx_hook(f.win, KeyPress, KeyPressMask, handle_keypress, &f);
	mlx_hook(f.win, 17, 0, exit_hook, &f);
	mlx_mouse_hook(f.win, mouse_hook, &f);
	mlx_loop(f.mlx);
	mlx_destroy_image(f.mlx, f.img.img);
	mlx_destroy_display(f.mlx);
	free(f.mlx);
	return (0);
}
