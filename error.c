/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:05:22 by rrangwan          #+#    #+#             */
/*   Updated: 2022/04/28 15:57:21 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_g(t_game *game)
{
	int	i;

	i = 0;
	if (game->map[0])
	{
		while (i < game->height)
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
	free(game);
}

void	ft_error(char	*str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	exit(1);
}

void	ft_error2(char	*str, t_game *game)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	if (game)
		free_g(game);
	exit(1);
}

int	check_args(int argc, char **argv)
{
	char	*ext;
	int		fd;

	if (argc != 2)
		ft_error("Wrong number of arguments\n");
	fd = open(argv[1], O_DIRECTORY);
	if (fd != -1)
		ft_error("Not a file\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error("Can't access file\n");
	ext = ft_strchr(argv[1], '.');
	if (ft_strncmp(ext, ".ber", 4) != 0)
		ft_error("Wrong map extention\n");
	return (fd);
}

int	check_rec(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		if (ft_strlen(game->map[i]) != game->width)
			return (1);
		i++;
	}
	if (game->height == game->width)
		return (1);
	return (0);
}
