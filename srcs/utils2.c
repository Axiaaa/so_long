/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:35:14 by lcamerly          #+#    #+#             */
/*   Updated: 2024/01/18 14:36:49 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_items(char **map, t_map_requirements *reqs,
		t_coordinate player_pos, t_coordinate witdhheight)
{
	if (player_pos.x <= 0 || player_pos.y <= 0 || player_pos.x >= witdhheight.x
		|| player_pos.y >= witdhheight.y
		|| map[player_pos.y][player_pos.x] == '1'
		|| map[player_pos.y][player_pos.x] == 'Q'
		|| map[player_pos.y][player_pos.x] == 'G')
		return ;
	if (map[player_pos.y][player_pos.x] == 'C')
	{
		reqs->access_items += 1;
		map[player_pos.y][player_pos.x] = 'Q';
	}
	if (map[player_pos.y][player_pos.x] != '1')
		map[player_pos.y][player_pos.x] = 'Q';
	check_items(map, reqs, (t_coordinate){player_pos.x + 1, player_pos.y},
		witdhheight);
	check_items(map, reqs, (t_coordinate){player_pos.x - 1, player_pos.y},
		witdhheight);
	check_items(map, reqs, (t_coordinate){player_pos.x, player_pos.y + 1},
		witdhheight);
	check_items(map, reqs, (t_coordinate){player_pos.x, player_pos.y - 1},
		witdhheight);
}

void	check_exit(char **map, t_map_requirements *reqs,
		t_coordinate player_pos, t_coordinate witdhheight)
{
	if (player_pos.x <= 0 || player_pos.y <= 0 || player_pos.x >= witdhheight.x
		|| player_pos.y >= witdhheight.y
		|| map[player_pos.y][player_pos.x] == '1'
		|| map[player_pos.y][player_pos.x] == 'G'
		|| map[player_pos.y][player_pos.x] == 'Q')
		return ;
	if (map[player_pos.y][player_pos.x] == 'E')
	{
		reqs->access_exit += 1;
		map[player_pos.y][player_pos.x] = 'Q';
	}
	if (map[player_pos.y][player_pos.x] != '1')
		map[player_pos.y][player_pos.x] = 'Q';
	check_exit(map, reqs, (t_coordinate){player_pos.x + 1, player_pos.y},
		witdhheight);
	check_exit(map, reqs, (t_coordinate){player_pos.x - 1, player_pos.y},
		witdhheight);
	check_exit(map, reqs, (t_coordinate){player_pos.x, player_pos.y + 1},
		witdhheight);
	check_exit(map, reqs, (t_coordinate){player_pos.x, player_pos.y - 1},
		witdhheight);
}

int	map_len(t_so_long so_long)
{
	int	i;

	i = 0;
	while (so_long.game.map[i])
		i++;
	return (i);
}
