/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 15:35:19 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/05/27 00:38:12 by gguiulfo         ###   ########.fr       */
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
	int			out_x;
	int			out_y;
	int			heatscore;
	char		player;
	char		rival;
	char		**map;
	char		**piece;
}				t_env;

void			filler(t_env *env);

/*
** Heat Map Functions
*/

void			make_heatmap(t_env *env);
void			update_heatmap(t_env *env);

#endif
