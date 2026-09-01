/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andtruji <andtruji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 14:50:57 by bsiguenc          #+#    #+#             */
/*   Updated: 2026/08/31 17:34:05 by andtruji         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
		|| !parse_diameter_height(parts[2], &cy->diameter)
		|| !parse_diameter_height(parts[3], &cy->height)
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

int	parse_line(char *line, t_data *dt)
{
	if (!ft_strncmp(line, "A ", 2))
		return (parse_ambient(line + 2, dt));
	else if (!ft_strncmp(line, "C ", 2))
		return (parse_camera(line + 2, dt));
	else if (!ft_strncmp(line, "L ", 2))
		return (parse_light(line + 2, dt));
	else if (!ft_strncmp(line, "sp ", 3))
		return (parse_sphere(line + 3, dt));
	else if (!ft_strncmp(line, "pl ", 3))
		return (parse_plane(line + 3, dt));
	else if (!ft_strncmp(line, "cy ", 3))
		return (parse_cylinder(line + 3, dt));
	return (0);
}
