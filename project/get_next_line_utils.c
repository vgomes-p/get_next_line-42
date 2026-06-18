/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:55:47 by vigomes-          #+#    #+#             */
/*   Updated: 2026/05/13 10:55:47 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *st)
{
	size_t	i;

	i = 0;
	while (st[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*gnl_strchr(char const *st, int c)
{
	int		i;
	char	*base;

	if (!st || !c)
		return (NULL);
	i = 0;
	base = (char *)st;
	while (base[i])
	{
		if (base[i] == (char)c)
			return (&base[i]);
		i++;
	}
	return (0);
}

char	*gnl_strjoin(char *st1, char *st2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!st1)
	{
		st1 = malloc(sizeof(char));
		st1[0] = '\0';
	}
	str = malloc((ft_strlen(st1) + ft_strlen(st2)) + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (st1[i])
	{
		str[i] = st1[i];
		i++;
	}
	while (st2[j])
		str[i++] = st2[j++];
	str[i] = '\0';
	free(st1);
	return (str);
}

char	*gnl_substr(char const *st, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = malloc(len + 1);
	if (!str)
		return (NULL);
	if (!st)
		return (NULL);
	i = start;
	j = 0;
	while (i < ft_strlen(st) && j < len)
		str[j++] = st[i++];
	str[j] = '\0';
	return (str);
}
