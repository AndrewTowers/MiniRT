/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:35:21 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/21 14:59:06 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	size;
	int	neg;

	size = 0;
	neg = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		neg = 1;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size + neg);
}

char	*ft_itoa(int n)
{
	long	nb;
	size_t	size;
	char	*s;

	nb = n;
	size = count_digits(n);
	s = malloc (sizeof(char) * (size + 1));
	if (!s)
		return (NULL);
	s[size] = '\0';
	if (nb < 0)
	{
		s[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		s[0] = '0';
	while (nb > 0)
	{
		s[--size] = (nb % 10) + '0';
		nb /= 10;
	}
	return (s);
}
