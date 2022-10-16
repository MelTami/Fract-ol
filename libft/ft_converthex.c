/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converthex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:02:51 by mvavasso          #+#    #+#             */
/*   Updated: 2022/10/16 18:20:11 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_converthex(int hex, char *s)
{
	int	len;

	if (*s == 'X')
		len = ft_puthex(hex, "0123456789ABCDEF");
	else
		len = ft_puthex(hex, "0123456789abcdef");
	return (len);
}

int	ft_puthex(unsigned int num, char *base)
{
	int			len_base;
	static int	len;

	len = 0;
	len_base = ft_strlen(base);
	if (num / len_base > 0)
		ft_puthex(num / len_base, base);
	len++;
	ft_putchar(base[num % len_base]);
	return (len);
}
