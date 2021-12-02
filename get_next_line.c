/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 06:05:51 by kmoutaou          #+#    #+#             */
/*   Updated: 2021/12/02 04:45:30 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_newline(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}
/*
char	*get_line(char *text)
{
	int		i;
	int		j;
	char	*line;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (text[i] && text[i] != '\n')
		i++;
	j = i;
	k = i;
	while (text[j])
	{
		j++;
	}
	line = ft_substr(text, 0, i);
	text = ft_substr(text, k, j);
	return (line);
}
*/
char	*get_newline_line(char *text)
{
	int	i;
	int	index0;
	int	index1;

	i = 0;
	index0 = 0;
	index1 = 0;
	if (ft_check_newline(text))
	{
		while (text[i])
		{
			if (text[i] == '\n')
			{
				index0 = i + 1;
				index1 = i + 1;
			}
			i++;
		}
	}
	while (text[index0])
	{
		index0++;
	}
	text = ft_substr(text, index1, index0);
	return (text);
}

char	*get_line(char **text)
{
	int		i;
	char	*line0;
	char	*line1;

	i = 0;
	line0 = NULL;
	if (!(*text))
		return (NULL);
	while ((*text)[i] && (*text)[i] != '\n')
		i++;
	if ((*text)[i] == '\n')
	{
		line0 = ft_substr(*text, 0, i + 1);
		line1 = ft_substr(*text, i + 1, ft_strlen(*text) - i - 1);
		*text = line1;
	}
	return (line0);
}

char	*get_next_line(int fd)
{
	char			*buff;
	static char		*text0;
	char			*text1;
	char			*line;
	int				test;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (buff);
	test = 1;
	while (test > 0)
	{
		test = read(fd, buff, BUFFER_SIZE);
		buff[test] = '\0';
		text0 = ft_strjoin(text0, buff);
		text1 = text0;
		if (ft_check_newline(text0))
		{
			line = get_line(&text0);
			break;
		}
		free(text1);
	}
	free(buff);
	return (line);
}

#include <stdio.h>
int	main()
{
	int	fd;
	char *s;

	fd = open ("t.txt", O_RDONLY);
	while ((s = get_next_line(fd)))
		printf("1- %s", get_next_line(fd));
}
