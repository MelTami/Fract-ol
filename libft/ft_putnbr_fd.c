/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:43:51 by mvavasso          #+#    #+#             */
/*   Updated: 2022/04/28 22:17:38 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;

	nb = n;
	if (nb == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		nb = 147483648;
	}
	if (nb < 0)
	{
		nb = nb * (-1);
		write(fd, "-", 1);
	}
	if (nb < 10)
	{
		nb = nb + 48;
		ft_putchar_fd(nb, fd);
	}
	else
	{
		ft_putnbr_fd((nb / 10), fd);
		nb = (nb % 10) + 48;
		ft_putchar_fd(nb, fd);
	}
}
