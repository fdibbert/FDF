/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 19:18:56 by fdibbert          #+#    #+#             */
/*   Updated: 2019/01/14 18:14:57 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define A 1199

void	ft_draw_y(t_xyz *i, t_mlx *param, t_rastr *r)
{
	if (r->y0 < i->y2)
	{
		while (r->y0 < i->y2 && r->y0 <= A && r->y0 >= 0
			&& r->x0 <= A && r->x0 >= 0)
		{
			param->img_data[r->x0 + (1200 * r->y0)] = get_color(i, param, r);
			r->y0 = r->y0 + 1;
		}
	}
	else if (r->y0 > i->y2)
	{
		while (r->y0 > i->y2 && r->y0 <= A && r->y0 >= 0
			&& r->x0 <= A && r->x0 >= 0)
		{
			param->img_data[r->x0 + (1200 * r->y0)] = get_color(i, param, r);
			r->y0 = r->y0 - 1;
		}
	}
}

void	ft_draw_x(t_xyz *i, t_mlx *param, t_rastr *r)
{
	while (r->x0 < i->x2)
	{
		if (r->y0 <= A && r->y0 >= 0 && r->x0 <= A && r->x0 >= 0)
			param->img_data[r->x0 + (1200 * r->y0)] = get_color(i, param, r);
		r->e = r->e + r->de;
		r->x0++;
		while (r->e >= 0.5)
		{
			r->y0 = r->y0 + r->dr;
			r->e -= 1.0;
			if (r->y0 <= A && r->y0 >= 0 && r->x0 <= A && r->x0 >= 0)
				param->img_data[r->x0 +
					(1200 * r->y0)] = get_color(i, param, r);
		}
	}
}

void	ft_draw_x2(t_xyz *i, t_mlx *param, t_rastr *r)
{
	while (r->x0 > i->x2)
	{
		if (r->y0 <= A && r->y0 >= 0 && r->x0 <= A && r->x0 >= 0)
			param->img_data[r->x0 + (1200 * r->y0)] = get_color(i, param, r);
		r->e = r->e + r->de;
		r->x0--;
		while (r->e >= 0.5)
		{
			r->y0 = r->y0 + r->dr;
			r->e -= 1.0;
			if (r->y0 <= A && r->y0 >= 0 && r->x0 <= A && r->x0 >= 0)
				param->img_data[r->x0 +
					(1200 * r->y0)] = get_color(i, param, r);
		}
	}
}

void	ft2(t_xyz *i, t_mlx *param)
{
	t_rastr *rast;

	rast = malloc(sizeof(t_rastr));
	rast->dx = abs(i->x2 - i->x);
	rast->dy = abs(i->y2 - i->y);
	rast->e = 0;
	rast->y0 = i->y;
	rast->x0 = i->x;
	rast->dr = i->y2 - i->y;
	if (rast->dr > 0)
		rast->dr = 1;
	if (rast->dr < 0)
		rast->dr = -1;
	if (rast->dx != 0)
		rast->de = (float)rast->dy / (float)rast->dx;
	if (rast->x0 == i->x2)
		ft_draw_y(i, param, rast);
	if (rast->x0 < i->x2)
		ft_draw_x(i, param, rast);
	if (rast->x0 > i->x2)
		ft_draw_x2(i, param, rast);
}
