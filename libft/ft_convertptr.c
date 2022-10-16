/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 02:29:20 by mvavasso          #+#    #+#             */
/*   Updated: 2022/10/16 18:20:19 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_convertptr(void *ptr)
{
	int	i;

	if (!ptr)
		return (ft_putstr_fd("(nil)", 1));
	ft_putstr_fd("0x", 1);
	i = 2;
	i += ft_putbase((unsigned long)ptr, "0123456789abcdef");
	return (i);
}

int	ft_putbase(unsigned long num, char *base)
{
	int			len_base;
	static int	len;

	len = 0;
	len_base = ft_strlen(base);
	if (num / len_base > 0)
		ft_putbase(num / len_base, base);
	len++;
	ft_putchar(base[num % len_base]);
	return (len);
}
