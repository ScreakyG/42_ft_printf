/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francois <francois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:38:14 by francois          #+#    #+#             */
/*   Updated: 2022/11/25 23:05:58 by francois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libftprintf.h"


int	ft_putstrlen(char *str)
{
	int	i;

	i = 0;
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

	temp = ft_itoa(nb);
	len = ft_putstrlen(temp);
	free(temp);
	return (len);
}