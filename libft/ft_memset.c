/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:14:11 by mvavasso          #+#    #+#             */
/*   Updated: 2022/04/19 19:41:50 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, unsigned int n)
{
	unsigned int	i;
	char			*aux;

	i = 0;
	aux = (char *)str;
	while (i < n)
	{
		aux[i] = c;
		i++;
	}
	return (str);
}
