/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 11:10:17 by mel-kouc          #+#    #+#             */
/*   Updated: 2022/11/14 18:10:55 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, char c, int *count)
{
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (c == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (c == 'x' || c == 'X')
		ft_putnb_hexa(va_arg(args, unsigned int), c, count);
	else if (c == 'u')
		ft_putnb_u(va_arg(args, unsigned int), count);
	else if (c == 'p')
		ft_putadrs(va_arg(args, void *), count);
	else if (c == '%')
		ft_putchar('%', count);
	else
		ft_putchar(c, count);
	return (*count);
}
