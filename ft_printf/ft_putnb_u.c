/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnb_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:26:39 by mel-kouc          #+#    #+#             */
/*   Updated: 2022/11/14 18:26:43 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnb_u(unsigned int n, int *count)
{
	if (n > 9)
	{
		ft_putnb_u((n / 10), count);
		ft_putnb_u((n % 10), count);
	}
	else
		ft_putchar(n + '0', count);
}
