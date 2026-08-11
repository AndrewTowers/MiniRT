/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 15:59:00 by blas              #+#    #+#             */
/*   Updated: 2026/08/11 13:02:45 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	end_data(t_data *dt, int err, char *sterr)
{
	close(dt->fd_rt);
	// free(dt->figure.type)
	if (err)
	{
		ft_printf("%s", sterr);
		exit (err);
	}
}

int	init_data(t_data *dt, char *args)
{
	dt->fd_rt = open(args[1], O_RDONLY);
	if (dt->fd_rt < 0)
		return (1);
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
	dt.mlx = mlx_init();
	dt.mlx_win = mlx_new_window(dt.mlx, 1000, 800, "Hello World");
	mlx_loop(dt.mlx);
	end_data(&dt, 0, NULL);
	return (0);
}