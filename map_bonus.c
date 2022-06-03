/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:09:43 by mkoch             #+#    #+#             */
/*   Updated: 2022/03/02 12:15:47 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_symbol_bonus(struct s_map *m, int i, int j)
{
	if (!((m->map_arr[i][j] == '1') || (m->map_arr[i][j] == '0') || \
	(m->map_arr[i][j] == 'P') || (m->map_arr[i][j] == 'C') || \
	(m->map_arr[i][j] == 'E') || (m->map_arr[i][j] == 'V')))
		write_exit("Error\nUnknown symbol\n");
	if (((i == 0) || (i == m->map_h - 1) || (j == 0) || \
	(j == m->map_w - 1)) && (m->map_arr[i][j] != '1'))
		write_exit("Error\nNo walls at the edges\n");
	if (m->map_arr[i][j] == 'P')
	{
		m->num_pl++;
		m->pl_x = j;
		m->pl_y = i;
	}
	if (m->map_arr[i][j] == 'C')
		m->num_cl++;
	if (m->map_arr[i][j] == 'E')
		m->num_ex++;
	return ;
}

void	check_map(struct s_map *m)
{
	int	i;
	int	j;

	i = 0;
	while (i < m->map_h)
	{
		j = 0;
		while (j < m->map_w)
			check_symbol_bonus(m, i, j++);
		i++;
	}
	if (m->num_pl != 1)
		write_exit("Error\nNumber of players must be 1!\n");
	if (m->num_cl < 1)
		write_exit("Error\nNumber of collectables < 1!\n");
	if (m->num_ex < 1)
		write_exit("Error\nNumber of exits < 1!\n");
	return ;
}

void	ft_gnl(struct s_map *m, char **line, char **map_str, int fd)
{
	char	*tmp;

	*map_str = *line;
	*line = get_next_line(fd);
	while (*line)
	{
		if (((*line)[m->map_w] == '\n') && (ft_strlen(*line) != 1) && \
		((int)ft_strlen(*line) != m->map_w + 1))
			write_exit("Error\nNot rectangular!\n");
		else if (((*line)[m->map_w] != '\n') && \
		(ft_strlen(*line) != 1) && ((int)ft_strlen(*line) != m->map_w))
			write_exit("Error\nNot rectangular!\n");
		tmp = *map_str;
		*map_str = ft_strjoin(*map_str, *line);
		free(tmp);
		free(*line);
		if (*line[0] != '\n')
			m->map_h++;
		*line = get_next_line(fd);
	}
}

char	**map_processing(int fd, struct s_map *m)
{
	char	*line;
	char	*map_str;
	char	*str;

	m->num_pl = 0;
	m->num_cl = 0;
	m->num_ex = 0;
	str = ft_substr(m->map_path, ft_strlen(m->map_path) - 4, 4);
	if (ft_strncmp(str, ".ber", 4) != 0)
		write_exit("Error\nWrong map filename!\n");
	free(str);
	line = get_next_line(fd);
	while (line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	m->map_w = ft_strlen(line) - 1;
	m->map_h = 1;
	ft_gnl(m, &line, &map_str, fd);
	m->map_arr = ft_split(map_str, '\n');
	free(map_str);
	check_map(m);
	return (m->map_arr);
}

void	draw_a_map_bonus(struct s_map *m)
{
	int	i;
	int	j;

	i = 0;
	while (i < m->map_h)
	{
		j = 0;
		while (j < m->map_w)
			j = draw_a_texture_bonus(m, i, j);
		i++;
	}
}
