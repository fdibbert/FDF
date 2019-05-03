/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:29:20 by fdibbert          #+#    #+#             */
/*   Updated: 2019/01/14 18:59:32 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		ft_changer(t_xyz *i, t_mlx *p, int id)
{
	if (id == 0)
	{
		i->z = ft_atoi(p->str[i->cnt][i->cnt2]);
		iso(&i->x, &i->y, i->z, p);
		i->x = i->x + p->b_x;
		i->y = i->y + p->b_y;
		p->color = ft_color(p->str[i->cnt][i->cnt2], i->z, p);
	}
	if (id == 1)
	{
		i->z = ft_atoi(p->str[i->cnt][i->cnt2 + 1]);
		iso(&i->x2, &i->y2, i->z, p);
		i->x2 = i->x2 + p->b_x;
		i->y2 = i->y2 + p->b_y;
		i->color2 = ft_color(p->str[i->cnt][i->cnt2 + 1], i->z, p);
	}
	if (id == 2)
	{
		i->z = ft_atoi(p->str[i->cnt + 1][i->cnt2]);
		iso(&i->x3, &i->y3, i->z, p);
		i->x2 = i->x3 + p->b_x;
		i->y2 = i->y3 + p->b_y;
		i->color2 = ft_color(p->str[i->cnt + 1][i->cnt2], i->z, p);
	}
}

void		ft_drawing2(int x, int y, t_mlx *p)
{
	t_xyz *i;

	i = malloc(sizeof(t_xyz));
	ident_xyz(i, x, y, p);
	while (i->cnt < p->limit)
	{
		while (i->cnt2 < p->limitd)
		{
			ft_changer(i, p, 0);
			if (i->cnt2 + 1 < p->limitd)
			{
				ft_changer(i, p, 1);
				ft2(i, p);
			}
			if (i->cnt + 1 < p->limit)
			{
				ft_changer(i, p, 2);
				ft2(i, p);
			}
			inc_xyz(i, p);
		}
		inc_xyz2(i, p);
	}
}
