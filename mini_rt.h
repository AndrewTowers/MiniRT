/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andtruji <andtruji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 14:02:05 by bsiguenc          #+#    #+#             */
/*   Updated: 2026/09/02 12:42:49 by andtruji         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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

# ifndef WIDTH
#  define WIDTH 1000
# endif
# ifndef HEIGHT
#  define HEIGHT 800
# endif

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
	int		save;
	float	ratio;
	t_rgb	rgb;
}	t_aml;

typedef struct s_cam
{
	int		save;
	t_pos	pos;
	t_pos	dir;
	float	fov;
}	t_cam;

typedef struct s_light
{
	int		save;
	t_pos	pos;
	float	ratio;
	t_rgb	rgb;
}	t_light;

typedef enum s_type_figures
{
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
	t_pos	normal;
	t_rgb	rgb;
}	t_plane;

typedef struct s_cylinder
{
	t_pos	pos;
	t_pos	axis;
	float	diameter;
	float	height;
	t_rgb	rgb;
}	t_cylinder;

typedef struct s_object
{
	t_figures		type;
	void			*figure;
	struct s_object	*next;
}	t_object;

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
	t_dt_mlx	img;
	int			fd_rt;
	t_aml		aml;
	t_cam		cam;
	t_light		light;
	t_object	*objects;
}	t_data;

int		check_args(char **args, char *extension, int count);
int		ret_str(char *str, int status);
char	*ft_findchar(char *str, char c);
char	*ft_reverse_findchar(char *str, char c);
int		parse_file(t_data *dt);
void	end_data(t_data *dt, int err, char *sterr);

//parsing elements
int		parse_line(char *line, t_data *dt, int size);
int		parse_camera(char *args, t_data *dt);
int		parse_ambient(char *args, t_data *dt);
int		parse_light(char *args, t_data *dt);
int		parse_sphere(char *args, t_data *dt);
int		parse_plane(char *args, t_data *dt);
int		parse_cylinder(char *args, t_data *dt);
int		parse_vec(char *str, t_pos *vec);
int		parse_rgb(char *rgb_str, t_rgb *rgb);
int		parse_diameter_n_height(char *dm_hg, float *dmt_hg);
int		parse_normalized_vec(char *str, t_pos *vec);

t_object	*new_object(t_figures type, void *figure);
void	add_object(t_object **head, t_object *new_obj);
void	free_objects(t_object *head);

//draw
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	run_mlx(t_data *dt);
int		create_trgb(int t, int r, int g, int b);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);


int	close_window(t_data *dt);

// Utils
int	count_nodes(char *str);
int	count_splits(char **strs);
char	**split_realloc(char **strs, char *str, int i, int j);
char	**splitter(char *str);
#endif
