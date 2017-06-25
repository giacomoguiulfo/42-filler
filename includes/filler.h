/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 15:35:19 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/06/10 02:01:46 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <libft.h>
# include <stdio.h>
# include <stdbool.h>

# define HEATMAX 11
# define DIVISH 1.3
# define FILLER_BUFF 4096

typedef struct	s_env
{
	float		dist;
	float		bestdist;
	int			**heatmap;
	int			out_x;
	int			out_y;
	int			m_rows;
	int			m_cols;
	int			p_rows;
	int			p_cols;
	int			heatscore;
	int			piece_pos_x;
	int			piece_pos_y;
	int			rival_pos_x;
	int			rival_pos_y;
	char		player;
	char		rival;
	char		**map;
	char		**piece;
}				t_env;

/*
** Algorithm
*/

void			filler(t_env *env);

/*
** Heatmap
*/

void			make_heatmap(t_env *env);
void			update_heatmap(t_env *env);

/*
** Utils
*/

char			*read_line(void);
int				make_map(t_env *env);
int				read_map(t_env *env);
int				read_piece(t_env *env);
void			get_rival_pos(t_env *env);

/*
** Debug Functions
*/

void			debug_print_map(t_env *env);
void			debug_print_piece(t_env *env);
void			debug_print_heatmap(t_env *env);

#endif
