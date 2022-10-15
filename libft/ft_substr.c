/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:54:37 by mvavasso          #+#    #+#             */
/*   Updated: 2022/04/28 20:30:45 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	tsize;

	i = 0;
	if (start >= ft_strlen(s))
		tsize = 1;
	else if (len >= ft_strlen(s))
		tsize = ft_strlen(s) - start + 1;
	else
		tsize = len + 1;
	substr = malloc(tsize);
	if (!substr)
		return (NULL);
	while ((start < ft_strlen(s)) && (i < len))
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = 0;
	return (substr);
}
