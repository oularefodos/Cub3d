/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <ahaifoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:10:49 by ahaifoul          #+#    #+#             */
/*   Updated: 2022/05/30 20:10:54 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_getlen(int n)
{
	long int	nb;
	int			i;

	nb = n;
	i = 1;
	if (nb < 0)
	{
		i++;
		nb = nb * -1;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	nb;
	int			len;	

	len = ft_getlen(n);
	nb = n;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		nb = nb * -1;
		str[0] = '-';
	}
	str[len] = 0;
	len--;
	while (nb >= 10)
	{
		str[len] = (nb % 10) + 48;
		nb = nb / 10;
		len--;
	}
	str[len] = nb + 48;
	return (str);
}
