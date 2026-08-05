/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:54:20 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/11 15:46:39 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*a;
	char	c_t;

	c_t = (char)c;
	a = (char *)s;
	while (*a != c_t)
	{
		if (*a == '\0')
			return (0);
		a++;
	}
	return (a);
}
