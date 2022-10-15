/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:14:47 by mvavasso          #+#    #+#             */
/*   Updated: 2022/04/28 21:20:00 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t size)
{
	size_t	i;
	size_t	aux;

	i = 0;
	if (find == NULL || *find == '\0')
		return ((char *)str);
	while (str[i] && (i < size))
	{
		aux = 0;
		while ((find[aux] == str[i + aux]) && ((i + aux) < size))
		{
			if (find[aux + 1] == '\0')
				return ((char *)str + i);
			aux++;
		}
		i++;
	}
	return (0);
}
