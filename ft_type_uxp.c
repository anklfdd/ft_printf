/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_uxp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 20:18:54 by gavril            #+#    #+#             */
/*   Updated: 2021/01/20 20:40:19 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_p(unsigned long long point, t_form *form)
{
	char	*str;
	char	*tmp;

	tmp = ft_itoa_pointer(point);
	if (form->dot == 1 && point == 0 && form->prec == 0 && form->nprec == 0)
		str = ft_strjoin("0x", "");
	else
		str = ft_strjoin("0x", tmp);
	ft_free_res(tmp, NULL, NULL);
	ft_writed(form, str);
}

void	ft_type_u(unsigned int u, t_form *form)
{
	char	*str;
	char	*tmp;
	char	*prec;

	str = ft_itoa_base(u, 10);
	if (form->prec > ft_strlen(str))
	{
		tmp = str;
		prec = ft_count_space(form->prec, str, '0');
		str = ft_strjoin(prec, tmp);
		ft_free_res(tmp, prec, NULL);
	}
	else if (form->dot == 1 && u == 0 && form->prec == 0 && form->nprec == 0)
		str = "";
	ft_writed(form, str);
}

void	ft_type_x(unsigned int x, char sym, t_form *form)
{
	char	*str;
	char	*tmp;
	char	*prec;

	if (sym == 'x')
		str = ft_str_tolower(ft_itoa_base(x, 16));
	else if (sym == 'X')
		str = ft_itoa_base(x, 16);
	if (form->prec > ft_strlen(str))
	{
		tmp = str;
		prec = ft_count_space(form->prec, str, '0');
		str = ft_strjoin(prec, tmp);
		ft_free_res(tmp, prec, NULL);
	}
	else if (form->dot == 1 && x == 0 && form->prec == 0 && form->nprec == 0)
		str = "";
	ft_writed(form, str);
}
