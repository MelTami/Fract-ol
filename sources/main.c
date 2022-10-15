/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:39:10 by mvavasso          #+#    #+#             */
/*   Updated: 2022/10/15 16:44:09 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	msg(int val)
{
	if (val == 1)
	{
		ft_putstr_fd("Your sintax is invalid!\n", 1);
		ft_putstr_fd("-----------------------\n", 1);
		ft_putstr_fd("Your sintax should follow these steps,\n", 1);
		ft_putstr_fd("./fractol [Mandelbrot or Julia]\n", 1);
		ft_putstr_fd("if you pick Julia, ", 1);
		ft_putstr_fd("add [kr] and [ki], -2.0 < k > 2.0\n", 1);
	}
	else if (val == 0)
	{
		ft_putstr_fd("Your sintax is invalid!\n", 1);
		ft_putstr_fd("Too few arguments!\n", 1);
	}
	else if (val == 2)
	{
		ft_putstr_fd("Your sintax is invalid!\n", 1);
		ft_putstr_fd("Too much arguments!\n", 1);
	}
}

int	validation(int argc, char *argv[])
{
	if (argc < 2)
	{
		msg(0);
		return (1);
	}
	if (argc > 4)
	{
		msg(2);
		return (1);
	}
	if ((ft_strncmp(argv[1], "Julia", sizeof(argv[1])) != 0) \
			&& (ft_strncmp(argv[1], "Mandelbrot", sizeof(argv[1])) != 0))
	{
		msg(1);
		return (1);
	}
	return (0);
}

int	init(t_vars *f)
{
	f->mlx = mlx_init();
	if (f->mlx == NULL)
		return (ft_putstr_fd("Occured an error connecting to mlx!\n", 1));
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fract'ol");
	if (f->win == NULL)
	{
		free(f->win);
		return (ft_putstr_fd("Occured an error in creating window!\n", 1));
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_vars	f;

	if (validation(argc, argv) == 1)
		return (0);
	init(&f);
	f.name = ft_name(argv[1]);
	set_vars(&f, &*argv);
	f.img.addr = mlx_get_data_addr(f.img.img, &f.img.bpp, \
									&f.img.ll, &f.img.endian);
	mlx_loop_hook(f.mlx, &render, &f);
	mlx_hook(f.win, KeyPress, KeyPressMask, handle_keypress, &f);
	mlx_hook(f.win, 17, 0, exit_hook, &f);
	mlx_mouse_hook(f.win, mouse_hook, &f);
	mlx_loop(f.mlx);
	mlx_destroy_image(f.mlx, f.img.img);
	mlx_destroy_display(f.mlx);
	mlx_loop_end(f.mlx);
	free(f.mlx);
	return (0);
}
