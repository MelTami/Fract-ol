/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:45:10 by mvavasso          #+#    #+#             */
/*   Updated: 2022/10/16 18:19:49 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*another_split(char **str)
{
	char	*line;
	int		i;
	char	*temp;

	if (str[0] == NULL)
		return (NULL);
	i = 0;
	while (str[0][i] != '\0' && str[0][i] != '\n')
		i++;
	line = ft_substr(str[0], 0, i + 1);
	temp = ft_strdup(str[0]);
	ft_free(str);
	str[0] = ft_substr(temp, i + 1, ft_strlen(temp));
	ft_free(&temp);
	if (!(ft_strchr(line, '\n')))
	{
		ft_free(str);
		if (!ft_strlen(line))
			ft_free(&line);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*str;
	int			fread;
	static char	*s_line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	fread = read(fd, str, BUFFER_SIZE);
	while (fread > 0)
	{
		str[fread] = '\0';
		if (s_line == NULL)
			s_line = ft_strdup(str);
		else
		{
			temp = ft_strjoin(s_line, str);
			ft_free(&s_line);
			s_line = temp;
		}
		if (ft_strchr(s_line, '\n'))
			break ;
		fread = read(fd, str, BUFFER_SIZE);
	}
	return (ft_free(&str), another_split(&s_line));
}
