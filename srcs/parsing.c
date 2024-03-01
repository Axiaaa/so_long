/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:17:27 by lcamerly          #+#    #+#             */
/*   Updated: 2024/03/01 17:43:12 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error in ft_open_file ");
		exit(1);
		return (1);
	}
	else
		return (fd);
}

int	close_file(int file)
{
	int	file_closed;

	file_closed = close(file);
	if (file_closed == -1)
	{
		perror("Error in ft_close_file : ");
		return (1);
		exit(1);
	}
	return (0);
}

int	pre_read(char *filename)
{
	int		fd;
	char	*line;
	int		i;

	fd = open_file(filename);
	i = 0;
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		if (line)
			i++;
		free(line);
	}
	close_file(fd);
	return (i);
}

void	read_file(char **map, char *filename, size_t line_nb)
{
	size_t	i;
	int		fd;

	fd = open_file(filename);
	i = 0;
	while (i <= line_nb)
		map[i++] = get_next_line(fd);
	delete_newline(map);
	close_file(fd);
}

void	parsing(t_so_long *so_long, char *filename)
{
	int	map_len;

	check_ber(so_long, filename);
	map_len = pre_read(filename);
	so_long->game.map = malloc(sizeof(char *) * (map_len + 1));
	read_file(so_long->game.map, filename, map_len);
}
