/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 20:00:11 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/14 00:16:18 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_list
{
	void		*content;
	struct s_list	*next;
} t_list;

int	ft_check_elements(char **arg)
{
	int	i
	int	j;

	i = 1;
}

char	**ft_parse(int ac, char **av)
{
	char	**elements;
	long	values[];

	elements = ft_split(arg);
	if (!elements)
		return (0);
}
