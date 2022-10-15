/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 03:58:34 by mvavasso          #+#    #+#             */
/*   Updated: 2022/10/15 15:29:16 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	set_color(t_vars *f, int n)
{
	if (f->color % 5 == 0)
		color_1(f, n);
	else if (f->color % 5 == 1)
		color_2(f, n);
	else if (f->color % 5 == 2)
		color_3(f, n);
	else if (f->color % 5 == 3)
		color_4(f, n);
	else if (f->color % 5 == 4)
		color_5(f, n);
}
