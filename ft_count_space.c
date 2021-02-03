/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:43:54 by gavril            #+#    #+#             */
/*   Updated: 2021/01/20 19:10:27 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_count_space(unsigned long int pw, char *str, char zero_or_space)
{
	unsigned long int	space;
	char				*str_space;

	space = pw;
	if (space <= ft_strlen(str))
		return ("");
	if (!(str_space = (char *)malloc(sizeof(char)
	* (space - ft_strlen(str) + 1))))
		return (NULL);
	str_space[space - ft_strlen(str)] = '\0';
	while (space > ft_strlen(str))
	{
		str_space[space - ft_strlen(str) - 1] = zero_or_space;
		space--;
	}
	return (str_space);
}
