/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 21:51:02 by gavril            #+#    #+#             */
/*   Updated: 2021/01/16 22:18:23 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strdup(const char *str)
{
	char	*str2;
	int		ind;

	ind = 0;
	while (str[ind] != '\0')
		ind++;
	if (!str || !(str2 = (char*)malloc(ind + 1)))
		return (0);
	ind = 0;
	while (str[ind] != '\0')
	{
		str2[ind] = str[ind];
		ind++;
	}
	str2[ind] = '\0';
	return (str2);
}
