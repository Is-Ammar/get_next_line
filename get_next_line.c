/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammar <iammar@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:00:44 by iammar            #+#    #+#             */
/*   Updated: 2024/11/18 10:27:55 by iammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join_and_free(char *str, char *tmp)
{
	char	*new_str;

	new_str = ft_strjoin(str, tmp);
	if (!new_str)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	free(str);
	return (new_str);
}

char	*read_file(int fd, char *tmp, char *str)
{
	int		bytes_read;

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
		str = join_and_free(str, tmp);
		if (!str)
			return (NULL);
	}
	return (str);
}

char	*extract_line(char **str, size_t len)
{
	char	*line;
	char	*new_str;

	line = (char *)malloc(len + 1);
	if (!line)
	{
		free(*str);
		*str = NULL;
		return (NULL);
	}
	ft_memcpy(line, *str, len);
	line[len] = '\0';
	new_str = ft_strdup(*str + len);
	free(*str);
	*str = new_str;
	if (!new_str || *new_str == '\0')
	{
		free(new_str);
		*str = NULL;
	}
	return (line);
}

char	*get_linee(char **str)
{
	size_t	len;

	len = 0;
	if (!*str || **str == '\0')
		return (NULL);
	while ((*str)[len] && (*str)[len] != '\n')
		len++;
	if ((*str)[len] == '\n')
		len++;
	return (extract_line(str, len));
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
		free(str);
		str = NULL;
		return (NULL);
	}
	str = read_file(fd, tmp, str);
	free(tmp);
	if (!str)
		return (NULL);
	return (get_linee(&str));
}

// int	main(void)
// {
// 	int fd = open("file.txt", O_RDONLY);

// 	char *line;
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
