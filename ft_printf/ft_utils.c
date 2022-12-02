/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francois <francois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:38:14 by francois          #+#    #+#             */
/*   Updated: 2022/12/02 20:50:57 by francois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"


int	ft_putstrlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putcharlen(int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putnbrlen(int nb)
{
	char	*temp;
	int	len;

	len = 0;
	if (nb == 0)
	{
		len += write(1, "0", 1);
		return (len);
	}
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	temp = ft_itoa(nb);
	len = ft_putstrlen(temp);
	free(temp);
	return (len);
}
