/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francois <francois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:43:29 by francois          #+#    #+#             */
/*   Updated: 2022/11/24 19:28:29 by francois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "./libft/libft.h"
#include <stdio.h>

int	ft_printf(const char *str, ...)
{
    int	i;
	va_list	ap;
	char	*str_arg;

	i = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 's')
			{
				str_arg = va_arg(ap, char *);
				ft_putstr_fd(str_arg, 1);
				i++;
			}
			else if (str[i] == 'c')
			{
				ft_putchar_fd(va_arg(ap, int), 1);
				i++;
			}
			else if(str[i] == 'd')
			{
				ft_putnbr_fd(va_arg(ap, int), 1);
				i++;
			}
			else if(str[i] == '%')
			{
				ft_putchar_fd('%', 1);
				i++;
			}
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			i++;
		}
	
	}
	va_end(ap);
	return (i);
}
int	main()
{
	ft_printf("J'ai %d %s et %d %s\n", 100, "euros", -150, "dollars");
}