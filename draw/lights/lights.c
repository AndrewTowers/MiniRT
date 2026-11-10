/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andtruji <andtruji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 19:41:31 by andtruji          #+#    #+#             */
/*   Updated: 2026/11/10 10:49:00 by andtruji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mini_rt.h"

t_pos	get_normal(t_object *obj, t_pos hit_point)
{
	t_pos		normal;
	double		height;
	t_cylinder	*cy;
	t_pos		axis;

	if (obj->type == SPHERE)
		return (v_norm(v_sub(hit_point, ((t_sphere *)obj->figure)->pos)));
	if (obj->type == PLANE)
		return (v_norm(((t_plane *)obj->figure)->normal));
	cy = (t_cylinder *)obj->figure;
	axis = v_norm(cy->axis);
	height = v_dot(v_sub(hit_point, cy->pos), axis);
	if (fabs(height) > cy->height / 2.0)
	{
		if (height > 0.0)
			return (axis);
		return (v_scale(axis, -1.0));
	}
	normal = v_sub(v_sub(hit_point, cy->pos), v_scale(axis, height));
	return (v_norm(normal));
}

static int	is_in_shadow(t_data *data, t_hit *hit, t_pos dir, double dist_light)
{
	t_ray	shadow_ray;
	double	t;

	shadow_ray.origin = v_add(hit->point, v_scale(hit->normal, 1e-4));
	shadow_ray.dir = dir;
	if (find_closest_object(data, shadow_ray, &t) && t < dist_light)
		return (1);
	return (0);
}

static void	apply_light(t_data *data, t_light *light, t_hit *hit, double *acc)
{
	t_pos	dir;
	double	dist_light;
	double	d;

	dir = v_norm(v_sub(light->pos, hit->point));
	dist_light = v_len(v_sub(light->pos, hit->point));
	if (is_in_shadow(data, hit, dir, dist_light))
		return ;
	d = fmax(0.0, v_dot(hit->normal, dir)) * light->ratio;
	acc[0] += d * light->rgb.r / 255.0;
	acc[1] += d * light->rgb.g / 255.0;
	acc[2] += d * light->rgb.b / 255.0;
}

static int	channel(int base, double factor)
{
	int	valeur;

	valeur = (int)(base * factor);
	if (valeur > 255)
		valeur = 255;
	return (valeur);
}

int	compute_color(t_data *data, t_object *obj, t_pos hit_point)
{
	t_hit	hit;
	t_light	*light;
	double	acc[3];
	int		base_color;

	hit.obj = obj;
	hit.point = hit_point;
	hit.normal = get_normal(obj, hit_point);
	base_color = get_object_color(obj);
	acc[0] = data->aml.ratio * data->aml.rgb.r / 255.0;
	acc[1] = data->aml.ratio * data->aml.rgb.g / 255.0;
	acc[2] = data->aml.ratio * data->aml.rgb.b / 255.0;
	light = data->light;
	while (light)
	{
		apply_light(data, light, &hit, acc);
		light = light->next;
	}
	return (create_trgb(0, channel(base_color >> 16 & 0xFF, acc[0]),
			channel(base_color >> 8 & 0xFF, acc[1]),
			channel(base_color & 0xFF, acc[2])));
}
