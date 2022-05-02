/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:05:58 by rrangwan          #+#    #+#             */
/*   Updated: 2022/04/25 09:55:31 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_arraylen(char **map)
{
	int		i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	ln;

	ln = n;
	if (ln < 0)
	{
		ln = -ln;
		ft_putchar_fd('-', fd);
	}
	if (ln > 9)
		ft_putnbr_fd(ln / 10, fd);
	ft_putchar_fd(ln % 10 + '0', fd);
}
