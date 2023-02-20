/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:14:28 by mel-kouc          #+#    #+#             */
/*   Updated: 2022/11/13 18:38:54 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *count)
{
	if (n > 9)
	{
		ft_putnbr((n / 10), count);
		ft_putnbr((n % 10), count);
	}
	else if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putchar('-', count);
			ft_putchar('2', count);
			ft_putnbr(147483648, count);
		}
		else
		{
			ft_putchar('-', count);
			n = -n;
			ft_putnbr(n, count);
		}
	}
	else
		ft_putchar(n + '0', count);
}
