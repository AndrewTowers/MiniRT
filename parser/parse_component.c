/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_component.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andtruji <andtruji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 11:47:01 by andtruji          #+#    #+#             */
/*   Updated: 2026/08/24 11:47:01 by andtruji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int parse_diameter_n_height(char *dm_hg, float *dmt_hg)
{
	if (!dm_hg)
		return (0);
	*dmt_hg = ft_atof(dm_hg);
	if (*dmt_hg <= 0)
		return (0);
	return (1);
}

int parse_rgb(char *rgb_str, t_rgb *rgb)
{
	char	**split;

	split = ft_split(rgb_str, ',');
	if (!split || !split[0] || !split[1] || !split[2] || split[3])
		return (0);
	rgb->r = ft_atoi(split[0]);
	rgb->g = ft_atoi(split[1]);
	rgb->b = ft_atoi(split[2]);
	if (rgb->r < 0 || rgb->r > 255 || rgb->g < 0 || rgb->g > 255 || rgb->b < 0 || rgb->b > 255)
	{
		ft_free_split(split);
		return (0);
	}
	ft_free_split(split);
	return (1);
}

int	parse_vec(char *str, t_pos *vec)
{
	char	**split;

	split = ft_split(str, ',');
	if (!split || !split[0] || !split[1] || !split[2] || split[3])
		return (0);
	vec->x = ft_atof(split[0]);
	vec->y = ft_atof(split[1]);
	vec->z = ft_atof(split[2]);
	ft_free_split(split);
	return (1);
}
