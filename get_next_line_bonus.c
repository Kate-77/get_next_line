/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 06:05:51 by kmoutaou          #+#    #+#             */
/*   Updated: 2021/12/03 21:47:18 by kmoutaou         ###   ########.fr       */
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

char	*get_afternewline_line(char *text)
{
	int		i;
	int		j;
	char	*line;

	if (!text)
		return (NULL);
	i = 0;
	while (text[i] && text[i] != '\n')
		i++;
	if (i == ft_strlen(text))
	{
		free(text);
		return (NULL);
	}
	if (text[i] == '\n')
		i++;
	j = i;
	while (text[j])
		j++;
	line = ft_substr(text, i, j);
	free(text);
	return (line);
}

char	*get_line(char *text)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	if (!text)
		return (NULL);
	while (text[i] && text[i] != '\n')
		i++;
	if (text[i] == '\n')
		i++;
	if (i == 0)
		return (NULL);
	line = ft_substr(text, 0, i);
	return (line);
}

int	check_test(int test, char *buff)
{
	if (test < 0)
	{
		free(buff);
		return (1);
	}
	else
		return (0);
}

char	*get_next_line(int fd)
{
	char			*buff;
	static char		*text[1024];
	char			*line;
	int				test;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (buff);
	test = 1;
	while (!ft_check_newline(text[fd]) && test > 0)
	{
		test = read(fd, buff, BUFFER_SIZE);
		if (check_test(test, buff))
			return (NULL);
		buff[test] = '\0';
		text[fd] = ft_strjoin(text[fd], buff);
	}
	free(buff);
	line = get_line(text[fd]);
	text[fd] = get_afternewline_line(text[fd]);
	return (line);
}
