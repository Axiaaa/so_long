#include "../inc/so_long.h"

int close_window(t_so_long *so_long)
{
	mlx_destroy_image(so_long->vars.mlx, so_long->game.wall.ptr);
	mlx_destroy_image(so_long->vars.mlx, so_long->game.grass.ptr);
	mlx_destroy_image(so_long->vars.mlx, so_long->game.exit.ptr);
	mlx_destroy_image(so_long->vars.mlx, so_long->game.item.ptr);
	mlx_destroy_image(so_long->vars.mlx, so_long->game.player_sprite.ptr);
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
	if (so_long->game.map[y / SPRITE_SIZE][x / SPRITE_SIZE] == 'C')
	{
		so_long->game.map[y / SPRITE_SIZE][x / SPRITE_SIZE] = '0';
		so_long->player.items++;
	}
	if (so_long->game.map[y / SPRITE_SIZE][x / SPRITE_SIZE] == 'E' && so_long->player.items == so_long->r_map.items)
	{
		printf("\033[1;32m\n\nYou won in %d mooves !\n\033[1;32m", so_long->player.mooves);
		close_window(so_long);
	}
	so_long->player.mooves++;
	printf("\033[1;36mMooves: %d\n\033[1;36m", so_long->player.mooves);
	return (1);
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
	put_tiles(so_long);
	return (0);
}

