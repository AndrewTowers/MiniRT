/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 14:50:57 by bsiguenc          #+#    #+#             */
/*   Updated: 2026/09/02 11:50:57 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int	parse_sphere(char *args, t_data *dt)
{
	char		**parts;
	t_sphere	*sp;
	t_object	*obj;

	parts = ft_split(args, ' ');
	if (!parts || !parts[0] || !parts[1] || !parts[2] || parts[3])
		return (0);
	sp = malloc(sizeof(t_sphere));
	if (!sp)
		return (0);
	if (!parse_vec(parts[0], &sp->pos) || !parse_rgb(parts[2], &sp->rgb)
		|| !parse_diameter_n_height(parts[1], &sp->diameter) )
	{
		free(sp);
		ft_free_split(parts);
		return (0);
	}
	obj = new_object(SPHERE, sp);
	add_object(&dt->objects, obj);
	ft_free_split(parts);
	return (1);
}

int	parse_plane(char *args, t_data *dt)
{
	char		**parts;
	t_plane		*pl;
	t_object	*obj;

	parts = ft_split(args, ' ');
	if (!parts || !parts[0] || !parts[1] || !parts[2] || parts[3])
		return (0);
	pl = malloc(sizeof(t_plane));
	if (!pl)
		return (0);
	if (!parse_vec(parts[0], &pl->pos) || !parse_normalized_vec(parts[1], &pl->normal)
		|| !parse_rgb(parts[2], &pl->rgb))
	{
		free(pl);
		ft_free_split(parts);
		return (0);
	}
	obj = new_object(PLANE, pl);
	add_object(&dt->objects, obj);
	ft_free_split(parts);
	return (1);
}

int	parse_cylinder(char *args, t_data *dt)
{
	char		**parts;
	t_cylinder	*cy;
	t_object	*obj;

	parts = ft_split(args, ' ');
	if (!parts || !parts[0] || !parts[1] || !parts[2] || !parts[3] || !parts[4] || parts[5])
		return (0);
	cy = malloc(sizeof(t_cylinder));
	if (!cy)
		return (0);
	if (!parse_vec(parts[0], &cy->pos) || !parse_normalized_vec(parts[1], &cy->axis)
		|| !parse_diameter_n_height(parts[2], &cy->diameter)
		|| !parse_diameter_n_height(parts[3], &cy->height)
		|| !parse_rgb(parts[4], &cy->rgb))
	{
		free(cy);
		ft_free_split(parts);
		return (0);
	}
	obj = new_object(CYLINDER, cy);
	add_object(&dt->objects, obj);
	ft_free_split(parts);
	return (1);
}

int	parse_line(char *line, t_data *dt, int size)
{
	if (!ft_strncmp(line, "A ", size))
		return (parse_ambient(line + size, dt));
	else if (!ft_strncmp(line, "C ", size))
		return (parse_camera(line + size, dt));
	else if (!ft_strncmp(line, "L ", size))
		return (parse_light(line + size, dt));
	else if (!ft_strncmp(line, "sp ", size))
		return (parse_sphere(line + size, dt));
	else if (!ft_strncmp(line, "pl ", size))
		return (parse_plane(line + size, dt));
	else if (!ft_strncmp(line, "cy ", size))
		return (parse_cylinder(line + size, dt));
	return (0);
}
