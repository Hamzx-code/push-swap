/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:13:20 by hhamidi           #+#    #+#             */
/*   Updated: 2025/11/27 15:57:12 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_count(char const *s, char c, int nb)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (nb == 1)
	{
		while (s[i])
		{
			if (s[i] != c && (i == 0 || s[i - 1] == c))
				count++;
			i++;
		}
	}
	else
	{
		while (s[count] && s[count] != c)
			count++;
	}
	return (count);
}

static char	*ft_strdup_word(char const *s, char c)
{
	size_t	i;
	char	*word;
	size_t	len;

	len = ft_count(s, c, 2);
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static	void	ft_free_buffers(char **tab, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static	char	**ft_add_words(char **tab, char const *s, char c, size_t nb)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] && j < nb)
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			tab[j] = ft_strdup_word(s + i, c);
			if (!tab[j])
			{
				ft_free_buffers(tab, j);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	nb_words;

	if (!s)
		return (NULL);
	nb_words = ft_count(s, c, 1);
	tab = malloc((nb_words + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	tab = ft_add_words(tab, s, c, nb_words);
	return (tab);
}
