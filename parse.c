/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 20:00:11 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/14 19:17:14 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

//typedef struct s_list
//{
//	void		*content;
//	struct s_list	*next;
//} t_list;

//ft_strjoin
//ft_split


size_t  ft_strlen(const char *s)
{
        size_t  len;

        len = 0;
        while (s[len])
                len++;
        return (len);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len_total;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len_total = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	str = malloc(len_total * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
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

char	**ft_parse(int ac, char **av)
{
	char	**values;
	char	*elements;
	char	*tmp;
	int	i;

	i = 1;
	tmp = NULL;
	while (i <= ac)
	{
		elements = ft_strjoin(tmp, av[i]);
		free(tmp);
		tmp = elements;
		i++;
	}
	free(tmp);
	values = ft_split(elements, ' ');
	free(elements);
	return (values);
}

#include <stdio.h>
int main(int ac, char **av)
{
	char **tab;

	tab = ft_parse(ac, av);
	int	i = 0;
	while (tab[i])
	{
		printf("[%s]\n", tab[i]);
		i++;
	}
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
