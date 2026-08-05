/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:03:33 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/25 11:00:04 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printeger(int nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		len++;
	}
	if (nb / 10 > 0)
		len += ft_printeger(nb / 10);
	len++;
	ft_printchar(nb % 10 + '0');
	return (len);
}

int	ft_printeger_unsig(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb / 10 > 0)
		len += ft_printeger_unsig(nb / 10);
	len++;
	ft_printchar(nb % 10 + '0');
	return (len);
}

int	ft_print_hex(unsigned int nb, int upper)
{
	char	*base;
	int		size;

	base = "0123456789abcdef";
	size = 0;
	if (nb >= 16)
		size += ft_print_hex(nb / 16, upper);
	if (upper)
		size += ft_printchar(ft_toupper(base[nb % 16]));
	else
		size += ft_printchar(base[nb % 16]);
	return (size);
}

int	ft_print_address(unsigned long nb, int upper)
{
	char	*base;
	int		size;

	base = "0123456789abcdef";
	size = 0;
	if (nb == 0)
	{
		size += ft_printstr("(nil)");
		return (size);
	}
	if (nb >= 16)
		size += ft_print_address(nb / 16, upper);
	else
		size = ft_printstr("0x");
	if (upper)
		size += ft_printchar(ft_toupper(base[nb % 16]));
	else
		size += ft_printchar(base[nb % 16]);
	return (size);
}
