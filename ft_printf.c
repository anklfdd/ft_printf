/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 17:57:51 by gavril            #+#    #+#             */
/*   Updated: 2021/01/20 19:07:43 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list	arg;
	t_form	*form;

	if (!(form = (t_form *)malloc(sizeof(t_form))))
		return (-1);
	form->ret = 0;
	if (str == NULL)
		return (-1);
	va_start(arg, str);
	ft_parser(str, arg, form);
	va_end(arg);
	free(form);
	return (form->ret);
}
