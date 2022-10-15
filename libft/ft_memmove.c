/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:14:43 by mvavasso          #+#    #+#             */
/*   Updated: 2022/05/12 19:11:01 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, void *str2, unsigned int n)
{
	char			*copy;
	char			*mov;

	copy = (char *)str2;
	mov = (char *)str1;
	if (str1 == str2)
		return (str1);
	if (str1 < str2)
		ft_memcpy(mov, copy, n);
	else
		while (n--)
			mov[n] = copy[n];
	return (str1);
}
