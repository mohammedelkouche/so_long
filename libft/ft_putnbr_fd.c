/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:22:26 by mel-kouc          #+#    #+#             */
/*   Updated: 2022/11/09 21:27:49 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n > 9)
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putnbr_fd((n % 10), fd);
	}
	else if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putchar_fd ('-', fd);
			ft_putchar_fd ('2', fd);
			ft_putnbr_fd (147483648, fd);
		}
		else
		{
			ft_putchar_fd ('-', fd);
			n = -n;
			ft_putnbr_fd (n, fd);
		}
	}
	else
		ft_putchar_fd (n + '0', fd);
}
