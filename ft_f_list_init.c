/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_list_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 19:28:17 by gavril            #+#    #+#             */
/*   Updated: 2021/01/20 20:40:26 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_f_list_init(t_form *form)
{
	form->minus = 0;
	form->width = 0;
	form->prec = 0;
	form->zero = 0;
	form->dot = 0;
	form->nprec = 0;
	form->space = 0;
}
