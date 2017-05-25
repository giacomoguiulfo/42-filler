/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 15:35:19 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/05/24 23:39:54 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <libft.h>

# define HEATMAX 100

typedef struct 	s_env
{
	int			**heat;
	int			m_rows;
	int			m_cols;
	int			p_row;
	int			p_col;
	int			in_x;
	int			in_y;
	char		player;
	char		rival;
	char		**map;
	char		**piece;
}				t_env;

void			filler(t_env *env);

/*
** Heat Map Functions
*/

void			fl_make_heatmap(t_env *env);
void			fl_update_heatmap(t_env *env);

#endif
