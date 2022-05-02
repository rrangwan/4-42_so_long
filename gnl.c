/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:05:27 by rrangwan          #+#    #+#             */
/*   Updated: 2022/04/28 16:04:53 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_next_line(int fd)
{
	int		i[2];
	char	c;
	char	*buffer;

	i[0] = 0;
	buffer = malloc(4096);
	if (!buffer)
		return (NULL);
	i[1] = read(fd, &c, 1);
	while (i[1] > 0)
	{
		if (c == '\n')
			break ;
		buffer[i[0]] = c;
		i[0]++;
		i[1] = read(fd, &c, 1);
	}
	if ((!buffer[i[0] - 1] && !i[1]) || i[1] == -1)
	{
		free(buffer);
		return (NULL);
	}
	i[0]++;
	buffer[i[0]] = '\0';
	return (buffer);
}
