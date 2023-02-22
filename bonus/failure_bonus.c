/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   failure_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:52:43 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/02/22 21:49:00 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	protection(void *failur, t_info *game)
{
	if (failur == NULL)
	{
		free(failur);
		free_all(game->map, game->map_cpy);
	}
}
