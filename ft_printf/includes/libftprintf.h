/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francois <francois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:39:39 by francois          #+#    #+#             */
/*   Updated: 2022/12/06 02:34:10 by francois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const char *format, ...);
int	ft_formats(va_list ap, const char format);
int	ft_putstrlen(char *str);
int	ft_putcharlen(int c);
int	ft_putnbrlen(int nb);
int	ft_puthexlen(unsigned int nb, const char format);
int	ft_printpointer(unsigned long nb);
int	ft_uitoa(unsigned int nb);

#endif
