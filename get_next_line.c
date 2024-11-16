/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammar <iammar@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:00:44 by iammar            #+#    #+#             */
/*   Updated: 2024/11/16 21:21:05 by iammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *tmp, char *str)
{
	int	bytes_read;

	while (!ft_strchr(str, '\n'))
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(str);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		tmp[bytes_read] = '\0';
		str = ft_strjoin(str, tmp);
		if (!str)
			return (NULL);
	}
	return (str);
}

char	*get_line(char **str)
{
	char	*line;
	char	*new_str;
	size_t	len;

	len = 0;
	if (!*str || **str == '\0')
		return (NULL);
	while ((*str)[len] && (*str)[len] != '\n')
		len++;
	if ((*str)[len] == '\n')
		len++;
	line = (char *)malloc(len + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, *str, len);
	line[len] = '\0';
	new_str = ft_strdup(*str + len);
	free(*str);
	*str = new_str;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = (char *)malloc(BUFFER_SIZE + 1);
	if (!tmp)
	{
		if (str)
			free(str);
		str = NULL;
		return (NULL);
	}
	str = read_file(fd, tmp, str);
	free(tmp);
	return (get_line(&str));
}

// int	main(void)
// {
// 	int fd = open("file.txt", O_RDONLY);

// 	char *line;
// 	if ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }