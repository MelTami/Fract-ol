/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:14:38 by mvavasso          #+#    #+#             */
/*   Updated: 2022/04/28 20:41:41 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*first;
	unsigned char	*sec;

	if (n == 0)
		return (0);
	i = 0;
	first = (unsigned char *)str1;
	sec = (unsigned char *)str2;
	while (i < n)
	{
		if (first[i] != sec[i])
			return (first[i] - sec[i]);
		i++;
	}
	return (0);
}
