/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:05:50 by rrangwan          #+#    #+#             */
/*   Updated: 2022/04/27 22:02:10 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	steps(int move, t_game *game)
{
	int		x;
	int		y;
	char	c;

	x = game->px;
	y = game->py;
	if (move == LEFT)
		y--;
	if (move == RIGHT)
		y++;
	if (move == UP)
		x--;
	if (move == DOWN)
		x++;
	if (move == ESC)
		exit_game(game);
	c = game->map[x][y];
	steps2(game, c, x, y);
	return (0);
}

void	steps3(t_game *game)
{
	write(1, "\033c", 3);
	ft_putstr_fd("Steps taken: ", 1);
	ft_putnbr_fd(game->steps, 1);
	write(1, "\n", 1);
}

void	steps2(t_game *game, char c, int x, int y)
{
	if (c == 'C' || c == '0')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->img_0, game->py * PIX, game->px * PIX);
		game->map[game->px][game->py] = '0';
		game->px = x;
		game->py = y;
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->img_p, game->py * PIX, game->px * PIX);
		game->map[game->px][game->py] = 'P';
		game->steps++;
		steps3(game);
		if (c == 'C')
			game->c_taken++;
	}
	if (c == 'E' && (game->c_taken == game->cctn))
	{
		game->steps++;
		steps3(game);
		ft_putstr_fd("Congrats, You Won\n", 1);
		exit_game(game);
	}
}

int	exit_game(t_game *game)
{
	destroy_map(game);
	free_g(game);
	ft_putstr_fd("Game Ended\n", 1);
	exit(0);
	return (0);
}
