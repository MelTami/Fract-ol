/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 21:52:57 by mvavasso          #+#    #+#             */
/*   Updated: 2022/04/28 20:14:59 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nb, size_t size)
{
	void	*src;

	if (nb > 2147483647 || size > 2147483647)
		return (NULL);
	else if (nb * size > 2147483647)
		return (NULL);
	src = malloc(nb * size);
	if (!src)
		return (NULL);
	if (src)
		ft_bzero(src, (nb * size));
	return (src);
}
