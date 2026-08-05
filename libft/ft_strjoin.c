/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:05:27 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/21 15:00:27 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*uni;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	i = 0;
	uni = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!uni)
		return (NULL);
	while (i < len_s1)
	{
		uni[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len_s2)
	{
		uni[i + len_s1] = s2[i];
		i++;
	}
	uni[i + len_s1] = '\0';
	return (uni);
}
