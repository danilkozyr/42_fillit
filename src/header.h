/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 20:19:18 by svovchyn          #+#    #+#             */
/*   Updated: 2018/12/07 20:19:21 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../libft/inc/libft.h"
# include <fcntl.h>

# define BUF_SIZE 21
# define CHECK_ROW() if (i > 4 && (i - r) % 4 != 0) RET();
# define CHECK_SYMB() if (piece[i] != '.' && piece[i] != '#') RET() else i++;
# define RET() return (0);
# define CHECK_TETR() if (count > 25) { tetri_clean(tetri, count); RET(); }
# define DECLARE() int row_shift; int row; int i; static unsigned int count;
# define DECLARE2() int **pos; int bit_num; int y; int x; int i;
# define TETCLEAN() { tetri_clean(tetri, t_num); RET(); }

typedef struct	s_tetri
{
	int			bit;
	int			**pos;
	char		letter;
}				t_tetris;

typedef struct	s_field
{
	int			size;
	int			t_num;
	int			x;
	int			y;
	char		**map;
}				t_map;

void			fatal_error(void);
int				warning(const char *app);
void			output(char **map, int size);
int				pauwa(int x, unsigned int y);
int				root(int x);
int				solver(char *file);
int				solution(t_map field, t_tetris *tetri, int count);
int				read_and_write(char *file, t_tetris *tetri);
int				validation(char *piece, int last);
int				blocks_validation(char *piece, int i, int touch);
char			**map_create(int size);
int				position(t_map field, int **pos);
void			map_clean(t_map *field);
void			tetri_clean(t_tetris *tetri, int t_num);
void			on_off(t_map *field, int **pos, char letter);
int				write_height(int **pos);
int				write_width(int **pos);
int				write_and_transform(char *piece, t_tetris *tetri);
int				**save_x_y(unsigned int t);

#endif
