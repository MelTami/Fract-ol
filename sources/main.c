/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:39:10 by mvavasso          #+#    #+#             */
/*   Updated: 2022/10/27 01:29:22 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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

int	exit_program(t_vars *f)
{
	mlx_destroy_window(f->mlx, f->win);
	mlx_loop_end(f->mlx);
	mlx_destroy_image(f->mlx, f->img.img);
	mlx_destroy_display(f->mlx);
	free(f->mlx);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_vars	f;

	if (validation(argc, argv, 0) == 1)
		return (0);
	init(&f);
	f.name = ft_name(argv[1]);
	set_vars(&f, &*argv);
	f.img.addr = mlx_get_data_addr(f.img.img, &f.img.bpp, \
									&f.img.ll, &f.img.endian);
	mlx_loop_hook(f.mlx, &render, &f);
	mlx_hook(f.win, KeyPress, KeyPressMask, handle_keypress, &f);
	mlx_hook(f.win, DestroyNotify, NoEventMask, exit_program, &f);
	mlx_mouse_hook(f.win, mouse_hook, &f);
	mlx_loop(f.mlx);
	mlx_loop_end(f.mlx);
	mlx_destroy_image(f.mlx, f.img.img);
	mlx_destroy_display(f.mlx);
	free(f.mlx);
	return (0);
}
