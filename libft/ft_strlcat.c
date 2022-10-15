/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 23:47:52 by mvavasso          #+#    #+#             */
/*   Updated: 2022/04/25 19:52:27 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *str, size_t size)
{
	unsigned int	i;
	unsigned int	aux;
	unsigned int	save;

	aux = 0;
	i = 0;
	while (dest[aux] && aux < size)
		aux++;
	save = aux;
	if (aux < size)
	{
		while (str[i] && aux < (size - 1))
		{
			dest[aux++] = str[i];
			i++;
		}
		dest[aux] = '\0';
	}
	while (str[i])
		i++;
	return (i + save);
}
