/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francois <francois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 00:35:36 by francois          #+#    #+#             */
/*   Updated: 2022/11/22 16:20:26 by francois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*copy;
	size_t	i;
	size_t	len;

	len = ft_strlen(str);
	i = 0;
	copy = malloc((len + 1) * sizeof(char));
	if (!copy)
		return (0);
	while (str[i] != '\0')
	{
		copy[i] = str[i];
		i++;
	}
	return (copy);
}
