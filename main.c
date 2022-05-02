/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:05:41 by rrangwan          #+#    #+#             */
/*   Updated: 2022/04/27 21:42:35 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		ft_error("Malloc failed\n");
	game->fd = check_args(argc, argv);
	load_map(game);
	check_map(game);
	init_game(game);
	mlx_key_hook(game->mlx_win, &steps, game);
	mlx_hook(game->mlx_win, 17, 0, &exit_game, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
