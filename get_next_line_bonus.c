/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabtaour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:29:10 by yabtaour          #+#    #+#             */
/*   Updated: 2021/12/09 13:48:16 by yabtaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*ft_read(int fd, char *str)
{
	char	*line;
	int		len;

	line = malloc(1 + BUFFER_SIZE);
	if (!line)
		return (NULL);
	len = 1;
	while (!ft_strchr_bonus(str, '\n') && len)
	{
		len = read(fd, line, BUFFER_SIZE);
		if (len == -1)
		{
			free(line);
			return (NULL);
		}
		line[len] = '\0';
		str = ft_strjoin_bonus(str, line);
	}
	free(line);
	return (str);
}

char	*ft_get_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str[0])
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_get_rest(char *str)
{
	char	*line;
	int		i;
	int		j;
	int		len;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	len = ft_strlen_bonus(&str[i + 1]);
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	j = 0;
	i++;
	while (str[i] != '\0')
		line[j++] = str[i++];
	line[j] = '\0';
	free(str);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*current_line[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	current_line[fd] = ft_read(fd, current_line[fd]);
	if (!current_line[fd])
		return (NULL);
	line = ft_get_line(current_line[fd]);
	current_line[fd] = ft_get_rest(current_line[fd]);
	return (line);
}
