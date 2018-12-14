/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 20:19:30 by svovchyn          #+#    #+#             */
/*   Updated: 2018/12/07 20:19:33 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**map_create(int size)
{
	char	**map;
	int		y;
	int		x;

	if (!(map = (char **)ft_memalloc(sizeof(char *) * size)))
		return (NULL);
	y = -1;
	while (++y < size)
	{
		if (!(map[y] = ft_strnew(size + 1)))
			return (NULL);
		x = -1;
		while (++x < size)
			map[y][x] = '.';
		map[y][x] = '\n';
		map[y][++x] = '\0';
	}
	return (map);
}

int		position(t_map field, int **pos)
{
	if ((field.map[pos[0][0] + field.y][pos[0][1] + field.x] == '.') &&
		(field.map[pos[1][0] + field.y][pos[1][1] + field.x] == '.') &&
		(field.map[pos[2][0] + field.y][pos[2][1] + field.x] == '.') &&
		(field.map[pos[3][0] + field.y][pos[3][1] + field.x] == '.'))
		return (1);
	return (0);
}

void	map_clean(t_map *field)
{
	int y;

	y = -1;
	while (++y < field->size)
		ft_memdel((void **)&(field->map[y]));
	ft_memdel((void **)&(field->map));
}

void	tetri_clean(t_tetris *tetri, int t_num)
{
	int		i;
	int		y;

	i = -1;
	while (++i < t_num)
	{
		y = -1;
		while (++y < 4)
			ft_memdel((void **)&tetri[i].pos[y]);
		ft_memdel((void **)&tetri[i].pos);
	}
}

void	on_off(t_map *field, int **pos, char letter)
{
	field->map[pos[0][0] + field->y][pos[0][1] + field->x] = letter;
	field->map[pos[1][0] + field->y][pos[1][1] + field->x] = letter;
	field->map[pos[2][0] + field->y][pos[2][1] + field->x] = letter;
	field->map[pos[3][0] + field->y][pos[3][1] + field->x] = letter;
}
