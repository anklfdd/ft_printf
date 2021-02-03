/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 19:29:18 by gavril            #+#    #+#             */
/*   Updated: 2021/01/20 20:40:52 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_writed(t_form *form, char *str)
{
	char *res;
	char *space;

	if (form->zero == 1 && form->minus == 0 && !(ft_strncmp(str, "", 2) == 0)
	&& ((form->dot == 0 && form->prec == 0) || form->nprec < 0))
		space = ft_count_space(form->width, str, '0');
	else
		space = ft_count_space(form->width, str, ' ');
	if (form->minus == 1)
	{
		res = ft_strjoin(str, space);
		ft_putstr(res);
	}
	else
	{
		res = ft_strjoin(space, str);
		ft_putstr(res);
	}
	form->ret += ft_strlen(space) + ft_strlen(str);
	ft_free_res(res, str, space);
}
