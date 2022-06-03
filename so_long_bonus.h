/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:53:22 by mkoch             #+#    #+#             */
/*   Updated: 2022/02/26 14:03:16 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h> 
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include "get_next_line.h"
# include "libft/libft.h"

struct s_map {
	char	**map_arr;
	int		map_w;
	int		map_h;
	int		num_pl;
	int		num_cl;
	int		num_ex;
	int		pl_x;
	int		pl_y;
	int		steps;
	char	*steps_print;
	char	*map_path;
	void	*mlx;
	void	*win;
	void	*i_sp;
	void	*i_wl;
	void	*i_plr;	
	void	*i_pll;
	void	*i_ex;
	void	*i_exo;
	void	*i_cl;
	void	*i_en;
	int		i_w;
	int		i_h;
};

int		exit_hook(struct s_map *m);
void	*ft_free(char **res);
void	put_image(struct s_map *m, void	**img, int x, int y);
void	change_exit(struct s_map *m);
void	draw_a_map_bonus(struct s_map *m);
int		draw_a_texture_bonus(struct s_map *m, int i, int j);
int		key_hook_bonus(int key_code, struct s_map *m);
int		ft_move_ud_lr_bonus(struct s_map *m, int ud, int lr);
void	if_next_sp_bonus(struct s_map *m, int ud, int lr);
void	if_next_cl_bonus(struct s_map *m, int ud, int lr);
void	if_next_ex_bonus(struct s_map *m, int ud, int lr);
void	check_symbol_bonus(struct s_map *m, int i, int j);
void	check_map(struct s_map *m);
void	ft_gnl(struct s_map *m, char **line, char **map_str, int fd);
char	**map_processing(int fd, struct s_map *m);
void	write_exit(char *str);
void	plus_step_bonus(struct s_map *m);

#endif