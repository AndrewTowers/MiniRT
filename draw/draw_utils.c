/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 01:26:31 by blas              #+#    #+#             */
/*   Updated: 2026/09/06 18:39:02 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int	get_object_color(t_object *obj)
{
	t_rgb	rgb;

	if (obj->type == SPHERE)
		rgb = ((t_sphere *)obj->figure)->rgb;
	else if (obj->type == PLANE)
		rgb = ((t_plane *)obj->figure)->rgb;
	else if (obj->type == CYLINDER)
		rgb = ((t_cylinder *)obj->figure)->rgb;
	else
		return (0x000000);
	return (create_trgb(0, rgb.r, rgb.g, rgb.b));
}
