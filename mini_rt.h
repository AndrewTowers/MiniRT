/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 14:02:05 by bsiguenc          #+#    #+#             */
/*   Updated: 2026/07/28 15:22:21 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include "minilibx-linux/mlx.h"

typedef struct s_mlx_dt
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		endian;
} 		t_mlx_dt;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
}	t_data;

#endif
