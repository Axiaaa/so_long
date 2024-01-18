#include "../inc/so_long.h"

int close_window(t_so_long *so_long)
{
	mlx_destroy_image(so_long->vars.mlx, so_long->game.wall.ptr);
	mlx_destroy_image(so_long->vars.mlx, so_long->game.grass.ptr);
	mlx_destroy_image(so_long->vars.mlx, so_long->game.exit.ptr);
	mlx_destroy_image(so_long->vars.mlx, so_long->game.item.ptr);
	mlx_destroy_image(so_long->vars.mlx, so_long->game.player_sprite1.ptr);
	mlx_destroy_image(so_long->vars.mlx, so_long->game.player_sprite2.ptr);
	mlx_destroy_image(so_long->vars.mlx, so_long->game.player_sprite3.ptr);
	mlx_destroy_image(so_long->vars.mlx, so_long->game.player_sprite4.ptr);
	mlx_destroy_image(so_long->vars.mlx, so_long->game.ghost.ptr);
	mlx_destroy_window(so_long->vars.mlx, so_long->vars.win);
	mlx_destroy_display(so_long->vars.mlx);
	free(so_long->vars.mlx);
	free_map(so_long->game.map);
	exit(0);
	return (0);
}

int is_valid(t_so_long *so_long, int x, int y)
{
	if (so_long->game.map[y / SPRITE_SIZE][x / SPRITE_SIZE] == '1')
		return (0);
	so_long->player.mooves++;
	ft_printf("\033[1;36mMoves: %d\n\033[1;36m", so_long->player.mooves);
	if (so_long->game.map[y / SPRITE_SIZE][x / SPRITE_SIZE] == 'C')
	{
		so_long->game.map[y / SPRITE_SIZE][x / SPRITE_SIZE] = '0';
		so_long->player.items++;
	}
	if (so_long->game.map[y / SPRITE_SIZE][x / SPRITE_SIZE] == 'E' && so_long->player.items == so_long->r_map.items	)
	{
		ft_printf("\033[1;32m\n\nYou won in %d moves !\n\033[1;32m", so_long->player.mooves);
		close_window(so_long);
	}
	if (so_long->game.map[y / SPRITE_SIZE][x / SPRITE_SIZE] == 'G')
	{
		ft_printf("\033[1;31m\n\nYou lost with %d moves !\n\033[1;31m", so_long->player.mooves);
		close_window(so_long);
	}
	return (1);
}

void update_player_sprite(t_so_long *so_long, int keycode)
{
	void *tmp;
	if (keycode == XK_a)
	{
		if (so_long->player.sprite_state == 0)
		{
			tmp = so_long->game.player_sprite1.ptr;
			so_long->game.player_sprite1.ptr = so_long->game.player_sprite2.ptr;
			so_long->game.player_sprite2.ptr = tmp;
			so_long->player.sprite_state = 1;
		}
	}
	if (keycode == XK_d)
	{
		if (so_long->player.sprite_state == 1)
		{
			tmp = so_long->game.player_sprite1.ptr;
			so_long->game.player_sprite1.ptr = so_long->game.player_sprite2.ptr;
			so_long->game.player_sprite2.ptr = tmp;
			so_long->player.sprite_state = 0;
		}
	}
}

int mooves(int keycode, t_so_long *so_long) 
{
	if (keycode == XK_w)
		if (is_valid(so_long, so_long->player.cords.x, so_long->player.cords.y - SPRITE_SIZE))
			so_long->player.cords.y -= SPRITE_SIZE;
	if (keycode == XK_s)
		if (is_valid(so_long, so_long->player.cords.x, so_long->player.cords.y + SPRITE_SIZE))
			so_long->player.cords.y += SPRITE_SIZE;
	if (keycode == XK_a)
		if (is_valid(so_long, so_long->player.cords.x - SPRITE_SIZE, so_long->player.cords.y))
			so_long->player.cords.x -= SPRITE_SIZE;
	if (keycode == XK_d)
		if (is_valid(so_long, so_long->player.cords.x + SPRITE_SIZE, so_long->player.cords.y))
			so_long->player.cords.x += SPRITE_SIZE;
	if (keycode == XK_Escape)
		close_window(so_long);
	update_player_sprite(so_long, keycode);
	put_tiles(so_long);
	return (0);
}

