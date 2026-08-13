#include "mini_rt.h"

int parse_diameter_height(char *dm_hg, float *dmt_hg)
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
	rgb->x = ft_atoi(split[0]);
	rgb->y = ft_atoi(split[1]);
	rgb->z = ft_atoi(split[2]);
	if (rgb->x < 0 || rgb->x > 255 || rgb->y < 0 || rgb->y > 255 || rgb->z < 0 || rgb->z > 255)
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
		return (1);
	vec->x = ft_atof(split[0]);
	vec->y = ft_atof(split[1]);
	vec->z = ft_atof(split[2]);
	ft_free_split(split);
	return (0);
}
