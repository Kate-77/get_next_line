/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 06:05:51 by kmoutaou          #+#    #+#             */
/*   Updated: 2021/12/02 06:45:30 by kmoutaou         ###   ########.fr       */
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
char	*get_save(char *text)
{
	char	*r;
	int		i;

	if(!text)
		return (NULL);
	while(text[i] && text[i] != '\n')
		i++;
	if(text[i] == '\n')
		i++;

}
*/

char	*get_newline_line(char *text)
{
	int	i;
	int j;
	char *r;
	
	if(!text)
		return (NULL);
	i = 0;
	while (text[i] && text[i] != '\n')
		i++;
	if(i == ft_strlen(text))
		return (NULL);
	if(text[i] == '\n')
		i++;
	j = i;
	while(text[j])
		j++;
	r = ft_substr(text, i, j);
	return (r);
}

char	*get_line(char *text)
{
	int		i;
	char	*line0;

	i = 0;
	line0 = NULL;
	if (!text)
		return (NULL);
	while (text[i] && text[i] != '\n')
		i++;
	if (text[i] == '\n')
		i++;
	if (i == 0)
		return (NULL);
	line0 = ft_substr(text, 0, i);
	return (line0);
}

char	*get_next_line(int fd)
{
	char			*buff;
	static char		*text0;
	char			*line;
	int				test;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (buff);
	test = 1;
	while (!ft_check_newline(text0) && test > 0)
	{
		test = read(fd, buff, BUFFER_SIZE);
		if(test < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[test] = '\0';
		text0 = ft_strjoin(text0, buff);
	}
	free(buff);
	line = get_line(text0);
	text0 = get_newline_line(text0);
	if(!line && text0)
		free(text0);
	return (line);
}
/*
#include <stdio.h>
int	main()
{
	int	fd;
	char *s;

	
	//char *line = get_newline_line("this not a file this \n just a line !");
	printf("%s \n", ft_strjoin("test this", NULL));
	printf("%s \n", ft_strjoin(NULL, NULL));
	printf("%s \n", ft_strjoin(NULL, "test this"));
	
	
	fd = open ("lorem.txt", O_RDONLY);
	//printf("1- %s", get_next_line(fd));
	int i = 0;
	
	while ( i < 120 )
	{
		printf("1- %s", get_next_line(fd));
		i++;
	}
	
}*/
