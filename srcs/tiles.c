#include "../inc/so_long.h"

t_coordinate def_window_size(t_so_long *so_long)
{
    t_coordinate size;
    int i;
    int j;

    i = 0;
    size.x = 0;
    size.y = 0;

    while (so_long->game.map[i])
    {
        j = 0;
        while (so_long->game.map[i][j])
        {
            if (size.x < j)
                size.x = j;
            j++;
        }
        i++;
    }
    size.x = size.x * SPRITE_SIZE;
    size.y = i * SPRITE_SIZE;
    return (size);
}

void process_tiles(t_so_long *so_long, char c, t_coordinate xy)
{
    if (c == '1')
        mlx_put_image_to_window(so_long->vars.mlx, so_long->vars.win, so_long->game.wall.ptr, xy.x, xy.y);
    else if (c == '0' || c == 'P')
        mlx_put_image_to_window(so_long->vars.mlx, so_long->vars.win, so_long->game.grass.ptr, xy.x, xy.y);
    else if (c == 'C')
        mlx_put_image_to_window(so_long->vars.mlx, so_long->vars.win,  so_long->game.item.ptr, xy.x, xy.y);
    else if (c == 'E')
        mlx_put_image_to_window(so_long->vars.mlx, so_long->vars.win, so_long->game.exit.ptr, xy.x, xy.y);
    mlx_put_image_to_window(so_long->vars.mlx, so_long->vars.win, so_long->game.player_sprite1.ptr, so_long->player.cords.x, so_long->player.cords.y);
}


void put_tiles(t_so_long *so_long)
{
    int i;
    int j;
    t_coordinate xy;

    i = 0;
    j = 0;
    xy.x = 0;
    xy.y = 0;
    while (so_long->game.map[i])
    {
        j = 0;
        while (so_long->game.map[i][j])
        {
            process_tiles(so_long, so_long->game.map[i][j], xy);
            j++;
            xy.x += SPRITE_SIZE;
        }
        xy.x = 0;
        xy.y += SPRITE_SIZE;
        i++;
    }

}


