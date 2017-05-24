/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 15:35:19 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/05/23 02:21:41 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <libft.h>

typedef struct 	s_env
{
	int			rows;
	int			cols;
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

#endif
