/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_name.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 03:22:57 by mvavasso          #+#    #+#             */
/*   Updated: 2022/10/15 16:14:18 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	ft_name(char *str)
{
	if ((ft_strncmp(str, "Mandelbrot", sizeof(str)) == 0) || \
			(ft_strncmp(str, "mandelbrot", sizeof(str)) == 0))
		return (1);
	if ((ft_strncmp(str, "Julia", sizeof(str)) == 0) || \
			(ft_strncmp(str, "julia", sizeof(str)) == 0))
		return (2);
	else
		return (0);
}
