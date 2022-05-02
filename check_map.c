/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:05:01 by rrangwan          #+#    #+#             */
/*   Updated: 2022/04/25 11:41:31 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->width)
	{
		if (game->map[0][i] != '1')
			return (1);
		if (game->map[game->height - 1][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < game->height)
	{
		if (game->map[i][game->width - 1] != '1')
			return (1);
		if (game->map[i][0] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_epc(t_game *game, char e)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == e)
				c++;
			j++;
		}
		i++;
	}
	return (c);
}

int	check_epc2(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0' && \
			game->map[i][j] != 'E' && game->map[i][j] != 'P' \
			&& game->map[i][j] != 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	check_epc3(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'P')
			{
				game->py = i;
				game->px = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

int	check_char(t_game *game)
{
	game->ectn = check_epc(game, 'E');
	game->pctn = check_epc(game, 'P');
	game->cctn = check_epc(game, 'C');
	if (game->pctn != 1 || game->cctn == 0 || game->ectn == 0)
		return (1);
	if (check_epc2(game))
		return (1);
	check_epc3(game);
	return (0);
}
