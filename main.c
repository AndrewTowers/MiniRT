/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 15:59:00 by blas              #+#    #+#             */
/*   Updated: 2026/09/02 12:25:10 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

// free(dt->figure.type)
void	end_data(t_data *dt, int err, char *sterr)
{
	if (dt->mlx && dt->mlx_win)
	{
		mlx_destroy_window(dt->mlx, dt->mlx_win);
		free(dt->mlx);
	}
	close(dt->fd_rt);
	if (err)
	{
		ft_printf("%s", sterr);
		exit (err);
	}
}

int	init_data(t_data *dt, char **args)
{
	dt->fd_rt = open(args[1], O_RDONLY);
	if (dt->fd_rt < 0)
		return (ret_str("Error: Invalid File\n", 1));
	dt->aml.save = 0;
	dt->cam.save = 0;
	dt->light.save = 0;
	dt->objects = NULL;
	parse_file(dt);
	return (0);
}


int	key_hook(int keycode, t_data *dt)
{
	if (keycode == 65307)
		close_window(dt);
	return (0);
}

int	main(int argn, char **args)
{
	t_data	dt;

	if (argn <= 1)
		return (ret_str("Error: Invalid format, enter: ./miniRT file.rt\n", 1));
	if (check_args(args, ".rt", argn - 1) == -1)
		return (ret_str("Error: Incorrect File Format\n", 1));
	init_data(&dt, args);
	run_mlx(&dt);
	end_data(&dt, 0, NULL);
	return (0);
}
