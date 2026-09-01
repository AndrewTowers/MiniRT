/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 22:58:57 by blas              #+#    #+#             */
/*   Updated: 2026/08/25 01:33:56 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line_length
			+ x * (data->img.bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

//Aqui va todo el renderizado
void	do_paint(t_data *dt)
{
	int	i;
	int	x;

	i = 0;
	while (i < 100)
	{
		x = 0;
		while (x < 100)
		{
			my_mlx_pixel_put(dt, i, x, 0x00FF0000);
			x++;
		}
		i++;
	}
}

void	run_mlx(t_data *dt)
{
	dt->mlx = mlx_init();
	if (!dt->mlx)
		return (1);
	dt->mlx_win = mlx_new_window(dt->mlx, WIDTH, HEIGHT, "MiniRT");
	if (!dt->mlx_win)
		return (1);
	dt->img.img = mlx_new_image(dt->mlx, WIDTH, HEIGHT);
	dt->img.addr = mlx_get_data_addr(dt->img.img, &dt->img.bits_per_pixel,
			&dt->img.line_length, &dt->img.endian);
	do_paint(dt);
	mlx_put_image_to_window(dt->mlx, dt->mlx_win, dt->img.img, 0, 0);
	mlx_loop(dt->mlx);
}


