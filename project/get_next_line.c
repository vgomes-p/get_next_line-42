/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:55:51 by vigomes-          #+#    #+#             */
/*   Updated: 2026/05/13 10:55:51 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*gnl_free(char *store, char *buf)
{
	free(store);
	free(buf);
	return (NULL);
}

static char	*gnl_read(int fd, char *store)
{
	char	*temp;
	int		i;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	i = 1;
	while (!gnl_strchr(store, '\n') && i > 0)
	{
		i = read(fd, temp, BUFFER_SIZE);
		if (i < 0)
			return (gnl_free(store, temp));
		if (i == 0)
			break ;
		temp[i] = '\0';
		store = gnl_strjoin(store, temp);
	}
	free (temp);
	return (store);
}

static char	*gnl_get_current_line(char *store)
{
	int		i;
	char	*line;

	i = 0;
	if (!store[i])
		return (NULL);
	while (store[i] && store[i] != '\n')
		i++;
	line = gnl_substr(store, 0, i + (store[i] == '\n'));
	return (line);
}

static char	*gnl_trimmer(char *store)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (store[i] && store[i] != '\n')
		i++;
	if (!store[i])
	{
		free(store);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(store) - i + 1));
	if (!str)
		return (NULL);
	i++;
	while (store[i])
		str[j++] = store[i++];
	str[j] = '\0';
	free (store);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*store;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	store = gnl_read(fd, store);
	if (!store)
		return (NULL);
	line = gnl_get_current_line(store);
	store = gnl_trimmer(store);
	return (line);
}
