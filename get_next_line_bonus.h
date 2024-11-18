/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammar <iammar@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:01:11 by iammar            #+#    #+#             */
/*   Updated: 2024/11/11 20:01:11 by iammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef FD_MAX
#  define FD_MAX 13370
# endif
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*get_linee(char **str);
char	*ft_strdup(char *str);
char	*read_file(int fd, char *tmp, char *str);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*join_and_free(char *str, char *tmp);
char	*extract_line(char **str, size_t len);
#endif
