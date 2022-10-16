/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:16:37 by mvavasso          #+#    #+#             */
/*   Updated: 2022/10/16 18:07:59 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	whitespace(char w)
{
	if (w == ' ' || (w <= 13 && w >= 9))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t		i;
	long int	nb;
	int			signal;

	i = 0;
	nb = 0;
	signal = 0;
	while (whitespace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal++;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	if (signal == 1)
		return (-nb);
	return (nb);
}
