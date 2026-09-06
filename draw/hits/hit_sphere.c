/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 18:42:23 by blas              #+#    #+#             */
/*   Updated: 2026/09/06 18:43:00 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mini_rt.h"

double	hit_sphere(t_sphere *sp, t_ray ray)
{
	t_pos	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	t1;
	double	t2;
	double	radius;

	radius = sp->diameter / 2.0;
	oc = v_sub(ray.origin, sp->pos);
	a = v_dot(ray.dir, ray.dir);
	b = 2.0 * v_dot(oc, ray.dir);
	c = v_dot(oc, oc) - (radius * radius);
	discriminant = (b * b) - (4.0 * a * c);
	if (discriminant < 0.0)
		return (-1.0);
	t1 = (-b - sqrt(discriminant)) / (2.0 * a);
	t2 = (-b + sqrt(discriminant)) / (2.0 * a);
	if (t1 > 0.001)
		return (t1);
	if (t2 > 0.001)
		return (t2);
	return (-1.0);
}
