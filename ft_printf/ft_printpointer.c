/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francois <francois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:02:13 by francois          #+#    #+#             */
/*   Updated: 2022/11/29 21:23:38 by francois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"
#include <stdint.h>

void	ft_putptrlen(uintptr_t num)
{
	if (num >= 16)
	{
		ft_putptrlen(num / 16);
		ft_putptrlen(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	ft_printpointer(unsigned long nb)
{
	write(1, "0x", 2);
	ft_putptrlen(nb);
	return (0);
}