/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 23:32:48 by mvavasso          #+#    #+#             */
/*   Updated: 2022/04/25 19:52:07 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *str, size_t size)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	if (size == 0)
		return (ft_strlen(str));
	while (str[count])
		count++;
	while (i < (size - 1) && str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (count);
}
