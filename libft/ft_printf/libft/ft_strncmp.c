/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:40:58 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/11 15:47:00 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n <= 0)
		return (0);
	while (n - 1 != 0 && *s1 == *s2 && (*s1 != '\0' || *s2 != '\0'))
	{
		n--;
		s1++;
		s2++;
	}
	if (*s1 != *s2)
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	return (0);
}
