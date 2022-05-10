/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantavar <dantavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 00:46:28 by dantavar          #+#    #+#             */
/*   Updated: 2022/05/10 20:11:21 by dantavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_to_main_str(int fd, char *main_str)
{
	char	*buff;
	int		readb;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	readb = 1;
	while (!ft_strchr(main_str, '\n') && readb != 0)
	{
		readb = read(fd, buff, BUFFER_SIZE);
		if (readb == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[readb] = '\0';
		main_str = ft_strjoin(main_str, buff);
	}
	free(buff);
	return (main_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*main_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	main_str = ft_read_to_main_str(fd, main_str);
	if (!main_str)
		return (NULL);
	line = ft_get_line(main_str);
	main_str = ft_new_main_str(main_str);
	return (line);
}
