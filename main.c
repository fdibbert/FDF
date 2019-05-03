/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 19:21:03 by fdibbert          #+#    #+#             */
/*   Updated: 2019/05/03 19:52:16 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		needlen(int fd, t_mlx *param)
{
	char	buff[2000];
	int		reader;
	int		count;

	param->limitd = 0;
	param->limit = 0;
	count = 0;
	while ((reader = read(fd, buff, 2000)) > 0)
	{
		buff[reader] = '\0';
		while (buff[count] != '\0')
		{
			if (buff[count] == '\n')
				param->limit++;
			count++;
		}
		count = 0;
	}
	close(fd);
}

void		check_z(t_mlx *param)
{
	int	count;
	int count2;

	count = 0;
	count2 = 0;
	while (count2 < param->limit)
	{
		while (param->str[count2][count] != NULL)
		{
			if (ft_atoi(param->str[count2][count]) > param->z_max)
				param->z_max = ft_atoi(param->str[count2][count]);
			if (ft_atoi(param->str[count2][count]) < param->z_min)
				param->z_min = ft_atoi(param->str[count2][count]);
			count++;
		}
		count2++;
		count = 0;
	}
}

void		start_mlx(t_mlx *param, char ***size)
{
	while (size[0][param->limitd] != NULL)
		param->limitd++;
	param->size_x = 1200 / param->limitd;
	if (param->size_x > 20)
		param->size_x = 20;
	param->size_y = 1200 / param->limit;
	if (param->size_y > 20)
		param->size_y = 20;
	param->b_x = 0;
	param->b_y = 0;
	param->a_x = 0;
	param->a_y = 0;
	param->a_z = 0;
	param->z_max = 0;
	param->mouse_num = 0;
	param->z_min = 0;
	param->key = 0;
	param->size_z = 3;
	param->str = size;
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr, 1200, 1200, "hi");
	check_z(param);
}

int			main(int argc, char *argv[])
{
	t_mlx	*init;
	int		fd;
	int		count;
	char	***size;
	char	*kat;

	if (argc != 2)
	{
		write(1, "wrong nubmer of parametrs\n", 27);
		exit(0);
	}
	count = -1;
	init = malloc(sizeof(t_mlx));
	if (((fd = open(argv[1], O_RDONLY)) < 0))
		exit(0);
	needlen(fd, init);
	size = malloc(sizeof(char ***) * init->limit);
	((fd = open(argv[1], O_RDONLY)) < 0) ? exit(0) : 0;
	while (get_next_line(fd, &kat))
		size[++count] = ft_strsplit(kat, ' ');
	start_mlx(init, size);
	deal_key(0, init);
	mlx_hook(init->win_ptr, 4, 0, deal_mouse, init);
	mlx_key_hook(init->win_ptr, deal_key, init);
	mlx_loop(init->mlx_ptr);
}
