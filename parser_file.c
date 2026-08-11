/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 12:30:40 by bsiguenc          #+#    #+#             */
/*   Updated: 2026/08/11 13:52:59 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	parse_file(t_data *dt)
{
	char	*str;

	str = get_next_line(dt->fd_rt);
	while (str != NULL)
	{
		ft_printf("%s", str);
		str = get_next_line(dt->fd_rt);
	}
	return (0);
}