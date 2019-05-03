/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 18:09:41 by fdibbert          #+#    #+#             */
/*   Updated: 2019/01/14 18:59:19 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

float	percent(int start, int end, int current)
{
	float	placement;
	float	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		get_light(int start, int end, float percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int		get_color(t_xyz *i, t_mlx *p, t_rastr *rs)
{
	int		red;
	int		green;
	int		blue;
	float	percentage;

	if (p->color == i->color2)
		return (p->color);
	if (rs->dx > rs->dy)
		percentage = percent(i->x, i->x2, rs->x0);
	else
		percentage = percent(i->y, i->y2, rs->y0);
	red = get_light((p->color >> 16) & 0xFF,
					(i->color2 >> 16) & 0xFF,
					percentage);
	green = get_light((p->color >> 8) & 0xFF,
					(i->color2 >> 8) & 0xFF,
					percentage);
	blue = get_light(p->color & 0xFF,
					i->color2 & 0xFF,
					percentage);
	return ((red << 16) | (green << 8) | blue);
}
