/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammar <iammar@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:01:06 by iammar            #+#    #+#             */
/*   Updated: 2024/11/16 20:48:23 by iammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*str[FD_MAX];
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = (char *)malloc(BUFFER_SIZE + 1);
	if (!tmp)
	{
		if (str[fd])
			free(str[fd]);
		str[fd] = NULL;
		return (NULL);
	}
	str[fd] = read_file(fd, tmp, str[fd]);
	free(tmp);
	return (get_line(&str[fd]));
}

// int	main(void)
// {
// 	int fd = open("file.txt", O_RDONLY);
// 	int fd1 = open("file1.txt", O_RDONLY);
// 	int fd2 = open("file2.txt", O_RDONLY);
// 	char *line;
// 	line = get_next_line(fd);
// 		printf("%s", line);
// 	line = get_next_line(fd2);
// 	printf("%s", line);
// 	line = get_next_line(fd1);
// 	printf("%s", line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	line = get_next_line(fd2);
// 	printf("%s", line);
// 	line = get_next_line(fd1);
// 	printf("%s", line);
// 	close(fd);
// 	return (0);
// }