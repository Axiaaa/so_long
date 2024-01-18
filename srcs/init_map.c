#include "../inc/so_long.h"


int no_event(t_so_long *so_long)
{
	char *s;
	s = ft_itoa(so_long->player.mooves);
	mlx_string_put(so_long->vars.mlx, so_long->vars.win, 30, 30, 0xff000000, s);
	free(s);
	s = NULL;
	return (0);
}

void init_map(t_so_long *so_long)
{
    t_coordinate size;

    size = def_window_size(so_long);
    so_long->vars.mlx = mlx_init();
	so_long->vars.win = mlx_new_window(so_long->vars.mlx, size.x+SPRITE_SIZE, size.y, "so_long");
	sprite_init(so_long);
	put_tiles(so_long);
	mlx_hook(so_long->vars.win, DestroyNotify, StructureNotifyMask, close_window, so_long); //Closing button hook
	mlx_hook(so_long->vars.win, KeyPress, KeyPressMask,  mooves, so_long); // Mooving hook & escape hook
	//mlx_key_hook(so_long->vars.win, mooves, so_long); // Mooving hook & escape hook
	mlx_loop_hook(so_long->vars.mlx, no_event, so_long);
	mlx_loop(so_long->vars.mlx);
}