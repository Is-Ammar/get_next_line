/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammar <iammar@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:00:50 by iammar            #+#    #+#             */
/*   Updated: 2024/11/16 16:45:56 by iammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*get_line(char **str);
char	*ft_strdup(char *str);
char	*read_file(int fd, char *tmp, char *str);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
#endif