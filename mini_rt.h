/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 14:02:05 by bsiguenc          #+#    #+#             */
/*   Updated: 2026/08/10 23:54:50 by blas             ###   ########.fr       */
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
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

typedef struct s_dt_mlx
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_dt_mlx;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	int		fd_rt;
}	t_data;

int		check_args(char **args, char *extension, int count);
int		ret_str(char *str, int status);
char	*ft_findchar(char *str, char c);
char	*ft_reverse_findchar(char *str, char c);

#endif
