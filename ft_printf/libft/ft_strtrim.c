/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francois <francois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:56:30 by francois          #+#    #+#             */
/*   Updated: 2022/11/22 16:59:41 by francois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill(size_t size, size_t len, size_t i, const char *s1)
{
	size_t	j;
	char	*copy;

	j = 0;
	while (size < len)
		size++;
	copy = malloc((size + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	while (i < len)
	{
		copy[j] = s1[i];
		j++;
		i++;
	}
	copy[j] = '\0';
	return (copy);
}

static int	is_charset(char str, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (str == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;
	size_t	size;

	if (s1 == 0)
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	while (is_charset(s1[len - 1], (char *)set) == 1)
		len--;
	while (is_charset(s1[i], (char *)set) == 1)
		i++;
	size = i;
	return (fill(size, len, i, s1));
}
