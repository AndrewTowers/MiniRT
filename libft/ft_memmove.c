/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:07:24 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/14 13:34:42 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_t;
	unsigned char	*src_t;

	dest_t = (unsigned char *)dest;
	src_t = (unsigned char *)src;
	i = 0;
	if ((i == n) || (dest_t == src_t))
		return (dest_t);
	if (dest_t < src_t)
	{
		while (i < n)
		{
			dest_t[i] = src_t[i];
			i++;
		}
	}
	else
	{
		while (n--)
		{
			dest_t[n] = src_t[n];
		}
	}
	return (dest_t);
}
