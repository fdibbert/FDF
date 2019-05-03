/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 19:41:54 by fdibbert          #+#    #+#             */
/*   Updated: 2019/05/03 19:44:14 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			deal_mouse(int mouse, int x, int y, t_mlx *p)
{
	mlx_clear_window(p->mlx_ptr, p->win_ptr);
	p->img_ptr = mlx_new_image(p->mlx_ptr, 1200, 1200);
	p->img_data = (int *)(mlx_get_data_addr(p->img_ptr,
	&(p->bpp), &(p->size_line), &(p->endian)));
	if (mouse == 2)
	{
		if (p->size_y > 1 && p->size_x > 1 && p->size_z > 1.0)
		{
			p->size_y -= 1;
			p->size_x -= 1;
			p->size_z -= 0.2;
		}
	}
	if (mouse == 1)
	{
		p->size_y += 1;
		p->size_x += 1;
		p->size_z += 0.2;
	}
	ft_drawing2(0, 0, p);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img_ptr, 0, 0);
	mlx_destroy_image(p->mlx_ptr, p->img_ptr);
	(void)x;
	(void)y;
	return (0);
}
