/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 20:19:06 by svovchyn          #+#    #+#             */
/*   Updated: 2018/12/07 20:19:09 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	fatal_error(void)
{
	ft_putstr_fd("error\n", 1);
	exit(EXIT_FAILURE);
}

int		warning(const char *app)
{
	ft_putstr_fd("usage: ", STDERR_FILENO);
	ft_putstr_fd(app, STDERR_FILENO);
	ft_putstr_fd(" [input file]\n", STDERR_FILENO);
	return (1);
}

void	output(char **map, int size)
{
	int		y;

	y = -1;
	while (++y < size)
		ft_putstr_fd(map[y], 1);
}

int		pauwa(int x, unsigned int y)
{
	int		i;

	if (y == 0)
		return (1);
	i = pauwa(x, y / 2);
	if (y % 2 == 0)
		return (i * i);
	else
		return (x * i * i);
}

int		root(int x)
{
	int i;

	i = 2;
	while (i * i < x)
		i++;
	return (i);
}
