/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammar <iammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 21:37:15 by iammar            #+#    #+#             */
/*   Updated: 2024/10/04 22:16:10 by iammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 3


char *get_next_line(int fd)
{
    char *buffer;
    char *line;
    char temp[BUFFER_SIZE + 1];
    int bytes_read;
    int line_len;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    line = ft_calloc(1, sizeof(char)); 
    if (!line)
        return (NULL);

    while ((bytes_read = read(fd, temp, BUFFER_SIZE)) > 0)
    {
        temp[bytes_read] = '\0'; 
        buffer = ft_strjoin(line, temp); 
        free(line);
        line = buffer;
        
        if (ft_strchr(temp, '\n'))
            break;
    }


    if (bytes_read < 0 || (bytes_read == 0 && ft_strlen(line) == 0))
    {
        free(line);
        return (NULL);
    }

    return (line);
}
