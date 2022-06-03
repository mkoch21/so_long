/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:55:31 by mkoch             #+#    #+#             */
/*   Updated: 2022/03/02 12:40:09 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move_ud_lr(struct s_map *m, int ud, int lr)
{
	if (m->map_arr[m->pl_y + ud][m->pl_x + lr] == '1')
		return (1);
	else if (m->map_arr[m->pl_y + ud][m->pl_x + lr] == '0')
		if_next_sp(m, ud, lr);
	else if (m->map_arr[m->pl_y + ud][m->pl_x + lr] == 'C')
		if_next_cl(m, ud, lr);
	else if (m->map_arr[m->pl_y + ud][m->pl_x + lr] == 'E')
		if_next_ex(m, ud, lr);
	return (0);
}

int	ft_move_lr(struct s_map *m, int lr)
{
	if (m->map_arr[m->pl_y][m->pl_x + lr] == '1')
		return (1);
	else if (m->map_arr[m->pl_y][m->pl_x + lr] == '0')
		if_next_sp(m, 0, lr);
	else if (m->map_arr[m->pl_y][m->pl_x + lr] == 'C')
		if_next_cl(m, 0, lr);
	else if (m->map_arr[m->pl_y][m->pl_x + lr] == 'E')
		if_next_ex(m, 0, lr);
	return (0);
}

void	if_next_sp(struct s_map *m, int ud, int lr)
{
	put_image(m, m->i_sp, m->pl_x * m->i_w, m->pl_y * m->i_h);
	if (m->map_arr[m->pl_y][m->pl_x] == 'F')
	{
		put_image(m, m->i_ex, m->pl_x * m->i_w, m->pl_y * m->i_h);
		m->map_arr[m->pl_y][m->pl_x] = 'E';
	}
	else
		m->map_arr[m->pl_y][m->pl_x] = '0';
	m->pl_x = m->pl_x + lr;
	m->pl_y = m->pl_y + ud;
	m->map_arr[m->pl_y][m->pl_x] = 'P';
	m->steps++;
	ft_putstr_fd("Number of steps: ", 1);
	ft_putnbr_fd(m->steps, 1);
	ft_putchar_fd('\n', 1);
	if (lr == 0)
		put_image(m, m->i_plr, m->pl_x * m->i_w, m->pl_y * m->i_h);
	else if (lr == -1)
		put_image(m, m->i_pll, m->pl_x * m->i_w, m->pl_y * m->i_h);
	else if (lr == 1)
		put_image(m, m->i_plr, m->pl_x * m->i_w, m->pl_y * m->i_h);
}

void	if_next_cl(struct s_map *m, int ud, int lr)
{
	put_image(m, m->i_sp, m->pl_x * m->i_w, m->pl_y * m->i_h);
	if (m->map_arr[m->pl_y][m->pl_x] == 'F')
	{
		put_image(m, m->i_ex, m->pl_x * m->i_w, m->pl_y * m->i_h);
		m->map_arr[m->pl_y][m->pl_x] = 'E';
	}
	else
		m->map_arr[m->pl_y][m->pl_x] = '0';
	m->num_cl--;
	m->pl_x = m->pl_x + lr;
	m->pl_y = m->pl_y + ud;
	m->map_arr[m->pl_y][m->pl_x] = 'P';
	put_image(m, m->i_sp, m->pl_x * m->i_w, m->pl_y * m->i_h);
	m->steps++;
	ft_putstr_fd("Number of steps: ", 1);
	ft_putnbr_fd(m->steps, 1);
	ft_putchar_fd('\n', 1);
	if (lr == 0)
		put_image(m, m->i_plr, m->pl_x * m->i_w, m->pl_y * m->i_h);
	else if (lr == -1)
		put_image(m, m->i_pll, m->pl_x * m->i_w, m->pl_y * m->i_h);
	else if (lr == 1)
		put_image(m, m->i_plr, m->pl_x * m->i_w, m->pl_y * m->i_h);
	if (m->num_cl == 0)
		change_exit(m);
}

void	if_next_ex(struct s_map *m, int ud, int lr)
{
	m->steps++;
	ft_putstr_fd("Number of steps: ", 1);
	ft_putnbr_fd(m->steps, 1);
	ft_putchar_fd('\n', 1);
	if (m->num_cl == 0)
	{
		mlx_destroy_window(m->mlx, m->win);
		ft_putstr_fd("You win!\n", 1);
		ft_free(m->map_arr);
		exit(0);
	}
	else
	{
		put_image(m, m->i_sp, m->pl_x * m->i_w, m->pl_y * m->i_h);
		m->map_arr[m->pl_y][m->pl_x] = '0';
		m->pl_x = m->pl_x + lr;
		m->pl_y = m->pl_y + ud;
		m->map_arr[m->pl_y][m->pl_x] = 'F';
		if (lr == 0)
			put_image(m, m->i_plr, m->pl_x * m->i_w, m->pl_y * m->i_h);
		else if (lr == -1)
			put_image(m, m->i_pll, m->pl_x * m->i_w, m->pl_y * m->i_h);
		else if (lr == 1)
			put_image(m, m->i_plr, m->pl_x * m->i_w, m->pl_y * m->i_h);
	}
}
