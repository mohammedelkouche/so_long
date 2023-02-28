/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   failure.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:21:09 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/02/28 12:21:12 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	protection(void *failur, t_info *game)
{
	if (failur == NULL)
	{
		free(failur);
		free_all(game->map, game->map_cpy);
	}
}
