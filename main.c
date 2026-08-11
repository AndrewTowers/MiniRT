/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 15:59:00 by blas              #+#    #+#             */
/*   Updated: 2026/08/11 00:06:42 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	main(int argn, char **args)
{
	t_data dt;

	if (argn < 1)
		return (ret_str("Error: Invalid format, enter: ./miniRT file.rt\n", 1));
	if (check_args(args, ".rt", argn - 1) == -1)
		return (ret_str("Error: Incorrect File Format\n", 1));
	dt.mlx = mlx_init();
	dt.mlx_win = mlx_new_window(dt.mlx, 1000, 800, "Hello World");
	mlx_loop(dt.mlx);
	return (0);
}