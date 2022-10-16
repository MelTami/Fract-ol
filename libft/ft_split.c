/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:43:42 by mvavasso          #+#    #+#             */
/*   Updated: 2022/10/16 18:19:40 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(const char *s, char c)
{
	int	words;
	int	i;
	int	isword;

	words = 0;
	i = 0;
	isword = 1;
	while (s[i])
	{
		if (s[i] != c && isword)
		{
			isword = 0;
			words++;
		}
		else if (s[i] == c)
			isword = 1;
		i++;
	}
	return (words);
}

static void	ft_alloc(char **str, char *s, int word, char c)
{
	int	i;
	int	j;
	int	start;
	int	end;

	i = 0;
	j = 0;
	while (i < word)
	{
		while (s[j] == c)
			j++;
		start = j;
		while (s[j] != c && s[j])
		{
			if (s[j + 1] == c || s[j + 1] == '\0')
				end = j;
			j++;
		}
		str[i] = ft_substr(&s[start], 0, (end - start + 1));
		i++;
	}
}

char	**ft_split(const char *s, char c)
{
	int		word;
	char	**str;

	if (!s && s[0] == 0)
		return (NULL);
	word = ft_count(s, c);
	str = malloc(sizeof(char *) * (word + 1));
	if (!str)
		return (NULL);
	ft_alloc (str, (char *)s, word, c);
	str[word] = NULL;
	return (str);
}
