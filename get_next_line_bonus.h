/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:20:31 by kmoutaou          #+#    #+#             */
/*   Updated: 2021/12/03 14:58:33 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		ft_check_newline(char *str);
char	*get_line(char *text);
char	*get_afternewline_line(char *text);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		check_test(int test, char *buff);
char	*ft_substr(char *s, int start, int len);
char	*ft_strdup(char *s1);

#endif
