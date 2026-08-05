/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:52:19 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/10 14:23:10 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_t;
	unsigned char	*s2_t;

	s1_t = (unsigned char *) s1;
	s2_t = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (s1_t[i] != s2_t[i])
			return (s1_t[i] - s2_t[i]);
		i++;
	}
	return (0);
}
