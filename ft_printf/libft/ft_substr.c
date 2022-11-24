/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francois <francois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:51:26 by francois          #+#    #+#             */
/*   Updated: 2022/11/22 17:14:51 by francois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*newchaine;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	newchaine = malloc((len + 1) * sizeof(char));
	if (newchaine == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (j < len && i >= start)
		{
			newchaine[j] = str[i];
			j++;
		}
		i++;
	}
	newchaine[j] = '\0';
	return (newchaine);
}
