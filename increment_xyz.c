/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increment_xyz.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 17:36:48 by fdibbert          #+#    #+#             */
/*   Updated: 2019/05/03 19:52:51 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	inc_xyz(t_xyz *init, t_mlx *param)
{
	init->x1 = init->x1 + param->size_x;
	init->x = init->x1;
	init->x2 = init->x1 + param->size_x;
	init->y2 = init->y1;
	init->x3 = init->x1;
	init->y3 = init->y1 + param->size_y;
	init->y = init->y1;
	init->cnt2++;
}

void	inc_xyz2(t_xyz *init, t_mlx *param)
{
	init->x1 = init->x1 - (param->size_x * init->cnt2);
	init->x = init->x1;
	init->x3 = init->x1;
	init->x2 = init->x1 + param->size_x;
	init->cnt2 = 0;
	init->y1 += param->size_y;
	init->y = init->y1;
	init->y2 = init->y1;
	init->y3 = init->y1 + param->size_y;
	init->cnt++;
}
