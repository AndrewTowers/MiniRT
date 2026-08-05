/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:56:58 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/21 15:00:14 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_delimits(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	return (i);
}

static int	ft_free_strs(char **strs, size_t j)
{
	while (j > 0)
	{
		j--;
		free(strs[j]);
	}
	free(strs);
	return (0);
}

static	int	ft_do_split(char **strs, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	h;

	j = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		i = 0;
		while (s[i] && s[i] != c)
			i++;
		strs[j] = (char *)malloc(sizeof(char) * (i + 1));
		if (!strs[j])
			return (ft_free_strs(strs, j));
		h = 0;
		while (h < i)
			strs[j][h++] = *s++;
		strs[j++][h] = '\0';
	}
	strs[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;

	if (!s)
		return (NULL);
	strs = (char **)malloc(sizeof(char *) * (ft_delimits(s, c) + 1));
	if (!strs)
		return (NULL);
	if (!ft_do_split(strs, s, c))
		return (NULL);
	return (strs);
}
