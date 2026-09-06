/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 22:58:57 by blas              #+#    #+#             */
/*   Updated: 2026/09/06 18:36:48 by blas             ###   ########.fr       */
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
	int	x;
	int	y;
	t_ray	ray;
	t_object	*hit_obj;
	double	t;
	int	color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ray = generate_ray(dt, x, y);
			hit_obj = find_closest_object(dt, ray, &t);
			if (hit_obj)
				color = get_object_color(hit_obj);
			else
				color = 0x000000;
			my_mlx_pixel_put(dt, x, y, color);
			x++;
		}
		y++;
	}
}

void	run_mlx(t_data *dt)
{
	dt->mlx = mlx_init();
	if (!dt->mlx)
		return ;
	dt->mlx_win = mlx_new_window(dt->mlx, WIDTH, HEIGHT, "MiniRT");
	if (!dt->mlx_win)
		return ;
	dt->img.img = mlx_new_image(dt->mlx, WIDTH, HEIGHT);
	dt->img.addr = mlx_get_data_addr(dt->img.img, &dt->img.bits_per_pixel,
			&dt->img.line_length, &dt->img.endian);
	do_paint(dt);
	mlx_put_image_to_window(dt->mlx, dt->mlx_win, dt->img.img, 0, 0);
	mlx_hook(dt->mlx_win, 17, 0, close_window, dt);
	mlx_loop(dt->mlx);
}


