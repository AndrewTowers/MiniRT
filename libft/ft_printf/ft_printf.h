/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:12:52 by bsiguenc          #+#    #+#             */
/*   Updated: 2025/04/25 15:47:23 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_printchar(char c);
int	ft_printeger(int nb);
int	ft_printeger_unsig(unsigned int nb);
int	ft_printstr(char *c);
int	ft_print_hex(unsigned int nb, int upper);
int	ft_print_address(unsigned long nb, int upper);
#endif