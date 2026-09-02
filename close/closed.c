/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closed.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 20:06:11 by blas              #+#    #+#             */
/*   Updated: 2026/09/02 12:26:13 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int	close_window(t_data *dt)
{
	if (dt->img.img)
		mlx_destroy_image(dt->mlx, dt->img.img);
	if (dt->mlx_win)
		mlx_destroy_window(dt->mlx, dt->mlx_win);
	if (dt->mlx)
	{
		mlx_destroy_display(dt->mlx);
		free(dt->mlx);
		dt->mlx = NULL;
	}
	end_data(dt, 0, NULL);
	exit(0);
	return (0);
}

void	close_fd(t_data *dt)
{
	char	*temp;

	temp = get_next_line(dt->fd_rt);
	while (temp != NULL)
	{
		free(temp);
		temp = get_next_line(dt->fd_rt);
	}
	close(dt->fd_rt);
	dt->fd_rt = -1;
}
