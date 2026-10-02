/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andtruji <andtruji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 18:42:02 by blas              #+#    #+#             */
/*   Updated: 2026/09/30 18:53:29 by andtruji         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../mini_rt.h"

double	body_t(double t, t_cylinder *cy, t_ray ray)
{
	t_pos	hit;
	double	h;

	if (t < 0.001)
		return (-1.0);
	hit = v_add(ray.origin, v_scale(ray.dir, t));
	h = v_dot(v_sub(hit, cy->pos), v_norm(cy->axis));
	if (fabs(h) > cy->height / 2.0)
		return (-1.0);
	return (t);
}

double	body_roots(t_cy_info *cy_i, t_cylinder *cy, t_ray ray)
{
	double	sq;
	double	t;

	sq = sqrt(cy_i->discriminant);
	t = body_t((-cy_i->b - sq) / (2.0 * cy_i->a), cy, ray);
	if (t > 0.0)
		return (t);
	return (body_t((-cy_i->b + sq) / (2.0 * cy_i->a), cy, ray));
}

double	hit_body(t_cylinder *cy, t_ray ray)
{
	t_cy_info	cy_info;

	cy_info.oc = v_sub(ray.origin, cy->pos);
	cy_info.axis = v_norm(cy->axis);
	cy_info.radius = cy->diameter / 2.0;
	cy_info.oc_perp = v_sub(cy_info.oc, v_scale(cy_info.axis, v_dot(cy_info.oc, cy_info.axis)));
	cy_info.dir_perp = v_sub(ray.dir, v_scale(cy_info.axis, v_dot(ray.dir, cy_info.axis)));
	cy_info.a = v_dot(cy_info.dir_perp, cy_info.dir_perp);
	cy_info.b = 2.0 * v_dot(cy_info.oc_perp, cy_info.dir_perp);
	cy_info.c = v_dot(cy_info.oc_perp, cy_info.oc_perp) - (cy_info.radius * cy_info.radius);
	cy_info.discriminant = cy_info.b * cy_info.b - 4.0 * cy_info.a * cy_info.c;
	if (cy_info.discriminant < 0.0)
		return (-1.0);
	cy_info.t1 = (-cy_info.b - sqrt(cy_info.discriminant)) / (2.0 * cy_info.a);
	cy_info.t2 = (-cy_info.b + sqrt(cy_info.discriminant)) / (2.0 * cy_info.a);
	return (body_roots(&cy_info, cy, ray));
}

double	hit_cap(t_cylinder *cy, t_ray ray, double sign)
{
	t_plane	pl;
	t_pos	p;
	double	t;

	pl.normal = v_norm(cy->axis);
	pl.pos = v_add(cy->pos, v_scale(pl.normal, sign * cy->height / 2.0));
	t = hit_plane(&pl, ray);
	if (t < 0.0)
		return (-1.0);
	p = v_sub(v_add(ray.origin, v_scale(ray.dir, t)), pl.pos);
	if (v_len(p) > cy->diameter / 2.0)
		return (-1.0);
	return (t);
}

double	hit_cylinder(t_cylinder *cy, t_ray ray)
{
	double	best;
	double	t;

	best = hit_body(cy, ray);
	t = hit_cap(cy, ray, 1.0);
	if (t > 0.0 && (best < 0.0 || t < best))
		best = t;
	t = hit_cap(cy, ray, -1.0);
	if (t > 0.0 && (best < 0.0 || t < best))
		best = t;
	return (best);
}
