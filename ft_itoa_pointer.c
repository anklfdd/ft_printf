/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:52:27 by gavril            #+#    #+#             */
/*   Updated: 2021/01/20 19:08:58 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_count(unsigned long long n)
{
	size_t		count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

char			*ft_itoa_pointer(unsigned long long p)
{
	size_t	ind;
	char	*str;
	char	*dict;

	dict = "0123456789abcdef";
	ind = ft_count(p);
	if (!(str = (char*)malloc(sizeof(char) * ind + 1)))
		return (0);
	str[ind--] = '\0';
	if (p == 0)
		str[0] = '0';
	while (p > 0)
	{
		str[ind--] = dict[p % 16];
		p = p / 16;
	}
	return (str);
}
