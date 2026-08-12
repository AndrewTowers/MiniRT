#include "mini_rt.h"

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

int	parse_line(char *line, t_data *dt)
{
	if (!ft_strncmp(line, "A ", 2))
		return (parse_ambient(line + 2, dt));
	else if (!ft_strncmp(line, "C ", 2))
		return (parse_camera(line + 2, dt));
	else if (!ft_strncmp(line, "L ", 2))
		return (parse_light(line + 2, dt));
	else if (!ft_strncmp(line, "sp ", 3))
		return (parse_sphere(line + 3, dt));
	else if (!ft_strncmp(line, "pl ", 3))
		return (parse_plane(line + 3, dt));
	else if (!ft_strncmp(line, "cy ", 3))
		return (parse_cylinder(line + 3, dt));
	return (0);
}

int parse_sphere(char *line, t_data *dt)
{

}

int parse_plane(char *line, t_data *dt)
{

}

int parse_cylinder(char *line, t_data *dt)
{

}
