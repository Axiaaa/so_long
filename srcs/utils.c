/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:34:30 by lcamerly          #+#    #+#             */
/*   Updated: 2024/03/01 18:14:55 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	delete_newline(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '\n')
				map[i][j] = '\0';
			j++;
		}
		i++;
	}
}

void	sprite_init(t_so_long *so_long)
{
	so_long->game.player_sprite1.ptr = mlx_xpm_file_to_image(so_long->vars.mlx,
			PACMAN_SPRITE,
			&so_long->game.player_sprite1.width,
			&so_long->game.player_sprite1.height);
	so_long->game.player_sprite2.ptr = mlx_xpm_file_to_image(so_long->vars.mlx,
			PACMAN_SPRITE2,
			&so_long->game.player_sprite2.width,
			&so_long->game.player_sprite2.height);
	so_long->game.player_sprite3.ptr = mlx_xpm_file_to_image(so_long->vars.mlx,
			PACMAN_SPRITE3,
			&so_long->game.player_sprite3.width,
			&so_long->game.player_sprite3.height);
	so_long->game.player_sprite4.ptr = mlx_xpm_file_to_image(so_long->vars.mlx,
			PACMAN_SPRITE4,
			&so_long->game.player_sprite4.width,
			&so_long->game.player_sprite4.height);
}

void	sprite_init2(t_so_long *so_long)
{
	so_long->game.wall.ptr = mlx_xpm_file_to_image(so_long->vars.mlx,
			WALL_SPRITE,
			&so_long->game.wall.width,
			&so_long->game.wall.height);
	so_long->game.grass.ptr = mlx_xpm_file_to_image(so_long->vars.mlx,
			BACKGROUND_SPRITE,
			&so_long->game.grass.width,
			&so_long->game.grass.height);
	so_long->game.exit.ptr = mlx_xpm_file_to_image(so_long->vars.mlx,
			EXIT_SPRITE,
			&so_long->game.exit.width,
			&so_long->game.exit.height);
	so_long->game.item.ptr = mlx_xpm_file_to_image(so_long->vars.mlx,
			ITEM_SPRITE,
			&so_long->game.item.width,
			&so_long->game.item.height);
	so_long->game.ghost.ptr = mlx_xpm_file_to_image(so_long->vars.mlx,
			GHOST_SPRITE,
			&so_long->game.ghost.width,
			&so_long->game.ghost.height);
}

int	flood_fill(char *str, t_map_requirements *reqs, t_coordinate player_pos,
		t_coordinate witdhheight)
{
	char	**map;
	int		nb;

	reqs->access_items = 0;
	reqs->access_exit = 0;
	nb = pre_read(str);
	map = malloc(sizeof(char *) * (nb + 1));
	read_file(map, str, nb);
	check_items(map, reqs, player_pos, witdhheight);
	free_map(map);
	map = malloc(sizeof(char *) * (nb + 1));
	read_file(map, str, nb);
	check_exit(map, reqs, player_pos, witdhheight);
	free_map(map);
	if (reqs->access_exit == 1 && reqs->access_items == reqs->items)
		return (1);
	return (0);
}

void	check_map_size(t_so_long *so_long)
{
	if (map_len(*so_long) > 15 || ft_strlen(so_long->game.map[0]) > 30)
		exit_error(so_long, "Error\nMap too big\n", MAP_TOO_BIG);
}
