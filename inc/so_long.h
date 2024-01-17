/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 23:08:52 by lcamerly          #+#    #+#             */
/*   Updated: 2024/01/17 15:52:26 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_MAIN_H
#define SO_LONG_MAIN_H



typedef struct s_coordinate {
	int x;
	int y;
}			   t_coordinate;

typedef struct	s_image {
	void	*ptr;
	int		width;
	int		height;
}				t_image;

typedef struct	s_game {
	char **map;
	t_image player_sprite;
	t_image wall;
	t_image grass;
	t_image exit;
	t_image item;
}				t_game;

typedef struct	s_mlx_vars {
	void	*mlx;
	void	*win;
}				t_mlx_vars ;

typedef struct s_player {
	t_coordinate cords;
	int items;
	int mooves;
}				t_player;

typedef struct	s_map_requirements {

	int exit;
	int items;
	int player_spawn;
	int access_exit;
	int access_items;
}				t_map_requirements;

typedef struct s_so_long {

	t_map_requirements r_map;
	t_player player;
	t_game game;
	t_mlx_vars vars;
}				t_so_long;

#define W_KEY 119
#define S_KEY 115
#define A_KEY 97
#define D_KEY 100
#define FOX_SPRITE "./ressources/fox_sprite.xpm"
#define GRASS_SPRITE "./ressources/grass_tile.xpm"
#define EXIT_SPRITE "./ressources/house_tile.xpm"
#define ITEM_SPRITE "./ressources/milk_tile.xpm"
#define WALL_SPRITE "./ressources/water_tile.xpm"

#include "../mlx_linux/mlx.h"
#include "../mlx_linux/mlx_int.h"
#include "../libft/libft/libft.h"
#include "../libft/ft_printf/ft_printf.h"
#include "../libft/get_next_line/get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

//		PARSING.C
int		open_file(char *filename);
int		close_file(int file);
int		pre_read(char *filename);
void 	read_file(char **map, char *filename, size_t line_nb);
void	parsing(t_so_long *so_long, char *filename);

//		CHECK_MAP.C
void check_verticales_wall(t_so_long *so_long);
void check_horizontales_wall(t_so_long *so_long);
void char_check(t_so_long *so_long, char c, size_t i, size_t j);
void check_global_map(t_so_long *so_long);
void exit_error(t_so_long *so_long);
void check_ber(char *filename);
int map_len(t_so_long so_long);

//		INIT_MAP.C
void init_map(t_so_long *so_long);
int no_event(t_so_long *so_long);

//		TILES.C
t_coordinate def_window_size(t_so_long *so_long);
void put_tiles(t_so_long *so_long);

//		INPUT.C
int close_window(t_so_long *so_long);
int mooves(int keycode, t_so_long *so_long);


// 		MAIN.C
void free_map(char **map);

//		UTILS.C
void delete_newline(char **map);
void sprite_init(t_so_long *so_long);
int flood_fill(char *str, t_map_requirements *reqs, t_coordinate player_pos, t_coordinate witdhheight);
void check_items(char **map, t_map_requirements *reqs, t_coordinate player_pos, t_coordinate witdhheight);
void map_size(t_so_long *so_long);

#endif

