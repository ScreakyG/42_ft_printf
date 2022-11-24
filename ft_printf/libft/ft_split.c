/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francois <francois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:37:13 by francois          #+#    #+#             */
/*   Updated: 2022/11/22 17:35:02 by francois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*filltab(const char *str, char c, char *tab)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && (str[i] != c))
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

static char	**filltabtabsuite(const char *str, char c, char **tabtab)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	j = 0;
	index = 0;
	while (str[i] != '\0' && str[i] == c)
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			j = 0;
			while (str[i + j] != '\0' && str[i + j] != c)
				j++;
			tabtab[index] = malloc ((j + 1) * sizeof(char));
			tabtab[index] = filltab(&str[i], c, tabtab[index]);
			index++;
			i = i + j;
		}
	}
	return (tabtab);
}

static char	**filltabtab(const char *str, char c, char **tabtab)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	j = 0;
	index = 0;
	if (str[i] == '\0')
	{
		tabtab[index] = malloc ((j + 1) * sizeof(char));
		tabtab[index] = '\0';
	}
	else
		filltabtabsuite(str, c, tabtab);
	return (tabtab);
}

static int	nbmots(char const *str, char c)
{
	int	i;
	int	mots;

	i = 0;
	mots = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0' && (str[i] == c))
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == c && str[i + 1] != c)
			mots++;
		i++;
	}
	if (str[i] == '\0' && str[i - 1] != c)
		mots++;
	return (mots);
}

char	**ft_split(char const *s, char c)
{
	char	**tabtab;
	int		mots;

	if (s == 0)
		return (0);
	mots = nbmots(s, c);
	tabtab = malloc((mots + 1) * sizeof(char *));
	tabtab[mots] = '\0';
	tabtab = filltabtab(s, c, tabtab);
	return (tabtab);
}
