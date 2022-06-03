/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:40:51 by mkoch             #+#    #+#             */
/*   Updated: 2022/02/26 13:18:10 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	exit_hook(struct s_map *m)
{
	mlx_destroy_window(m->mlx, m->win);
	ft_free(m->map_arr);
	exit(0);
	return (0);
}

void	*ft_free(char **res)
{
	int	i;

	i = 0;
	while (res[i])
		free(res[i++]);
	free(res);
	return (NULL);
}

void	put_image(struct s_map *m, void	**img, int x, int y)
{
	mlx_put_image_to_window(m->mlx, m->win, img, x, y);
}

void	change_exit(struct s_map *m)
{
	int	i;
	int	j;

	i = 0;
	while (i < m->map_h)
	{
		j = 0;
		while (j < m->map_w)
		{
			if (m->map_arr[i][j] == 'E')
				put_image(m, m->i_exo, j * m->i_w, i * m->i_h);
			j++;
		}
		i++;
	}
	return ;
}

void	plus_step_bonus(struct s_map *m)
{
	char	*tmp;

	m->steps++;
	put_image(m, m->i_wl, 0, 0);
	put_image(m, m->i_wl, 64, 0);
	tmp = ft_itoa(m->steps);
	m->steps_print = ft_strjoin("Steps: ", tmp);
	free(tmp);
	mlx_string_put(m->mlx, m->win, 0, 0, 1, m->steps_print);
	free(m->steps_print);
}
