/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:05:07 by rrangwan          #+#    #+#             */
/*   Updated: 2022/04/27 22:12:10 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_map(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->img_0);
	mlx_destroy_image(game->mlx_ptr, game->img_1);
	mlx_destroy_image(game->mlx_ptr, game->img_c);
	mlx_destroy_image(game->mlx_ptr, game->img_p);
	mlx_destroy_image(game->mlx_ptr, game->img_e);
	mlx_clear_window(game->mlx_ptr, game->mlx_win);
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	free(game->mlx_ptr);
}
