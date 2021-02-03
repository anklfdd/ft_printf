/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:10:39 by gavril            #+#    #+#             */
/*   Updated: 2021/01/20 21:16:42 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_skip(t_form *form, const char *str)
{
	int ind;

	ind = 0;
	while (str[ind] == '-' || str[ind] == '0' || str[ind] == ' ')
	{
		if (str[ind] == '-')
			form->minus = 1;
		else if (str[ind] == '0')
			form->zero = 1;
		else if (str[ind] == ' ')
			form->space = 1;
		ind++;
	}
	return (ind);
}

int		ft_pars_width(t_form *form, const char *str, int ind, va_list arg)
{
	long long int	val;

	if (ft_isdigit(str[ind]))
	{
		form->width = ft_atoi(&(str[ind]));
		ind = ind + ft_count_num((long long int)form->width);
	}
	else if (str[ind] == '*')
	{
		val = (int)va_arg(arg, int);
		if (val < 0)
		{
			form->minus = 1;
			form->width = (-1) * val;
		}
		else
			form->width = (unsigned long int)val;
		ind++;
	}
	return (ind);
}

int		ft_pars_prec(t_form *form, const char *str, int ind, va_list arg)
{
	long long int	val;

	ind++;
	form->dot = 1;
	while (str[ind] == '0')
		ind++;
	if (ft_isdigit(str[ind]))
	{
		form->prec = ft_atoi(&(str[ind]));
		ind = ind + ft_count_num(form->prec);
	}
	else if (str[ind] == '*')
	{
		val = (int)va_arg(arg, int);
		if (val >= 0)
			form->prec = (unsigned long int)val;
		else
			form->nprec = val;
		ind++;
	}
	else if (str[ind] == '-')
		ind = ind + ft_count_num(ft_atoi(&(str[ind])));
	return (ind);
}

int		ft_parser(const char *str, va_list arg, t_form *form)
{
	int				ind;

	ind = 0;
	while (str[ind] != '\0')
	{
		if (str[ind] == '%')
		{
			ft_f_list_init(form);
			ind++;
			ind = ind + ft_skip(form, &(str[ind]));
			ind = ft_pars_width(form, str, ind, arg);
			if (str[ind] == '.')
				ind = ft_pars_prec(form, str, ind, arg);
			ft_check_type(str[ind], arg, form);
		}
		else
		{
			ft_putchar(str[ind]);
			form->ret += 1;
		}
		ind++;
	}
	return (0);
}
