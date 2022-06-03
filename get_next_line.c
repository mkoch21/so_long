/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:06:19 by mkoch             #+#    #+#             */
/*   Updated: 2022/02/24 14:35:40 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	check_num_of_bytes(int *num_of_bytes, char ***line, int **line_fin)
{
	if (*num_of_bytes == -1)
	{
		**line_fin = -1;
		return ;
	}
	else if (*num_of_bytes == 0)
	{
		**line_fin = 1;
		if ((***line) == '\0')
		{
			free(**line);
			**line = NULL;
		}	
	}
}

static void	check_line(char ***line, int **line_fin)
{
	if (!(**line))
		**line_fin = -1;
	else
		**line_fin = 1;
}

static void	rem_is_absent(int fd, char **line, char **remainder, int *line_fin)
{
	int		num_of_bytes;
	char	buf[BUFFER_SIZE + 1];
	char	*ptr_next_line;

	num_of_bytes = read(fd, buf, BUFFER_SIZE);
	check_num_of_bytes(&num_of_bytes, &line, &line_fin);
	buf[num_of_bytes] = '\0';
	ptr_next_line = ft_strchr_gnl(buf, '\n');
	if (ptr_next_line)
	{
		*ptr_next_line = '\0';
		*line = ft_strjoin_gnl(*line, buf);
		check_line(&line, &line_fin);
		*remainder = ft_strdup_n(++ptr_next_line, 0);
		if (!(*remainder))
			*line_fin = -1;
		*line = ft_strdup_n(*line, 1);
	}
	else
	{
		*line = ft_strjoin_gnl(*line, buf);
		if (!(*line))
			*line_fin = -1;
	}
}

static void	rem_is_present(char **line, char **remainder, int *line_fin)
{
	char	*ptr_next_line;

	ptr_next_line = NULL;
	ptr_next_line = ft_strchr_gnl(*remainder, '\n');
	if (ptr_next_line)
	{
		*ptr_next_line = '\0';
		*line = ft_strdup_n(*remainder, 0);
		check_line(&line, &line_fin);
		if (*ptr_next_line + 1)
			*remainder = ft_strcpy(*remainder, ++ptr_next_line);
		else
			free(*remainder);
		*line = ft_strdup_n(*line, 1);
	}
	else
	{
		*line = ft_strdup_n(*remainder, 0);
		if (!(*line))
			*line_fin = -1;
		free(*remainder);
		*remainder = NULL;
	}	
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remainder;
	int			line_fin;

	if ((fd < 0) || (fd > 8192) || (BUFFER_SIZE <= 0))
		return (NULL);
	line_fin = 0;
	if (remainder)
		rem_is_present(&line, &remainder, &line_fin);
	else
	{
		line = (char *)malloc(sizeof(char) * 1);
		if (!line)
			return (NULL);
		*line = '\0';
	}
	while (!remainder && (line_fin == 0))
		rem_is_absent(fd, &line, &remainder, &line_fin);
	if (line_fin == -1)
	{
		free(line);
		return (NULL);
	}	
	return (line);
}
