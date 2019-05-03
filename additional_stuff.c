/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_stuff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 17:47:56 by fdibbert          #+#    #+#             */
/*   Updated: 2019/01/14 18:16:24 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_default_color(int z, t_mlx *p)
{
	float	percentage;

	percentage = percent(p->z_min, p->z_max, z);
	if (percentage < 0.2)
		return (COLOR_DISCO);
	else if (percentage < 0.4)
		return (COLOR_BRICK_RED);
	else if (percentage < 0.6)
		return (COLOR_FLAMINGO);
	else if (percentage < 0.8)
		return (COLOR_JAFFA);
	else
		return (COLOR_SAFFRON);
}

int	ft_colorer(char *str, int result, int d)
{
	while (result != 0)
	{
		d = d * 16;
		result--;
	}
	while (*str != '\0')
	{
		if (*str >= 97)
			result = result + ((*str - 87) * d);
		else
			result = result + ((*str - 48) * d);
		if (d != 0)
			d /= 16;
		str++;
	}
	return (result);
}

int	ft_color(char *str, int z, t_mlx *p)
{
	int result;
	int d;

	while (*str != 120 && *str != '\0')
	{
		str++;
	}
	if (*str == '\0')
		return (get_default_color(z, p));
	str++;
	result = 0;
	while (str[result] != '\0')
		result++;
	d = 1;
	if (result > 0)
		result--;
	return (ft_colorer(str, result, d));
}
