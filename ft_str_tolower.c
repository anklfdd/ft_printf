/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tolower.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 03:47:01 by gavril            #+#    #+#             */
/*   Updated: 2021/01/16 22:16:28 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_str_tolower(char *str)
{
	int ind;

	ind = 0;
	while (str[ind])
	{
		str[ind] = ft_tolower(str[ind]);
		ind++;
	}
	return (str);
}
