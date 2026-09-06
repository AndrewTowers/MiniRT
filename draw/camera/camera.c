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

t_ray	generate_ray(t_data *dt, int x, int y)
{
	t_ray ray;
	t_pos	up;
	t_pos	w;
	t_pos	u;
	t_pos	v;
	double aspect;
	double scale;
	double px;
	double py;

	w = v_norm(dt->cam.dir);
	if (fabs(w.y) > 0.999f)
		up = (t_pos){0, 0, 1};
	else
		up = (t_pos){0, 1, 0};
	u = v_norm(v_cross(up, w));
	v = v_cross(w, u);
	aspect = (double)WIDTH / (double)HEIGHT;
	scale = tan((dt->cam.fov * PI / 180.0) / 2.0);
	px = (2.0 * ((x + 0.5) / WIDTH) - 1.0) * aspect * scale;
	py = (1.0 - 2.0 * ((y + 0.5) / HEIGHT)) * scale;
	ray.origin = dt->cam.pos;
	ray.dir = v_norm(v_add(v_add(w, v_scale(u, px)), v_scale(v, py)));
	return (ray);
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
		t = -1.0;
		if (curr->type == SPHERE)
			t = hit_sphere((t_sphere *)curr->figure, ray);
		else if (curr->type == PLANE)
			t = hit_plane((t_plane *)curr->figure, ray);
		else if (curr->type == CYLINDER)
			t = hit_cylinder((t_cylinder *)curr->figure, ray);

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
