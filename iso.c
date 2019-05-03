/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 16:36:22 by fdibbert          #+#    #+#             */
/*   Updated: 2019/01/14 18:55:40 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		iso_project(int *x, int *y, t_mlx *param)
{
	double temp;

	if (param->key == 1)
	{
		temp = *x;
		*x = *x * cos(0.523599) + *y * cos(0.523599 + 2.0944)
		+ param->z * cos(0.523599 - 2.0944);
		*y = *x * sin(0.523599) + *y * sin(0.523599 + 2.0944)
		+ param->z * sin(0.523599 - 2.0944);
	}
}

void		iso(int *x, int *y, int z, t_mlx *p)
{
	double	t;

	p->x0 = (p->limitd * p->size_x) / 2;
	p->y0 = (p->limit * p->size_y) / 2;
	p->z = z * p->size_z;
	(void)z;
	if (p->a_x)
	{
		t = *x;
		*x = p->x0 + (t - p->x0) * cos(p->a_x) + p->z * sin(p->a_x);
		p->z = p->z * cos(p->a_x) + (-(t - p->x0)) * sin(p->a_x);
	}
	if (p->a_y)
	{
		t = *y;
		*y = p->y0 + (t - p->y0) * cos(p->a_y) - p->z * sin(p->a_y);
		p->z = p->z * cos(p->a_y) - (-(t - p->y0)) * sin(p->a_y);
	}
	if (p->a_z)
	{
		t = *x;
		*x = p->x0 + (t - p->x0) * cos(p->a_z) - (*y - p->y0) * sin(p->a_z);
		*y = p->y0 + (*y - p->y0) * cos(p->a_z) + (t - p->x0) * sin(p->a_z);
	}
	iso_project(x, y, p);
}
