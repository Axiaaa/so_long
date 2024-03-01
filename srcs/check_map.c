/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:01:09 by lcamerly          #+#    #+#             */
/*   Updated: 2024/03/01 18:19:58 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	is_rectangle(t_so_long *so_long)
{
	size_t	i;
	size_t	len_str;

	i = 1;
	len_str = ft_strlen(so_long->game.map[0]);
	while (so_long->game.map[i] != NULL)
	{
		if (len_str != ft_strlen(so_long->game.map[i]))
			exit_error(so_long, "Error\nMap invalid (Not a rectangle)", MAP_ISNT_RECTANGLE);
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
			exit_error(so_long, "Error\nMap invalid (Verticales Walls 1)", WALL_ISSUE);
		i++;
	}
	i = 0;
	while (i < (size_t)map_len(*so_long) - 1)
	{
		if (so_long->game.map[i][ft_strlen(so_long->game.map[0]) - 1] != '1')
			exit_error(so_long, "Error\nMap invalid (Verticales Walls 2)", WALL_ISSUE);
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
			exit_error(so_long, "Error\nMap invalid (Horizontales Walls 1)", WALL_ISSUE);
		i++;
	}
	i = 0;
	while (so_long->game.map[map_len(*so_long) - 1][i])
	{
		if (so_long->game.map[map_len(*so_long) - 1][i] != '1')
			exit_error(so_long, "Error\nMap invalid (Horizontales Walls 2)", WALL_ISSUE);
		i++;
	}
}

void	char_check(t_so_long *so_long, char c, size_t i, size_t j)
{
	if (c == 'C')
		so_long->r_map.items += 1;
	else if (c == 'P')
	{
		so_long->r_map.player_spawn += 1;
		so_long->player.cords.x = i * SPRITE_SIZE;
		so_long->player.cords.y = j * SPRITE_SIZE;
	}
	else if (c == 'E')
		so_long->r_map.exit += 1;
	else if (c != 'G' && c != '1' && c != '0')	
		exit_error(so_long, "Unknown character in the map !\n", UNKNOW_CHAR);
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
	exit_error(so_long, "Error\nMap invalid (Requirements not fullfilled)", REQUIREMENTS_ISSUE);
}
