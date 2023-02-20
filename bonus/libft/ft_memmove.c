/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 19:09:31 by mel-kouc          #+#    #+#             */
/*   Updated: 2022/11/09 21:27:29 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*destinaiton;
	unsigned char	*source;
	size_t			i;

	i = 0;
	destinaiton = (unsigned char *) dst;
	source = (unsigned char *) src;
	if (destinaiton == source)
		return (destinaiton);
	if (destinaiton > source)
	{
		while (i < len)
		{
			destinaiton[len - 1] = source[len - 1];
			len--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (destinaiton);
}
