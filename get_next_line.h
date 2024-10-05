/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammar <iammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:24:19 by iammar            #+#    #+#             */
/*   Updated: 2024/10/04 22:16:26 by iammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

#define BUFFER_SIZE 3

char  *get_next_line(int fd);
void    *ft_calloc(size_t count, size_t size);
char *ft_strjoin(char *s1, char *s2);
int ft_strlen(const char *s);
void *ft_calloc(size_t count, size_t size);
#endif