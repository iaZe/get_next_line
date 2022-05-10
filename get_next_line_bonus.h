/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantavar <dantavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:41:51 by dantavar          #+#    #+#             */
/*   Updated: 2022/05/10 20:24:44 by dantavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *main_str, char *buff);
char	*ft_get_line(char *main_str);
char	*ft_new_main_str(char *main_str);
char	*ft_read_to_main_str(int fd, char *main_str);
char	*get_next_line(int fd);

#endif