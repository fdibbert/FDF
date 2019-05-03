/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 22:12:53 by fdibbert          #+#    #+#             */
/*   Updated: 2019/05/03 19:48:55 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	deal_key3(int key, t_mlx *p)
{
	if (key == 4)
	{
		p->a_x = 0.0;
		p->a_y = 0.0;
		p->a_z = 0.0;
		p->b_x = 600;
		p->b_y = 600;
		p->key = 1;
	}
	if (key == 3)
	{
		p->b_x = 600;
		p->b_y = 600;
		p->key = 1;
	}
	if (key == 5)
	{
		p->key = 0;
		p->b_x = 600 - p->limitd * (p->size_x / 2);
		p->b_y = 600 - p->limit * (p->size_y / 2);
	}
	mlx_clear_window(p->mlx_ptr, p->win_ptr);
	ft_drawing2(0, 0, p);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img_ptr, 0, 0);
	mlx_destroy_image(p->mlx_ptr, p->img_ptr);
}

// void	deal_key4(int key, t_mlx *p)
// {
// 	key == 6 ? (p->size_z += 0.5) : 0;
// 	key == 7 ? (p->size_z -= 0.5) : 0;
// 	if (key == 14)
// 	{
// 		p->a_x += 0.1;
// 		p->mouse_num = 14;
// 	}
// 	deal_key5(key, p);
// }

// void	deal_key3(int key, t_mlx *p)
// {
// 	key == 124 ? (p->b_x += 20) : 0;
// 	key == 13 ? (p->a_z -= 0.1) : 0;
// 	if (key == 12)
// 	{
// 		p->a_x -= 0.1;
// 		p->mouse_num = 14;
// 	}
// 	deal_key4(key, p);
// }

void	deal_key2(int key, t_mlx *p)
{
	key == 126 ? (p->b_y -= 20) : 0;
	key == 125 ? (p->b_y += 20) : 0;
	key == 123 ? (p->b_x -= 20) : 0;
	key == 124 ? (p->b_x += 20) : 0;
	key == 13 ? (p->a_z -= 0.1) : 0;
	key == 6 ? (p->size_z += 0.5) : 0;
	key == 7 ? (p->size_z -= 0.5) : 0;
	if (key == 14)
	{
		p->a_x += 0.1;
		p->mouse_num = 14;
	}
	if (key == 12)
	{
		p->a_x -= 0.1;
		p->mouse_num = 14;
	}
	deal_key3(key, p);
}

int		deal_key(int key, t_mlx *p)
{
	p->img_ptr = mlx_new_image(p->mlx_ptr, 1200, 1200);
	p->img_data = (int *)(mlx_get_data_addr(p->img_ptr, &(p->bpp),
	&(p->size_line), &(p->endian)));
	key == 53 ? exit(0) : 0;
	if (key == 0)
	{
		p->a_y += 0.1;
		p->mouse_num = 0;
	}
	key == 1 ? (p->a_z += 0.1) : 0;
	if (key == 2)
	{
		p->a_y -= 0.1;
		p->mouse_num = 0;
	}
	deal_key2(key, p);
	return (0);
}
