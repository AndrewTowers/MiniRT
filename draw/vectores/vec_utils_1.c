/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andtruji <andtruji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 15:52:15 by blas              #+#    #+#             */
/*   Updated: 2026/09/23 19:43:28 by andtruji         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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

t_pos	v_scale(t_pos v, double factor)
{
	t_pos	res;

	res.x = v.x * factor;
	res.y = v.y * factor;
	res.z = v.z * factor;
	return (res);
}
