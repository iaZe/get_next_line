/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantavar <dantavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:41:48 by dantavar          #+#    #+#             */
/*   Updated: 2022/05/10 20:24:45 by dantavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	a;

	a = 0;
	while (s[a] != '\0')
		a++;
	return (a);
}

char	*ft_strchr(char *s, int c)
{
	int	a;

	a = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[a] != '\0')
	{
		if (s[a] == (char)c)
			return ((char *)s + a);
		a++;
	}
	return (0);
}

char	*ft_strjoin(char *main_str, char *buff)
{
	size_t	i;
	size_t	a;
	char	*str;

	if (!main_str)
	{
		main_str = malloc(1 * sizeof(char));
		main_str[0] = '\0';
	}
	if (!main_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(main_str) + ft_strlen(buff) + 1));
	if (!str)
		return (NULL);
	i = -1;
	a = 0;
	if (main_str)
		while (main_str[++i] != '\0')
			str[i] = main_str[i];
	while (buff[a] != '\0')
		str[i++] = buff[a++];
	str[ft_strlen(main_str) + ft_strlen(buff)] = '\0';
	free(main_str);
	return (str);
}

char	*ft_get_line(char *main_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!main_str[i])
		return (NULL);
	while (main_str[i] && main_str[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (main_str[i] && main_str[i] != '\n')
	{
		str[i] = main_str[i];
		i++;
	}
	if (main_str[i] == '\n')
	{
		str[i] = main_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_main_str(char *main_str)
{
	int		i;
	int		a;
	char	*str;

	i = 0;
	while (main_str[i] && main_str[i] != '\n')
		i++;
	if (!main_str[i])
	{
		free(main_str);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(main_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	a = 0;
	while (main_str[i])
		str[a++] = main_str[i++];
	str[a] = '\0';
	free(main_str);
	return (str);
}
