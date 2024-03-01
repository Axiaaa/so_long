/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 01:16:29 by lcamerly          #+#    #+#             */
/*   Updated: 2024/03/01 17:29:27 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	exit_error(t_so_long *so_long, char *s, t_errors code)
{
	ft_putstr_fd(s, 2);
	if (so_long->game.map)
		free_map(so_long->game.map);
	exit(code);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map[i]);
	free(map);
}

void	check_ber(char *filename)
{
	int	i;

	i = ft_strlen(filename);
	if (filename[i - 1] != 'r' || filename[i - 2] != 'e' || filename[i
			- 3] != 'b' || filename[i - 4] != '.')
	{
		ft_putstr_fd("Error\nWrong file extension", 1);
		exit(1);
	}
}

t_so_long	init_so_long(void)
{
	t_so_long	so_long;

	so_long.r_map.exit = 0;
	so_long.r_map.items = 0;
	so_long.r_map.player_spawn = 0;
	so_long.game.map = NULL;
	so_long.player.items = 0;
	so_long.player.mooves = 0;
	so_long.player.sprite_state = 0;
	return (so_long);
}

int	main(int ac, char **av)
{
	t_so_long	so_long;

	so_long = init_so_long();
	if (ac == 2)
		parsing(&so_long, av[1]);
	else
		exit_error(&so_long, "Wrong number of argument !\n./so_long [map]", WRONG_ARG_NUM);
	check_global_map(&so_long);
	map_size(&so_long);
	if (flood_fill(av[1], &so_long.r_map, (t_coordinate){so_long.player.cords.x
			/ SPRITE_SIZE, so_long.player.cords.y / SPRITE_SIZE},
		(t_coordinate){ft_strlen(so_long.game.map[0]), map_len(so_long)}))
		init_map(&so_long);
	else
		exit_error(&so_long, "Error\nMap invalid (No acces to exit or items)\n", CANT_ACCESS);
	return (0);
}
