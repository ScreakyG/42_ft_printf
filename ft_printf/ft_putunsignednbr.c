/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignednbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francois <francois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:14:24 by francois          #+#    #+#             */
/*   Updated: 2022/12/02 19:57:29 by francois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

static char	*ft_uitoa_fill(unsigned int nb, int size, char *str)
{
	while (nb > 0)
	{
		str[size] = '0' + (nb % 10);
		size--;
		nb = nb / 10;
	}
	return (str);
}

static int	ft_countnbr(unsigned int nb)
{
	int	count;

	count = 0;
	while (nb > 9)
	{
		count++;
		nb  = nb / 10;
	}
	count++;
	return (count);
}

int	ft_uitoa(unsigned int nb)
{
	char	*str;
	int	len;
	int	size;

	if (nb == 0)
		return (write(1, "0", 1));
	size = ft_countnbr(nb);
	str = malloc((size + 1) * sizeof(char));
	str[size] = '\0';
	size--;
	ft_uitoa_fill(nb, size, str);
	if (str == NULL)
		return (0);
	len = ft_putstrlen(str);
	free(str);
	return (len);
}
