/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:27:42 by blas              #+#    #+#             */
/*   Updated: 2026/11/10 16:02:38 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int	parse_fov(char *fov_str, double *fov)
{
	*fov = ft_atof(fov_str);
	if (*fov < 0.0 || *fov > 180.0)
		return (0);
	return (1);
}

int	parse_camera(char *args, t_data *dt)
{
	char	**parts;

	parts = splitter(args);
	if (!parts || !parts[0] || !parts[1] || !parts[2] || parts[3])
		return (ret_str("Error\nParse CAMERA", 0));
	if (dt->ready.c_ready == 0)
		dt->ready.c_ready = 1;
	else
		return (ret_str("Error\nMultiple C", 0));
	if (!parse_vec(parts[0], &dt->cam.pos)
		|| !parse_normalized_vec(parts[1], &dt->cam.dir)
		|| !parse_fov(parts[2], &dt->cam.fov))
	{
		ft_free_split(parts);
		return (ret_str("Error\nNumber params CAMERA", 0));
	}
	ft_free_split(parts);
	return (1);
}
