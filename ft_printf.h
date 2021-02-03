/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 17:56:15 by gavril            #+#    #+#             */
/*   Updated: 2021/01/20 21:23:28 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <stddef.h>
# include <unistd.h>

typedef struct			s_form
{
	unsigned long int	width;
	int					minus;
	int					zero;
	unsigned long int	prec;
	int					space;
	int					ret;
	int					dot;
	int					nprec;
}						t_form;

int						ft_printf(const char *str, ...);
int						ft_parser(const char *str, va_list arg, t_form *form);
char					*ft_itoa_pointer(unsigned long long p);
char					*ft_count_space(unsigned long int pw,
char *str, char zero_or_space);
void					ft_check_type(char sym, va_list arg, t_form *form);
void					ft_f_list_init(t_form *form);
void					ft_type_x(unsigned int x, char sym, t_form *form);
void					ft_type_u(unsigned int u, t_form *form);
void					ft_type_d(int nbr, t_form *form);
void					ft_type_p(unsigned long long point, t_form *form);
void					ft_writed(t_form *form, char *str);
void					ft_free_res(char *res, char *str, char *space);
void					ft_putstr(char *s);
void					ft_putchar(char c);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_substr(char const *s,
unsigned int start, size_t len);
char					*ft_itoa(int n);
char					*ft_itoa_base(unsigned int n, int sys);
char					*ft_strdup(const char *str);
char					*ft_str_tolower(char *str);
size_t					ft_strlen(const char *str);
int						ft_isdigit(int sym);
int						ft_atoi(const char *str);
int						ft_count_num(long long int n);
int						ft_tolower(int sym);
int						ft_strncmp(const char *str1,
const char *str2, size_t num);

#endif
