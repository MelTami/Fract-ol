/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:39:10 by mvavasso          #+#    #+#             */
/*   Updated: 2022/09/27 15:14:18 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

void	input_errors(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_putstr_fd("Invalid syntax!\n", 1);
		exit (1);
	}
	else
	{
		if (ft_strncmp(argv[1], "Julia", sizeof(argv[1])) != 0 && ft_strncmp(argv[1], "Mandelbrot", sizeof(argv[1])) != 0)
		{
			ft_putstr_fd("You should use Julia or Mandelbrot set!\n", 1);
			exit (1);
		}
		else
		{
			ft_putstr_fd("Good job!\n", 1);
			exit (0);
		}
	}
}

int	main(int argc, char *argv[])
{
	t_vars  d;
	t_data 	mlx_img;

	d.mlx = mlx_init();
	if (!d.mlx)
		return (ft_putstr_fd("MLX_ERROR\n", 1));
	d.win = mlx_new_window(d.mlx, WIDTH, HEIGHT, "fractol");
	if (!d.win)
	{
		free(d.win);
		return (ft_putstr_fd("MLX_ERROR\n", 1));
	}
	mlx_img.img = mlx_new_image(d.mlx, WIDTH, HEIGHT);
	mlx_img.addr = mlx_get_data_addr(mlx_img.img, &mlx_img.bpp, &mlx_img.line_len, &mlx_img.endian);
	mlx_loop(d.mlx);
	mlx_destroy_window(d.mlx, d.win);
	free(d.mlx);
}
