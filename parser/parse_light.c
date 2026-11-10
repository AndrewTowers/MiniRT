/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andtruji <andtruji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 11:48:53 by andtruji          #+#    #+#             */
/*   Updated: 2026/11/10 03:36:53 by andtruji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int	parse_ratio(char *ratio_str, double *ratio)
{
	*ratio = ft_atof(ratio_str);
	if (*ratio < 0.0 || *ratio > 1.0)
		return (0);
	return (1);
}

int parse_ambient(char *args, t_data *dt)
{
	char	**parts;

	parts = splitter(args);
	if (!parts || !parts[0] || !parts[1] || parts[2])
		return (0);
	if (!parse_ratio(parts[0], &dt->aml.ratio) || !parse_rgb(parts[1], &dt->aml.rgb))
	{
		ft_free_split(parts);
		return (0);
	}
	ft_free_split(parts);
	return (1);
}

int	parse_light(char *args, t_data *dt)
{
	char **parts;
	t_light	*new_light;

	parts = splitter(args);
	if (!parts || !parts[0] || !parts[1] || !parts[2] || parts[3])
		return (0);
	new_light = malloc(sizeof(t_light));
	if (!new_light)
		return (ft_free_split(parts), 0);
	if (!parse_vec(parts[0], &new_light->pos) || !parse_ratio(parts[1], &new_light->ratio)
	|| !parse_rgb(parts[2], &new_light->rgb))
	{
		free(new_light);
		ft_free_split(parts);
		return (0);
	}
	new_light->next = dt->light;
	dt->light = new_light;
	ft_free_split(parts);
	return (1);	
}
