/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francois <francois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:02:13 by francois          #+#    #+#             */
/*   Updated: 2022/12/01 17:36:06 by francois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"
#include <stdint.h>

static int	ft_countnbr(uintptr_t num)
{
	int count;

	count = 0;
	while (num != 0)
	{
		count++;
		num = num / 16;
	}
	return (count);
}

static char	*ft_fillptr(char *str, uintptr_t num, int size)
{
	str[size] = '\0';
	size--;
	while (num != 0)
	{
		if ((num % 16) > 9)
			str[size] = (87 + (num % 16));
		else 
			str[size] = '0' + (num % 16);
		size--;
		num = num / 16;
	}
	return (str);
}

static char *ft_itoa_ptr(uintptr_t num)
{
	int	count;
	char	*str;

	count = ft_countnbr(num);
	str = malloc((count + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str = ft_fillptr(str, num, count);
	return (str);
}

int	ft_printpointer(unsigned long nb)
{
	int	len;
	char	*str;

	len = 0;
	len += write(1, "0x", 2);
	if (nb == 0)
	{
		len += write(1, "0", 1);
		return (len);
	}
	str = ft_itoa_ptr(nb);
	ft_putstr_fd(str, 1);
	len += ft_strlen(str);
	free(str);
	return (len);
}
