/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:20:15 by kmoutaou          #+#    #+#             */
/*   Updated: 2021/12/02 06:32:55 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s12;
	int		i;
	int		j;
	int		size;
	
	if (!s2 && !s1)
		return (NULL);
	if(!s1)
		return (ft_strdup(s2));
	if(!s2)
		return (ft_strdup(s1));

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	s12 = (char *)malloc(sizeof(char) * size);
	if (!s12)
		return (s12);
	i = 0;
	if (s1)
	{
		while (s1[i])
		{
			s12[i] = s1[i];
			i++;
		}
	}
	j = 0;
	while (s2[j])
		s12[i++] = s2[j++];
	s12[i] = '\0';
	free(s1);
	return (s12);
}

char	*ft_strdup(char *s1)
{
	char	*s1_temp;
	char	*s2;
	int		i;

	s1_temp = (char *)s1;
	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s2)
		return (s2);
	i = 0;
	while (s1_temp[i])
	{
		s2[i] = s1_temp[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*s2;
	int		i;
	int		l;
	int		size;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	size = l - start;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len < l - start)
		size = len;
	s2 = (char *)malloc(sizeof(char) * (size + 1));
	if (!s2)
		return (0);
	i = 0;
	while (i < (int)len && s[start])
		s2[i++] = s[start++];
	s2[i] = '\0';
	return (s2);
}
