/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 15:35:19 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/05/27 04:34:52 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <libft.h>
# include <stdbool.h>

# define HEATMAX 100

typedef struct 	s_env
{
	int			**heatmap;
	int			m_rows;
	int			m_cols;
	int			p_rows;
	int			p_cols;
	int			pbox_rows;
	int			pbox_cols;
	int			top_shift;
	int			left_shift;
	int			out_x;
	int			out_y;
	int			heatscore;
	char		player;
	char		rival;
	char		**map;
	char		**piece;
	char		**piecebox;
}				t_env;

void			filler(t_env *env);
void			process_piece(t_env *env);
void			make_heatmap(t_env *env);
void			update_heatmap(t_env *env);

#endif
