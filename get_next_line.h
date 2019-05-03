/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:32:16 by fdibbert          #+#    #+#             */
/*   Updated: 2019/05/03 19:49:28 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10000

# include "sys/types.h"
# include "sys/uio.h"
# include "unistd.h"
# include "stdlib.h"
# include "libft/libft.h"

# include "mlx.h"
# include "unistd.h"
# include "stdlib.h"
# include "fcntl.h"
# include "stdio.h"
# include "math.h"

# define COLOR_DISCO		0x9A1F6A
# define COLOR_BRICK_RED	0xC2294E
# define COLOR_FLAMINGO		0xEC4B27
# define COLOR_JAFFA		0xEF8633
# define COLOR_SAFFRON		0xF3AF3D

typedef struct	s_mlx
{
	char	***str;
	int		*img_data;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		key;
	int		bpp;
	int		size_line;
	int		endian;
	int		x;
	int		y;
	int		x0;
	int		y0;
	float	z;
	int		z_max;
	int		z_min;
	int		b_x;
	int		b_y;
	int		limit;
	int		limitd;
	int		size_x;
	int		size_y;
	float	size_z;
	float	a_z;
	float	a_y;
	float	a_x;
	int		mouse_num;
	int		color;
}				t_mlx;

typedef struct	s_xyz
{
	int cnt;
	int cnt2;
	int x;
	int y;
	int z;
	int x1;
	int y1;
	int x2;
	int y2;
	int x3;
	int y3;
	int	color2;
}				t_xyz;

typedef struct	s_rastr
{
	float	dx;
	float	dy;
	float	e;
	float	de;
	int		y0;
	int		x0;
	int		color;
	int		dr;
	int		x;
	int		y;
	int		x1;
	int		y1;
}				t_rastr;

int				ft_new_line(char **s, char **line, int fd, int ret);
int				get_next_line(const int fd, char **line);
void			ft2(t_xyz *i, t_mlx *param);
int				deal_mouse(int mouse, int x, int y, t_mlx *param);
void			ft_drawing2(int x, int y, t_mlx *param);
void			ident_xyz(t_xyz *init, int x, int y, t_mlx *param);
void			inc_xyz(t_xyz *init, t_mlx *param);
void			inc_xyz2(t_xyz *init, t_mlx *param);
int				ft_color(char *str, int z, t_mlx *p);
int				deal_key(int key, t_mlx *param1);
void			iso(int *x, int *y, int z, t_mlx *p);
float			percent(int start, int end, int current);
int				ft_color(char *str, int z, t_mlx *p);
float			percent(int start, int end, int current);
int				get_color(t_xyz *i, t_mlx *p, t_rastr *rs);
int				get_light(int start, int end, float percentage);

#endif
