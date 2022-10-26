/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 00:14:54 by mvavasso          #+#    #+#             */
/*   Updated: 2022/10/27 00:18:54 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	msg(void)
{
	ft_putstr_fd("Your sintax is invalid!\n", 1);
	ft_putstr_fd("------------Some tips for you!-----------\n", 1);
	ft_putstr_fd("Your sintax should follow these steps,\n", 1);
	ft_putstr_fd("./fractol Mandelbrot\n", 1);
	ft_putstr_fd("or\n ", 1);
	ft_putstr_fd("./fractol Julia [kr] [ki], -2.0 < k > 2.0\n", 1);
	ft_putstr_fd("-----Some numbers for Julia that are cool--!\n", 1);
	ft_putstr_fd("-0.076667 -0.90000\n", 1);
}

int	validation(int argc, char *argv[], int n)
{
	if (argc < 2 || argc > 4)
		n = 1;
	else if ((ft_strncmp(argv[1], "Mandelbrot", sizeof(argv[1])) != 0) \
			&& (ft_strncmp(argv[1], "Julia", sizeof(argv[1])) != 0))
		n = 1;
	else if ((ft_strncmp(argv[1], "Julia", sizeof(argv[1])) == 0) && \
			(param_error(argv, 0) == 1))
		n = 1;
	else if ((ft_strncmp(argv[1], "Mandelbrot", sizeof(argv[1])) == 0) && \
			argv[2] != NULL)
		n = 1;
	if (n == 1)
	{
		msg();
		return (n);
	}
	return (0);
}

int	param_error(char *argv[], int n)
{
	double	ki;
	double	kr;
	char	*real;
	char	*im;

	im = argv[3];
	real = argv[2];
	if (argv[2] == NULL || argv[3] == NULL)
		return (1);
	kr = ft_atof(real);
	ki = ft_atof(im);
	if (kr == -42 || ki == -42)
		n = 1;
	if (ki < -2.0 && ki > 2.0)
		n = 1;
	if (kr < -2.0 && kr > 2.0)
		n = 1;
	return (n);
}
