/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:30:37 by mel-kouc          #+#    #+#             */
/*   Updated: 2022/11/09 21:26:29 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	num_alloc(long nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = -nb;
		count++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

static	char	*case_alloc(long n, char *allocation, int i)
{
	int	start;

	allocation[i--] = '\0';
	if (n < 0)
	{
		n = -n;
		start = 1;
		allocation[0] = '-';
	}
	else
		start = 0;
	while (i >= start)
	{
		allocation[i] = (n % 10) + '0';
		n = (n / 10);
		i--;
	}
	return (allocation);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*allocation;
	char	*result;
	long	n1;

	n1 = (long)n;
	i = num_alloc(n1);
	allocation = (char *)malloc(sizeof(char) * i + 1);
	if (!allocation)
		return (NULL);
	result = case_alloc(n1, allocation, i);
	return (result);
}
