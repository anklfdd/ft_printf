/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:39:56 by gavril            #+#    #+#             */
/*   Updated: 2021/01/20 14:17:41 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_strcpy(char *dst, char *src)
{
	int ind;

	ind = 0;
	if (!src || !dst)
		return (0);
	while (src[ind])
	{
		dst[ind] = src[ind];
		ind++;
	}
	dst[ind] = '\0';
	return (dst);
}

static size_t	ft_count(long int n)
{
	size_t		count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n = n * (-1);
	}
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	size_t	ind;
	char	*str;

	ind = ft_count(n);
	if (!(str = (char*)malloc(sizeof(char) * (ind + 1))))
		return (0);
	if (n == -2147483648)
		return (ft_strcpy(str, "-2147483648"));
	str[ind--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = n * (-1);
	}
	if (n == 0)
		str[ind] = '0';
	while (n > 0)
	{
		str[ind--] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
