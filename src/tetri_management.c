/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 20:20:31 by svovchyn          #+#    #+#             */
/*   Updated: 2018/12/07 20:20:34 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		write_height(int **pos)
{
	int		height;
	int		res;
	int		y;

	height = 0;
	res = 0;
	y = -1;
	while (++y < 4)
	{
		height = pos[y][0] + 1;
		res = res > height ? res : height;
	}
	return (res);
}

int		write_width(int **pos)
{
	int		width;
	int		res;
	int		x;

	width = 0;
	res = 0;
	x = -1;
	while (++x < 4)
	{
		width = pos[x][1] + 1;
		res = res > width ? res : width;
	}
	return (res);
}

void	shift(t_tetris *tetri, unsigned int count)
{
	while (!(tetri[count].bit & 0x8888))
		tetri[count].bit <<= 1;
	while (!(tetri[count].bit & 0xF000))
		tetri[count].bit <<= 4;
	tetri[count].pos = save_x_y(tetri[count].bit);
}

int		write_and_transform(char *piece, t_tetris *tetri)
{
	DECLARE();
	CHECK_TETR();
	count = count ? count : 0;
	tetri[count].letter = 'A' + count;
	tetri[count].bit = 0;
	row_shift = 0;
	row = 1;
	i = -1;
	while (++i < 20)
	{
		if (piece[i] == '#')
			tetri[count].bit |= pauwa(2, 15 - (i - row_shift));
		if (!(row % 5))
		{
			row = 1;
			row_shift += 1;
			continue ;
		}
		row++;
	}
	shift(tetri, count);
	return (++count);
}

int		**save_x_y(unsigned int t)
{
	DECLARE2();
	bit_num = 16;
	y = 0;
	x = 0;
	i = -1;
	if (!(pos = (int **)ft_memalloc(sizeof(int *) * 4)))
		return (NULL);
	while (--bit_num >= 0)
	{
		if (t & (pauwa(2, bit_num)))
		{
			if (!(pos[++i] = (int *)ft_memalloc(sizeof(int) * 2)))
				return (NULL);
			pos[i][0] = y;
			pos[i][1] = x;
		}
		if (x && !(x % 3))
		{
			y++;
			x = 0;
			continue ;
		}
		x++;
	}
	return (pos);
}
