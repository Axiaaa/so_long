/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 23:08:52 by lcamerly          #+#    #+#             */
/*   Updated: 2024/03/01 17:31:51 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/get_next_line/get_next_line.h"
# include "../libft/libft/libft.h"
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_coordinate
{
	int					x;
	int					y;
}						t_coordinate;

typedef struct s_image
{
	void				*ptr;
	int					width;
	int					height;
}						t_image;

typedef struct s_game
{
	char				**map;
	t_image				player_sprite1;
	t_image				player_sprite2;
	t_image				player_sprite3;
	t_image				player_sprite4;
	t_image				wall;
	t_image				grass;
	t_image				exit;
	t_image				item;
	t_image				ghost;
}						t_game;

typedef struct s_mlx_vars
{
	void				*mlx;
	void				*win;
}						t_mlx_vars;

typedef struct s_player
{
	t_coordinate		cords;
	int					items;
	int					mooves;
	int					sprite_state;
}						t_player;

typedef struct s_map_requirements
{
	int					exit;
	int					items;
	int					player_spawn;
	int					access_exit;
	int					access_items;
}						t_map_requirements;

typedef struct s_so_long
{
	t_map_requirements	r_map;
	t_player			player;
	t_game				game;
	t_mlx_vars			vars;
}						t_so_long;

typedef enum s_errors
{
	WRONG_FILE_EXTENSION,
	CANT_ACCESS,
	REQUIREMENTS_ISSUE,
	MAP_TOO_BIG,
	WALL_ISSUE,
	MAP_ISNT_RECTANGLE,
	WRONG_ARG_NUM,
	UNKNOW_CHAR,
}	t_errors;

# define SPRITE_SIZE 64
# define PACMAN_SPRITE "./ressources/pacman1_tile.xpm"
# define PACMAN_SPRITE2 "./ressources/pacman2_tile.xpm"
# define PACMAN_SPRITE3 "./ressources/pacman3_tile.xpm"
# define PACMAN_SPRITE4 "./ressources/pacman4_tile.xpm"
# define BACKGROUND_SPRITE "./ressources/background_tile.xpm"
# define EXIT_SPRITE "./ressources/exit_tile.xpm"
# define ITEM_SPRITE "./ressources/item_tile.xpm"
# define WALL_SPRITE "./ressources/wall_tile.xpm"
# define GHOST_SPRITE "./ressources/ghost_tile.xpm"

//		PARSING.C
int						open_file(char *filename);
int						close_file(int file);
int						pre_read(char *filename);
void					read_file(char **map, char *filename, size_t line_nb);
void					parsing(t_so_long *so_long, char *filename);

//		CHECK_MAP.C
void					check_verticales_wall(t_so_long *so_long);
void					check_horizontales_wall(t_so_long *so_long);
void					char_check(t_so_long *so_long, char c, size_t i,
							size_t j);
void					check_global_map(t_so_long *so_long);
void					exit_error(t_so_long *so_long, char *s, t_errors code);
void					check_ber(char *filename);
int						map_len(t_so_long so_long);

//		INIT_MAP.C
void					init_map(t_so_long *so_long);
int						no_event(t_so_long *so_long);

//		TILES.C
t_coordinate			def_window_size(t_so_long *so_long);
void					put_tiles(t_so_long *so_long);
void					update_player_sprite(t_so_long *so_long, int keycode);

//		INPUT.C
int						close_window(t_so_long *so_long);
int						mooves(int keycode, t_so_long *so_long);

// 		MAIN.C
void					free_map(char **map);

//		UTILS.C
void					delete_newline(char **map);
void					sprite_init(t_so_long *so_long);
int						flood_fill(char *str, t_map_requirements *reqs,
							t_coordinate player_pos, t_coordinate witdhheight);
void					check_items(char **map, t_map_requirements *reqs,
							t_coordinate player_pos, t_coordinate witdhheight);
void					map_size(t_so_long *so_long);
void					sprite_init2(t_so_long *so_long);
void					check_exit(char **map, t_map_requirements *reqs,
							t_coordinate player_pos, t_coordinate witdhheight);

#endif
