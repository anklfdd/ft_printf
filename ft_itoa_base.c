/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 01:41:43 by gavril            #+#    #+#             */
/*   Updated: 2021/01/16 22:16:43 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_count(unsigned int n, int sys)
{
	size_t		count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / sys;
		count++;
	}
	return (count);
}

char			*ft_itoa_base(unsigned int n, int sys)
{
	size_t	ind;
	char	*str;
	char	*dict;

	dict = "0123456789ABCDEF";
	ind = ft_count(n, sys);
	if (!(str = (char*)malloc(sizeof(char) * ind + 1)))
		return (0);
	str[ind--] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[ind--] = dict[n % sys];
		n = n / sys;
	}
	return (str);
}
