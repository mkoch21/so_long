/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:53:22 by mkoch             #+#    #+#             */
/*   Updated: 2021/11/17 16:53:22 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h> 
# include <unistd.h> 
# include <fcntl.h>
# include <stdlib.h>

# define BUFFER_SIZE 10

size_t	ft_strlen_gnl(const char *s);
char	*ft_strjoin_gnl(char *s1, char const *s2);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup_n(char *s1, int plus_n);
char	*get_next_line(int fd);

#endif