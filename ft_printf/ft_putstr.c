/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:12:58 by mel-kouc          #+#    #+#             */
/*   Updated: 2022/11/14 17:50:11 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *count)
{
	int	i;

	if (!s)
	{
		ft_putstr("(null)", count);
		return ;
	}
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i], count);
		i++;
	}
}
