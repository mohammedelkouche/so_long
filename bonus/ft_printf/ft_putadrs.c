/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:26:55 by mel-kouc          #+#    #+#             */
/*   Updated: 2022/11/14 14:55:39 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthexa(unsigned long p, int *count)
{
	char	*base_hex;

	base_hex = "0123456789abcdef";
	if (p < 16)
		ft_putchar(base_hex[p], count);
	else
	{
		ft_puthexa((p / 16), count);
		ft_puthexa((p % 16), count);
	}
}

void	ft_putadrs(void *p, int *count)
{
	ft_putstr("0x", count);
	ft_puthexa((unsigned long)p, count);
}
