/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:14:40 by mvavasso          #+#    #+#             */
/*   Updated: 2022/04/28 20:07:15 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, unsigned int n)
{
	unsigned int	i;
	char			*copy;
	char			*mov;

	i = 0;
	copy = (char *)src;
	mov = (char *)dest;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		mov[i] = copy[i];
		i++;
	}
	return (dest);
}
