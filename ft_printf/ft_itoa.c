/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrui-ha <chrui-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:19:25 by chrui-ha          #+#    #+#             */
/*   Updated: 2024/08/07 19:43:42 by chrui-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	length(long n)
{
	int		i;
	long	nb;

	i = 0;
	nb = n;
	if (nb < 1)
		i ++;
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static char	*ft_putnbr(long nb, char *c, long len)
{
	int	i;

	i = 0;
	if (nb < 0)
		nb *= -1;
	while (len--)
	{
		*(c + len) = 48 + nb % 10;
		nb /= 10;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	char	*c;
	long	i;
	int		sign;
	long	nb;

	nb = n;
	sign = 0;
	if (nb < 0)
		sign = 1;
	i = length(nb);
	c = (char *)malloc((i + 1) * sizeof(char));
	if (!c)
		return (NULL);
	*(c + i) = '\0';
	ft_putnbr(nb, c, i);
	if (sign)
		*(c) = 45;
	return (c);
}
