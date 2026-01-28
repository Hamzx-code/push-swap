/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 22:33:15 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/28 17:00:17 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <unistd.h>

static char	*read_chunk(int fd)
{
	char	*buffer;
	ssize_t	bytes;

	buffer = malloc((1024 + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes = read(fd, buffer, 1024);
	if (bytes <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytes] = '\0';
	return (buffer);
}

char	*read_buffer(int fd, char *buffer_operations)
{
	char	*tmp;
	char	*chunk;

	chunk = read_chunk(fd);
	if (!chunk)
		return (NULL);
	while (chunk)
	{
		if (!buffer_operations)
			buffer_operations = ft_strdup(chunk);
		else
		{
			tmp = buffer_operations;
			buffer_operations = ft_strjoin(tmp, chunk);
			free(tmp);
		}
		free(chunk);
		if (!buffer_operations)
			return (NULL);
		chunk = read_chunk(fd);
	}
	return (buffer_operations);
}
