/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:01:09 by lcamerly          #+#    #+#             */
/*   Updated: 2024/01/18 14:34:53 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	is_rectangle(t_so_long *so_long)
{
	size_t	i;
	size_t	len_str;

	i = 0;
	len_str = 0;
	while (so_long->game.map[i] != NULL)
	{
		if (len_str == 0)
			len_str = ft_strlen(so_long->game.map[i]);
		if (len_str != ft_strlen(so_long->game.map[i]))
		{
			ft_putstr_fd("Error\nMap invalid (Not a rectangle)", 2);
			exit_error(so_long);
		}
		i++;
	}
}

void	check_verticales_wall(t_so_long *so_long)
{
	size_t	i;

	i = 0;
	while (i < (size_t)map_len(*so_long) - 1)
	{
		if (so_long->game.map[i][0] != '1')
		{
			ft_putstr_fd("Error\nMap invalid (Verticales Walls 1)", 2);
			exit_error(so_long);
		}
		i++;
	}
	i = 0;
	while (i < (size_t)map_len(*so_long) - 1)
	{
		if (so_long->game.map[i][ft_strlen(so_long->game.map[0]) - 1] != '1')
		{
			ft_putstr_fd("Error\nMap invalid (Verticales Walls 2)", 2);
			exit_error(so_long);
		}
		i++;
	}
}

void	check_horizontales_wall(t_so_long *so_long)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(so_long->game.map[0]) - 1)
	{
		if ((char)so_long->game.map[0][i] != '1')
		{
			ft_putstr_fd("Error\nMap invalid (Horizontales Walls 1)", 2);
			exit_error(so_long);
		}
		i++;
	}
	i = 0;
	while (so_long->game.map[map_len(*so_long) - 1][i])
	{
		if (so_long->game.map[map_len(*so_long) - 1][i] != '1')
		{
			ft_putstr_fd("Error\nMap invalid (Horizontales Walls 2)", 2);
			exit_error(so_long);
		}
		i++;
	}
}

void	char_check(t_so_long *so_long, char c, size_t i, size_t j)
{
	if (c == 'C')
		so_long->r_map.items += 1;
	if (c == 'P')
	{
		so_long->r_map.player_spawn += 1;
		so_long->player.cords.x = i * SPRITE_SIZE;
		so_long->player.cords.y = j * SPRITE_SIZE;
	}
	if (c == 'E')
		so_long->r_map.exit += 1;
}

void	check_global_map(t_so_long *so_long)
{
	size_t	i;
	size_t	j;

	i = 0;
	check_horizontales_wall(so_long);
	check_verticales_wall(so_long);
	is_rectangle(so_long);
	j = 0;
	while (so_long->game.map[j])
	{
		i = 0;
		while (so_long->game.map[j][i] != '\0')
		{
			char_check(so_long, so_long->game.map[j][i], i, j);
			i++;
		}
		j++;
	}
	if (so_long->r_map.exit == 1 && so_long->r_map.player_spawn == 1
		&& so_long->r_map.items >= 1)
		return ;
	ft_putstr_fd("Error\nMap invalid (Requirements not fullfilled)", 2);
	exit_error(so_long);
}
