/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:14:50 by mvavasso          #+#    #+#             */
/*   Updated: 2022/04/28 20:52:56 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *str, int find)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	if (find > 255)
		return ((void *) str);
	i = ft_strlen(str);
	while (i > 0)
	{
		if (str[i] == find)
		{
			return ((char *)&str[i]);
			break ;
		}
		i--;
	}
	if (str[i] == find)
		return ((char *)&str[i]);
	return (NULL);
}
