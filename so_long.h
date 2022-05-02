/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:05:46 by rrangwan          #+#    #+#             */
/*   Updated: 2022/04/27 22:00:44 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "mlx/mlx.h"
# define PIX 32
# define RIGHT 2
# define LEFT 0
# define DOWN 1
# define UP 13
# define ESC 53

typedef struct s_game
{
	int		fd;
	char	**map;
	int		height;
	int		width;
	int		px;
	int		py;
	int		pctn;
	int		ectn;
	int		cctn;
	void	*mlx_ptr;
	void	*mlx_win;
	int		steps;
	int		c_taken;
	void	*img_p;
	void	*img_c;
	void	*img_e;
	void	*img_1;
	void	*img_0;
}				t_game;

void	ft_error(char	*str);
void	ft_error2(char	*str, t_game *game);
int		check_args(int argc, char **argv);
void	init(t_game *game, char *map);
void	init_game(t_game *game);
void	init_img(t_game *game);
int		draw_map(t_game *game);
void	draw2(char c, int i, int j, t_game *game);
void	destroy_map(t_game *game);
void	map_expand(t_game *game, char *map);
void	load_map(t_game *game);
int		check_char(t_game *game);
int		check_epc(t_game *game, char e);
int		check_epc2(t_game *game);
void	check_epc3(t_game *game);
int		check_rec(t_game *game);
int		check_walls(t_game *game);
void	check_map(t_game *game);
void	free_g(t_game *game);
int		steps(int move, t_game *game);
void	steps2(t_game *game, char c, int x, int y);
void	steps3(t_game *game);
int		exit_game(t_game *game);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_strlen(char *str);
char	*ft_strchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_arraylen(char **map);
char	*get_next_line(int fd);

#endif
