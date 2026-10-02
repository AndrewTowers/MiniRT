/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andtruji <andtruji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 19:41:31 by andtruji          #+#    #+#             */
/*   Updated: 2026/10/02 11:56:44 by andtruji         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../mini_rt.h"

t_pos	get_normal(t_object *obj, t_pos hit_point)
{
	t_pos		normal;
	double		height;
	t_cylinder	*cy;
	t_pos		axis;

	if (obj->type == SPHERE)
		normal = v_norm(v_sub(hit_point, ((t_sphere *)obj->figure)->pos));
	else if (obj->type == PLANE)
		normal = v_norm(((t_plane *)obj->figure)->normal);
	else
	{
		cy = (t_cylinder *)obj->figure;
		axis = v_norm((cy->axis));
		height = v_dot(v_sub(hit_point, (cy->pos)),
				v_norm((cy->axis)));
		if (fabs(height) > cy->height / 2.0)
			normal = v_norm(v_scale(axis, height > 0.0 ? 1.0 : -1.0));
		else
			normal = v_norm(v_sub(v_sub(hit_point, (cy->pos)),
					v_scale(v_norm((cy->axis)), height)));
	}
	return (normal);
}

int	is_in_shadow(t_data *data, t_pos point, t_pos light_dir, t_pos normal, double dist_light)
{
	t_ray	shadow_ray;
	double	t;

	shadow_ray.origin = v_add(point, v_scale(normal, 1e-4));
	shadow_ray.dir = light_dir;
	if (find_closest_object(data, shadow_ray, &t) && t < dist_light)
		return (1);
	return (0);
}

int	scale_color(int color, double factor)
{
	int	r;
	int	g;
	int	b;

	r = get_r(color);
	g = get_g(color);
	b = get_b(color);
	r = (int)(r * factor);
	g = (int)(g * factor);
	b = (int)(b * factor);
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	return (create_trgb(0, r, g, b));
}

int	compute_color(t_data *data, t_object *obj, t_pos hit_point)
{
	t_pos	normal;
	t_pos	light_dir;
	double	dist_light;
	double	diffuse;
	int		base_color;

	normal = get_normal(obj, hit_point);
	light_dir = v_norm(v_sub(data->light.pos, hit_point));
	dist_light = v_len(v_sub((data->light).pos, hit_point));
	base_color = get_object_color(obj);
	diffuse = 0.0;
	if (!is_in_shadow(data, hit_point, light_dir, normal, dist_light))
		diffuse = fmax(0.0, v_dot(normal, light_dir));
	diffuse += data->aml.ratio;
	if (diffuse > 1.0)
		diffuse = 1.0;
	return (scale_color(base_color, diffuse));
}
