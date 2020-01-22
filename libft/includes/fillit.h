/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 13:32:32 by panderss          #+#    #+#             */
/*   Updated: 2020/01/21 15:38:03 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 8
# define FD_MAX 4864

# include "libft.h"

typedef	struct		s_piece
{
	int				x[3];
	int				y[3];
	int				letter;
	struct s_piece	*prev;
	struct s_piece	*next;
}					t_piece;


void		backtrack(t_piece *cursor, char **map, int piece);
void		print_map(char **map);
char		**create_map(int n);
char		**initialize_map(int newlines);
int     	check_candidate(t_piece *cursor, char **map, int x, int y, int piece);
int			find_dot(t_piece *cursor, char **map, int x, int y, int piece);
int			new_line(char *file, char **grid, int lines_read);
int     	place_first(t_piece *head, char **map, int placed, int n, int start);
int     	place_piece(t_piece *head, char **map, int placed, int n, int start);
void		display_error(void);
void		traverse(t_piece* head);
void		traverse_rev(t_piece* head);
void		print_list(t_piece *cursor);
void    	solve(t_piece *head, int newlines, int max, int n, int start);
t_piece		*create_list(int *x, int *y);
t_piece		*create(int *x, int *y, t_piece *prev, t_piece *next);
t_piece		*add_piece(t_piece *ret, int *x, int *y);
t_piece		*find_coords(char **grid);
t_piece		*traverse_until(t_piece *head, int piece);

#endif
