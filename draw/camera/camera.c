/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 16:24:09 by blas              #+#    #+#             */
/*   Updated: 2026/09/06 18:39:21 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mini_rt.h"

static t_pos	compute_ray_dir(t_data *dt, int x, int y, t_pos w)
{
	t_pos	u;
	t_pos	v;
	t_pos	up;
	double	px;
	double	py;

	if (fabs(w.y) > 0.999f)
		up = (t_pos){0, 0, 1};
	else
		up = (t_pos){0, 1, 0};
	u = v_norm(v_cross(up, w));
	v = v_cross(w, u);
	px = (2.0 * ((x + 0.5) / WIDTH) - 1.0)
		* ((double)WIDTH / (double)HEIGHT)
		* tan((dt->cam.fov * PI / 180.0) / 2.0);
	py = (1.0 - 2.0 * ((y + 0.5) / HEIGHT))
		* tan((dt->cam.fov * PI / 180.0) / 2.0);
	return (v_norm(v_add(v_add(w, v_scale(u, px)), v_scale(v, py))));
}

t_ray	generate_ray(t_data *dt, int x, int y)
{
	t_ray	ray;
	t_pos	w;

	w = v_norm(dt->cam.dir);
	ray.origin = dt->cam.pos;
	ray.dir = compute_ray_dir(dt, x, y, w);
	return (ray);
}

static double	get_object_intersection(t_object *obj, t_ray ray)
{
	if (obj->type == SPHERE)
		return (hit_sphere((t_sphere *)obj->figure, ray));
	else if (obj->type == PLANE)
		return (hit_plane((t_plane *)obj->figure, ray));
	else if (obj->type == CYLINDER)
		return (hit_cylinder((t_cylinder *)obj->figure, ray));
	return (-1.0);
}

t_object	*find_closest_object(t_data *dt, t_ray ray, double *out_t)
{
	t_object	*curr;
	t_object	*closest;
	double		closest_t;
	double		t;

	curr = dt->objects;
	closest = NULL;
	closest_t = 1e30;
	while (curr)
	{
		t = get_object_intersection(curr, ray);
		if (t > 0.001 && t < closest_t)
		{
			closest_t = t;
			closest = curr;
		}
		curr = curr->next;
	}
	*out_t = closest_t;
	return (closest);
}
