/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_id.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 20:16:41 by gavril            #+#    #+#             */
/*   Updated: 2021/01/20 20:47:17 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_prec(t_form *form, int nbr)
{
	char	*tmp;
	char	*prec;
	char	*res;
	char	*str;

	str = ft_itoa(nbr);
	if (nbr >= 0 && form->prec > ft_strlen(str))
	{
		prec = ft_count_space(form->prec, str, '0');
		tmp = str;
		str = ft_strjoin(prec, tmp);
		ft_free_res(tmp, prec, NULL);
	}
	else if (nbr < 0 && form->prec >= ft_strlen(str))
	{
		tmp = ft_substr(str, 1, ft_strlen(str));
		prec = ft_count_space(form->prec, tmp, '0');
		res = ft_strjoin(prec, tmp);
		ft_free_res(str, NULL, NULL);
		str = ft_strjoin("-", res);
		ft_free_res(tmp, prec, res);
	}
	else if (form->dot == 1 && nbr == 0 && form->prec == 0 && form->nprec == 0)
		str = "";
	return (str);
}

char		*ft_write_d(t_form *form, char *str, char *space, int nbr)
{
	char	*tmp;
	char	*tmp2;
	char	*res;

	if (nbr < 0 && form->zero == 1 && ((form->dot == 0
	&& form->prec == 0) || form->nprec < 0))
	{
		tmp2 = ft_substr(str, 1, ft_strlen(str));
		tmp = ft_strjoin(space, tmp2);
		res = ft_strjoin("-", tmp);
		ft_putstr(res);
		ft_free_res(tmp, tmp2, NULL);
	}
	else
	{
		res = ft_strjoin(space, str);
		ft_putstr(res);
	}
	return (res);
}

void		ft_type_d(int nbr, t_form *form)
{
	char	*space;
	char	*str;
	char	*res;

	str = ft_prec(form, nbr);
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
		res = ft_write_d(form, str, space, nbr);
	form->ret += ft_strlen(space) + ft_strlen(str);
	ft_free_res(res, str, space);
}
