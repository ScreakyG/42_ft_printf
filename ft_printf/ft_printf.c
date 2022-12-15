/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francois <francois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:43:29 by francois          #+#    #+#             */
/*   Updated: 2022/12/13 02:55:31 by francois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

int	ft_format(va_list ap, const char format)
{
	int	len;

	len = 0;
	if (format == 's')
		len += ft_putstrlen(va_arg(ap, char *));
	if (format == 'c')
		len += ft_putcharlen(va_arg(ap, int));
	if (format == 'd' || format == 'i')
		len += ft_putnbrlen(va_arg(ap, int));
	if (format == 'x' || format == 'X')
		len += ft_puthexlen(va_arg(ap, unsigned int), format);
	if (format == 'p')
		len += ft_printpointer(va_arg(ap, unsigned long));
	if (format == 'u')
		len += ft_uitoa(va_arg(ap, unsigned int));
	if (format == '%')
	{
		write (1, "%", 1);
		len += 1;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		lentotal;
	va_list	ap;

	i = 0;
	lentotal = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			lentotal += ft_format(ap, str[i + 1]);
			i++;
		}
		else
			lentotal += ft_putcharlen(str[i]);
		i++;
	}
	va_end(ap);
	return (lentotal);
}
