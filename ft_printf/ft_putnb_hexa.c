/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnb_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:16:06 by mel-kouc          #+#    #+#             */
/*   Updated: 2022/11/14 14:41:10 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnb_hexa(unsigned int n, char c, int *count)
{
	char	*hexa_base;

	if (c == 'x')
		hexa_base = "0123456789abcdef";
	else
		hexa_base = "0123456789ABCDEF";
	if (n < 16)
		ft_putchar(hexa_base[n], count);
	else
	{
		ft_putnb_hexa((n / 16), c, count);
		ft_putnb_hexa((n % 16), c, count);
	}
}
