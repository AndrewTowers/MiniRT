/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:59:39 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/25 15:35:51 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *c)
{
	int	i;

	i = 0;
	if (c == NULL)
	{
		i += ft_printstr("(null)");
		return (i);
	}
	while (c[i])
	{
		write(1, &c[i], 1);
		i++;
	}
	return (i);
}
