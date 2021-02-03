/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 23:50:46 by gavril            #+#    #+#             */
/*   Updated: 2021/01/20 21:36:15 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_free_res(char *res, char *str, char *space)
{
	if (res && !(ft_strncmp(res, "", 2) == 0))
	{
		free(res);
		res = NULL;
	}
	if (str && !(ft_strncmp(str, "", 2) == 0))
	{
		free(str);
		str = NULL;
	}
	if (space && !(ft_strncmp(space, "", 2) == 0))
	{
		free(space);
		space = NULL;
	}
}

void	ft_type_c(char c, t_form *form)
{
	char	*space;

	if (form->width > 0)
		form->width--;
	space = ft_count_space(form->width, "", ' ');
	if (form->minus == 1)
	{
		write(1, &c, 1);
		ft_putstr(space);
	}
	else
	{
		ft_putstr(space);
		write(1, &c, 1);
	}
	form->ret += ft_strlen(space) + 1;
	ft_free_res(NULL, NULL, space);
}

void	ft_type_s(char *str, t_form *form)
{
	char	*space;
	char	*res;

	if (str == NULL)
		str = "(null)";
	if (form->prec > 0)
		str = ft_substr(str, 0, form->prec);
	else if (form->dot == 1 && form->prec == 0 && form->nprec == 0)
		str = "";
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
	ft_free_res(res, NULL, space);
	if (form->prec > 0)
		ft_free_res(str, NULL, NULL);
}

void	ft_percent(char sym, t_form *form)
{
	char	str[2];
	char	*space;
	char	*res;

	str[0] = sym;
	if (form->zero == 1 && form->minus == 0)
		space = ft_count_space(form->width, str, '0');
	else
		space = ft_count_space(form->width, str, ' ');
	if (form->minus == 1)
		res = ft_strjoin(str, space);
	else
		res = ft_strjoin(space, str);
	form->ret += ft_strlen(space) + 1;
	ft_putstr(res);
	ft_free_res(res, space, NULL);
}

void	ft_check_type(char sym, va_list arg, t_form *form)
{
	if (sym == 'c')
		ft_type_c((char)va_arg(arg, int), form);
	else if (sym == 's')
		ft_type_s((char*)va_arg(arg, char*), form);
	else if (sym == 'p')
		ft_type_p((unsigned long long)va_arg(arg, unsigned long long), form);
	else if (sym == 'd' || sym == 'i')
		ft_type_d((int)va_arg(arg, int), form);
	else if (sym == 'u')
		ft_type_u((unsigned int)va_arg(arg, unsigned int), form);
	else if (sym == 'x' || sym == 'X')
		ft_type_x((unsigned int)va_arg(arg, unsigned int), sym, form);
	else if (sym == '%')
		ft_percent('%', form);
}
