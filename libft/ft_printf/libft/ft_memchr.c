/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:08:26 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/10 14:25:17 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_t;

	s_t = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (s_t[i] == (unsigned char)c)
			return ((void *)(s_t + i));
		i++;
	}
	return (0);
}
