/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:06:15 by mkoch             #+#    #+#             */
/*   Updated: 2022/03/02 12:14:30 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	write_exit(char *str)
{
	write(1, str, ft_strlen(str));
	exit(1);
}

int	key_hook_bonus(int key_code, struct s_map *m)
{
	if ((key_code == 13) || (key_code == 126))
		return (ft_move_ud_lr_bonus(m, -1, 0));
	if ((key_code == 1) || (key_code == 125))
		return (ft_move_ud_lr_bonus(m, 1, 0));
	if ((key_code == 0) || (key_code == 123))
		return (ft_move_ud_lr_bonus(m, 0, -1));
	if ((key_code == 2) || (key_code == 124))
		return (ft_move_ud_lr_bonus(m, 0, 1));
	if (key_code == 53)
		exit_hook(m);
	return (0);
}

void	images_to_struct(struct s_map *m)
{
	m->i_sp = mlx_xpm_file_to_image(m->mlx, "./imgs/s.xpm", &m->i_w, &m->i_h);
	m->i_wl = mlx_xpm_file_to_image(m->mlx, "./imgs/w.xpm", &m->i_w, &m->i_h);
	m->i_plr = mlx_xpm_file_to_image(m->mlx, "./imgs/pr.xpm", &m->i_w, &m->i_h);
	m->i_pll = mlx_xpm_file_to_image(m->mlx, "./imgs/pl.xpm", &m->i_w, &m->i_h);
	m->i_ex = mlx_xpm_file_to_image(m->mlx, "./imgs/e.xpm", &m->i_w, &m->i_h);
	m->i_exo = mlx_xpm_file_to_image(m->mlx, "./imgs/eo.xpm", &m->i_w, &m->i_h);
	m->i_cl = mlx_xpm_file_to_image(m->mlx, "./imgs/c.xpm", &m->i_w, &m->i_h);
	m->i_en = mlx_xpm_file_to_image(m->mlx, "./imgs/en.xpm", &m->i_w, &m->i_h);
}

int	draw_a_texture_bonus(struct s_map *m, int i, int j)
{
	if (m->map_arr[i][j] == '1')
		put_image(m, m->i_wl, (j++) * m->i_w, i * m->i_h);
	else
	{
		put_image(m, m->i_sp, j * m->i_w, i * m->i_h);
		if (m->map_arr[i][j] == 'P')
			put_image(m, m->i_plr, j * m->i_w, i * m->i_h);
		else if (m->map_arr[i][j] == 'E')
			put_image(m, m->i_ex, j * m->i_w, i * m->i_h);
		else if (m->map_arr[i][j] == 'C')
			put_image(m, m->i_cl, j * m->i_w, i * m->i_h);
		else if (m->map_arr[i][j] == 'V')
			put_image(m, m->i_en, j * m->i_w, i * m->i_h);
		j++;
	}
	return (j);
}

int	main(int argc, char **argv)
{
	struct s_map	m;
	int				fd;

	if (argc != 2)
		write_exit("Error\nWrong input!\n");
	m.map_path = argv[1];
	m.steps = 0;
	fd = open(m.map_path, O_RDONLY);
	if (fd == -1)
		write_exit("Error\nfd error!\n");
	m.map_arr = map_processing(fd, &m);
	close(fd);
	m.mlx = mlx_init();
	images_to_struct(&m);
	m.win = mlx_new_window(m.mlx, m.i_w * m.map_w, m.i_h * m.map_h, "So_long");
	draw_a_map_bonus(&m);
	mlx_hook(m.win, 2, 0, key_hook_bonus, &m);
	mlx_hook(m.win, 17, 0, &exit_hook, &m);
	mlx_loop(m.mlx);
}
