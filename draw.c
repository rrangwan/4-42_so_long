/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:05:07 by rrangwan          #+#    #+#             */
/*   Updated: 2022/04/25 12:16:26 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_map(t_game *game)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			c = game->map[i][j];
			draw2(c, j, i, game);
			j++;
		}
		i++;
	}
	return (0);
}

void	draw2(char c, int i, int j, t_game *game)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->img_1, i * PIX, j * PIX);
	if (c == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->img_0, i * PIX, j * PIX);
	if (c == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->img_c, i * PIX, j * PIX);
	if (c == 'P')
	{
		game->px = j;
		game->py = i;
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->img_p, i * PIX, j * PIX);
	}
	if (c == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->img_e, i * PIX, j * PIX);
}
