/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:41:59 by mvavasso          #+#    #+#             */
/*   Updated: 2022/10/26 23:49:03 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 900
# define HEIGHT 900
# define MAX_ITERATIONS 300

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	kr;
	double	ki;
	int		name;
	int		color;
	int		x;
	int		y;
	t_data	img;
}				t_vars;

typedef struct s_aux{
	double	middle_r;
	double	middle_i;
}				t_aux;

void	my_mlx_pixel_put(t_vars *f, int x, int y, int color);
int		julia(t_vars *f, double zr, double zi);
int		mandelbrot(double cr, double ci);
void	ft_arrows(int keycode, t_vars *f);
int		handle_keypress(int keycode, t_vars *vars);
int		exit_hook(t_vars *f);
double	ft_name(char *str);
void	set_vars(t_vars *f, char **argv);
void	set_color(t_vars *f, int n);
void	color_1(t_vars *f, int n);
void	color_2(t_vars *f, int n);
void	color_3(t_vars *f, int n);
void	color_4(t_vars *f, int n);
void	color_5(t_vars *f, int n);
double	ft_atof(char *str);
int		mouse_hook(int keycode, int x, int y, t_vars *f);
int		render(t_vars *f);
void	msg(void);
int		validation(int argc, char *argv[], int n);
int		init(t_vars *f);
void	clean_win(t_vars *f);
int		param_error(char *argv[], int n);

#endif