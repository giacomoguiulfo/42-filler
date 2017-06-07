/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 15:35:19 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/06/07 10:03:36 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <libft.h>
# include <stdio.h>
# include <stdbool.h>

# define HEATMAX 100
# define FILLER_BUFF 4096

typedef struct	s_env
{
	int			**heatmap;
	int			m_rows;
	int			m_cols;
	int			p_rows;
	int			p_cols;
	int			out_x;
	int			out_y;
	int			heatscore;
	int			player_pos_x;
	int			player_pos_y;
	int			special:1;
	char		player;
	char		rival;
	char		**map;
	char		**piece;
}				t_env;

/*
** Algorithms
*/

void			filler(t_env *env);
void			small_filler(t_env *env);

/*
** Heatmap
*/

void			make_heatmap(t_env *env);
void			update_heatmap(t_env *env);
void			fill_heatmap(t_env *env, int y, int x, int heatmax);

/*
** Map Functions
*/

void			make_map(t_env *env);
void			read_map(t_env *env);

/*
** Utils
*/

char			*read_line(void);
void			get_player_pos(t_env *env);

/*
** Debug Functions
*/

void			debug_print_map(t_env *env);
void			debug_print_piece(t_env *env);
void			debug_print_heatmap(t_env *env);

#endif
