/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 23:12:13 by lcamerly          #+#    #+#             */
/*   Updated: 2023/11/18 01:15:44 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_square(t_data img, int x, int y, int size)
{
	int	i;
	int	j;

	i = x;
	while (i < x + size)
		my_mlx_pixel_put(&img, i++, y, 0x00FF0000);
	j = y;
	while (j < y + size)
		my_mlx_pixel_put(&img, x + size, j++, 0x00FF0000);
	i = x;
	while (i < x + size)
		my_mlx_pixel_put(&img, i++, y + size, 0x00FF0000);
	j = y;
	while (j < y + size)
		my_mlx_pixel_put(&img, x, j++, 0x00FF0000);
}

void	ft_cardrillage(t_data img, t_coodinate dim, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < dim.x)
	{
		j = 0;
		while (j < dim.y)
		{
			ft_square(img, i, j, size);
			j += size;
		}
		i += size;
	}
}

int	close(int keycode, void *mlx, void *mlx_win)
{
	mlx_destroy_window(mlx, mlx_win);
	return (0);
}

int	main(void)
{
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	t_coodinate	dim;

	dim.x = 1920;
	dim.y = 1080;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, dim.x, dim.y, "so_long");
	img.img = mlx_new_image(mlx, dim.x, dim.y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	ft_cardrillage(img, dim, 45);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_hook(mlx_win, 2, 1L << 0, close, mlx, mlx_win);
	mlx_loop(mlx);
}
