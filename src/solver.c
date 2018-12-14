/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 20:18:55 by svovchyn          #+#    #+#             */
/*   Updated: 2018/12/07 20:18:58 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		solver(char *file)
{
	t_tetris	tetri[26];
	t_map		field;
	int			t_num;

	if (!(t_num = read_and_write(file, tetri)))
		fatal_error();
	field.t_num = t_num;
	field.size = root(field.t_num * 4);
	field.map = map_create(field.size);
	while (!solution(field, tetri, 0))
	{
		map_clean(&field);
		field.map = map_create(++field.size);
	}
	tetri_clean(tetri, t_num);
	output(field.map, field.size);
	map_clean(&field);
	return (1);
}

int		solution(t_map field, t_tetris *tetri, int count)
{
	if (count == field.t_num)
		return (1);
	field.y = -1;
	while (++field.y < field.size - write_height(tetri[count].pos) + 1)
	{
		field.x = -1;
		while (++field.x < field.size - write_width(tetri[count].pos) + 1)
		{
			if (position(field, tetri[count].pos))
			{
				on_off(&field, tetri[count].pos, tetri[count].letter);
				if (solution(field, tetri, count + 1))
					return (1);
				else
					on_off(&field, tetri[count].pos, '.');
			}
		}
	}
	return (0);
}

int		read_and_write(char *file, t_tetris *tetri)
{
	char	buf[BUF_SIZE + 1];
	int		t_num;
	int		fd;
	int		r;

	t_num = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	while ((r = read(fd, buf, BUF_SIZE)) > 20)
	{
		buf[r] = '\0';
		if (!(validation(buf, 0)) ||
			!(t_num = write_and_transform(buf, tetri)))
			TETCLEAN();
	}
	buf[r] = '\0';
	if (close(fd) == -1 || !(validation(buf, 1)) ||
		!(t_num = write_and_transform(buf, tetri)))
		TETCLEAN();
	return (t_num);
}

int		blocks_validation(char *piece, int i, int touch)
{
	if (piece[i + 1] == '#')
		touch++;
	if (piece[i - 1] == '#')
		touch++;
	if (piece[i - 5] == '#')
		touch++;
	if (piece[i + 5] == '#')
		touch++;
	return (touch);
}

int		validation(char *piece, int last)
{
	int			block;
	int			touch;
	int			i;
	int			r;

	i = -1;
	r = 0;
	block = 0;
	touch = 0;
	while (piece[++i] != '\0')
	{
		while (piece[i] != '\n')
		{
			if (piece[i] == '#')
			{
				block++;
				touch = blocks_validation(piece, i, touch);
			}
			CHECK_SYMB();
		}
		CHECK_ROW();
		r++;
	}
	return ((piece[i - 1] == '\n' && ((last == 1 && piece[i - 2] != '\n') ||
	(!last && piece[i - 2] == '\n')) && block == 4 && touch >= 6));
}
