/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 15:52:15 by blas              #+#    #+#             */
/*   Updated: 2026/09/06 18:54:32 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mini_rt.h"

t_pos	v_add(t_pos a, t_pos b)
{
	t_pos	res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	res.z = a.z + b.z;
	return (res);
}

t_pos	v_sub(t_pos a, t_pos b)
{
	t_pos	res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	return (res);
}

t_pos	v_scale(t_pos v, float factor)
{
	t_pos	res;

	res.x = v.x * factor;
	res.y = v.y * factor;
	res.z = v.z * factor;
	return (res);
}
