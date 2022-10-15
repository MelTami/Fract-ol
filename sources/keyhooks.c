/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 02:36:17 by mvavasso          #+#    #+#             */
/*   Updated: 2022/10/15 03:35:43 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	handle_keypress(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		vars->win = NULL;
	}
	ft_arrows(keycode, vars);
	return (0);
}

void	ft_arrows(int keycode, t_vars *f)
{
	t_aux	aux;
	
	aux.middle_r = f->max_r - f->min_r;
	aux.middle_i = f->max_i - f->min_i;
	if (keycode == XK_Right)
	{
		f->min_r += aux.middle_r * 0.15;
		f->max_r += aux.middle_r * 0.15; 
	}
	if (keycode == XK_Left)
	{
		f->min_r -= aux.middle_r * 0.15;
		f->max_r -= aux.middle_r * 0.15; 
	}
	if (keycode == XK_Up)
	{
		f->min_i -= aux.middle_i * 0.15;
		f->max_i -= aux.middle_i * 0.15;
	}
	if (keycode == XK_Down)
	{
		f->min_i += aux.middle_i * 0.15;
		f->max_i += aux.middle_i * 0.15;
	}
	return ;
}