/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_xyz.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 19:53:56 by fdibbert          #+#    #+#             */
/*   Updated: 2019/05/03 19:54:04 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ident_xyz(t_xyz *init, int x, int y, t_mlx *param)
{
	init->cnt = 0;
	init->cnt2 = 0;
	init->x = x;
	init->y = y;
	init->y3 = y + param->size_y;
	init->x3 = x;
	init->y2 = y;
	init->x2 = x + param->size_x;
	init->x1 = x;
	init->y1 = y;
}
