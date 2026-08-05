/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:03:57 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/15 16:33:57 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*pointer;

	pointer = malloc (nmemb * size);
	if (!pointer)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		((char *)pointer)[i] = '\0';
		i++;
	}
	return (pointer);
}
