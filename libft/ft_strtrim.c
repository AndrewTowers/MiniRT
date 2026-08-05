/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:06:31 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/21 14:58:08 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_in_str(char c, const char *set)
{
	while (*set != '\0')
	{
		if (c == *set)
		{
			return (1);
		}
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s_t;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (ft_in_str(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (s1[end] != s1[start] && ft_in_str(s1[end - 1], set))
		end--;
	s_t = (char *) malloc(sizeof(char) * (end - start + 1));
	if (!s_t)
		return (NULL);
	i = 0;
	while (start < end)
		s_t[i++] = s1[start++];
	s_t[i] = '\0';
	return (s_t);
}
