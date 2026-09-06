/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 18:41:39 by blas              #+#    #+#             */
/*   Updated: 2026/09/06 18:44:19 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mini_rt.h"

double	hit_plane(t_plane *pl, t_ray ray)
{
	double	denominator;
	double	numerator;
	double	t;

	denominator = v_dot(ray.dir, pl->normal);
	if (fabs(denominator) < 1e-6)
		return (-1.0);
	numerator = v_dot(v_sub(pl->pos, ray.origin), pl->normal);
	t = numerator / denominator;
	if (t > 0.001)
		return (t);
	return (-1.0);
}