/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 13:54:07 by blas              #+#    #+#             */
/*   Updated: 2026/09/02 12:35:19 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int	count_nodes(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && str[i] != ' ' && str[i] != '\t')
				i++;
		}
	}
	if (count == 0)
		return (-1);
	return (count);
}

int	count_splits(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

char	**split_realloc(char **strs, char *str, int i, int j)
{
	char	**new_strs;
	int		h;
	int		splits;

	h = 0;
	if (!strs)
		splits = 0;
	else
		splits = count_splits(strs);
	new_strs = malloc (sizeof(char *) * (splits + 2));
	if (!new_strs)
		return (NULL);
	while (h != splits)
	{
		new_strs[h] = ft_strdup(strs[h]);
		h++;
	}
	new_strs[h] = ft_substr(str, i, j);
	h++;
	new_strs[h] = NULL;
	ft_free_split(strs);
	return (new_strs);
}

char	**splitter(char *str)
{
	int	i;
	int	j;
	char **strs;

	i = 0;
	strs = NULL;
	while (str[i])
	{
		while (str[i] == '\t' || str[i] == ' ')
			i++;
		j = 0;
		while (str[i + j] != '\t' && str[i + j] != ' ' && str[i + j] != '\0')
			j++;
		if (str[i] != '\0')
		{
			strs = split_realloc(strs, str, i, j);
			i += j;
		}
	}
	return (strs);

}




