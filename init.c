/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:05:30 by rrangwan          #+#    #+#             */
/*   Updated: 2022/04/25 09:49:45 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img(t_game *game)
{
	int	x;
	int	y;

	game->img_p = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./image/p.xpm", &x, &y);
	game->img_e = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./image/e.xpm", &x, &y);
	game->img_c = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./image/c.xpm", &x, &y);
	game->img_1 = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./image/1.xpm", &x, &y);
	game->img_0 = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./image/0.xpm", &x, &y);
}

void	init_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx_ptr, game->width * PIX, \
	game->height * PIX, "So Long...");
	game->steps = 0;
	game->c_taken = 0;
	init_img(game);
	draw_map(game);
}
