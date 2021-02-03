# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gavril <gavril@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/29 19:22:08 by alancel           #+#    #+#              #
#    Updated: 2021/01/20 21:49:42 by gavril           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRCS		=	ft_printf.c \
				ft_check_type.c \
				ft_count_space.c \
				ft_f_list_init.c \
				ft_itoa_pointer.c \
				ft_parser.c \
				ft_putstr.c \
				ft_strjoin.c \
				ft_substr.c \
				ft_itoa.c \
				ft_itoa_base.c \
				ft_strlen.c \
				ft_str_tolower.c \
				ft_putchar.c \
				ft_isdigit.c \
				ft_atoi.c \
				ft_count_num.c \
				ft_strdup.c \
				ft_tolower.c \
				ft_strncmp.c \
				ft_type_uxp.c \
				ft_check_flags.c \
				ft_type_id.c \


CC			=	gcc
	
OBJS		=	$(SRCS:.c=.o)

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

all:			$(NAME)

$(NAME):		$(OBJS)
				gcc -c $(SRCS)
				ar rc $(NAME) $^
				ranlib $(NAME)

%.o:			%.c
				$(CC) $(CFLAGS) -c $< -o $@ 

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re