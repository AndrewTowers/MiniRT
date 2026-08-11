/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 14:02:05 by bsiguenc          #+#    #+#             */
/*   Updated: 2026/08/11 13:35:48 by bsiguenc         ###   ########.fr       */
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

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_pos
{
	float		x;
	float		y;
	float		z;
}	t_pos;

typedef struct s_aml
{
	float	ratio_in_rang;
	t_rgb	rgb;
}	t_aml;

typedef struct s_cam
{
	t_pos	pos;
	float	deep;
	float	horizontal;
}	t_cam;

typedef struct s_light
{
	t_pos	pos;
	float	light_range;
	t_rgb	rgb;
}	t_light;

typedef enum s_type_figures
{
	NONE,
	SPHERE,
	PLANE,
	CYLINDER
}	t_figures;

typedef struct s_sphere
{
	t_pos	pos;
	float	diameter;
	t_rgb	rgb;
}	t_sphere;

typedef struct s_plane
{
	t_pos	pos;
	float	range_normalized;
	t_rgb	rgb;
}	t_plane;

typedef struct s_cylinder
{
	t_pos	pos;
	float	range_normalized;
	float	diameter;
	float	height;
	t_rgb	rgb;
}	t_cylinder;

typedef struct s_type_figure
{
	t_figures	type_figure;
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
}	t_figure;

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
	void		*mlx;
	void		*mlx_win;
	int			fd_rt;
	t_aml		aml;
	t_cam		cam;
	t_light		light;
	t_figure	figure;
}	t_data;

int		check_args(char **args, char *extension, int count);
int		ret_str(char *str, int status);
char	*ft_findchar(char *str, char c);
char	*ft_reverse_findchar(char *str, char c);
int		parse_file(t_data *dt);

#endif
