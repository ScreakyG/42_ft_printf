/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francois <francois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:45:37 by francois          #+#    #+#             */
/*   Updated: 2022/11/29 19:23:05 by francois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

static int		ft_countnbr(unsigned int nb)
{
	int	count;

	count = 0;
	while (nb != 0)
	{
		count++;
		nb = nb / 16;
	}
	return (count);
}

static char	*ft_fill(unsigned int nb, char *str, int size, const char format)
{
	str[size] = '\0';
	size--;
	while (nb != 0)
	{
		if ((nb % 16) > 9)
		{
			if (format == 'X')
				str[size] = (55 + (nb % 16));
			if (format == 'x')
				str[size] = (87 + (nb % 16));
		}
		else
		{
			str[size] = ('0' + (nb % 16));
		}
		nb = nb / 16;
		size--;
	}
	return (str);
}

static char	*ft_itoa_hex(unsigned int nb, const char format)
{
	char	*str;
	int		size;

	size = ft_countnbr(nb);
	str = malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str = ft_fill(nb, str, size, format);
	return (str);
}

int	ft_puthexlen(unsigned int nb, const char format)
{
	char	*str;
	int		len;

	if (nb == 0)
		return (write(1, "0", 1));
	str = ft_itoa_hex(nb, format);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);	
}
