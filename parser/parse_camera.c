/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andtruji <andtruji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 11:48:44 by andtruji          #+#    #+#             */
/*   Updated: 2026/08/24 11:48:44 by andtruji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int parse_fov(char *fov_str, float *fov)
{
    *fov = ft_atof(fov_str);
    if (*fov < 0.0 || *fov > 180.0)
        return (0);
    return (1);
}

int parse_camera(char *args, t_data *dt)
{
    char    **parts;

    parts = ft_split(args, ' ');
    if (!parts || !parts[0] || !parts[1] || !parts[2] || parts[3])
        return (0);
    if (!parse_vec(parts[0], &dt->cam.pos) || !parse_vec(parts[1], &dt->cam.dir)
        || !parse_fov(parts[2], &dt->cam.fov))
    {
        ft_free_split(parts);
        return (0);
    }
    ft_free_split(parts);
    return (1);
}