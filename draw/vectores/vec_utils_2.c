/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 16:23:04 by blas              #+#    #+#             */
/*   Updated: 2026/09/06 18:28:24 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mini_rt.h"

double	v_dot(t_pos	a, t_pos b)
{
	double	res;

	res = a.x * b.x + a.y * b.y + a.z * b.z;
	return (res);
}

t_pos	v_cross(t_pos a, t_pos b)
{
	t_pos	res;

	res.x = a.y * b.z - a.z * b.y;
	res.y = a.z * b.x - a.x * b.z;
	res.z = a.x * b.y - a.y * b.x;
	return (res);
}

double	v_len(t_pos v)
{
	return (sqrtl(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)));
}

t_pos	v_norm(t_pos v)
{
	double	len;
	t_pos	res;

	len = v_len(v);
	res.x = v.x / len;
	res.y = v.y / len;
	res.z = v.z / len;
	return (res);
}