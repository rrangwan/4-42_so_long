/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:05:34 by rrangwan          #+#    #+#             */
/*   Updated: 2022/04/28 15:54:24 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init(t_game *game, char *map)
{
	game->height = 1;
	game->width = ft_strlen(map);
	game->map = (char **)malloc(sizeof(char *) * 1);
	if (!game->map)
		ft_error2("Malloc issues", game);
	game->map[0] = map;
}

void	map_expand(t_game *game, char *map)
{
	char	**ret;
	char	**temp;
	int		i;

	i = 0;
	temp = game->map;
	ret = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!ret)
		ft_error2("Malloc issues", game);
	while (i < game->height)
	{
		ret[i] = temp[i];
		i++;
	}
	ret[i] = map;
	free(game->map);
	game->map = ret;
	game->height++;
}

void	load_map(t_game *game)
{
	char	*temp;

	temp = get_next_line(game->fd);
	if (temp)
		init(game, temp);
	else
	{
		free(game);
		ft_error("Map issues\n");
	}
	temp = get_next_line(game->fd);
	while (temp)
	{
		map_expand(game, temp);
		temp = get_next_line(game->fd);
	}
	close(game->fd);
}

void	check_map(t_game *game)
{
	if (check_walls(game) || check_char(game) || check_rec(game))
		ft_error2("Map is not valid\n", game);
}
