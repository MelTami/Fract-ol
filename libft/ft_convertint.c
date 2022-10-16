/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 22:04:59 by mvavasso          #+#    #+#             */
/*   Updated: 2022/10/16 18:07:59 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_convertint(int nb)
{
	char	*s_nb;
	int		len;

	s_nb = ft_itoa(nb);
	len = ft_strlen(s_nb);
	ft_putstr_fd(s_nb, 1);
	free(s_nb);
	return (len);
}

size_t	len(int n)
{
	size_t	length;

	length = 0;
	if (n < 0)
	{
		n = n * -1;
		length++;
	}
	while (n)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

char	*value(int n)
{
	char	*max;
	char	*ret;

	max = "-2147483648";
	if (n == -2147483648)
	{
		ret = ft_substr(max, 0, ft_strlen(max));
		return (ret);
	}
	ret = ft_substr("0", 0, 1);
	return (ret);
}

char	*ft_itoa(int n)
{
	size_t	length;
	char	*str;

	if (n == 0 || n == -2147483648)
	{
		str = value(n);
		return (str);
	}
	length = len(n);
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	str[length--] = '\0';
	while (n)
	{
		str[length--] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
