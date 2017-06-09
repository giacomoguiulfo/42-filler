/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 15:36:58 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/06/08 20:07:00 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static inline void	skip_plateau(char **line)
{
	if (!ft_strncmp(*line, "Plateau", 7))
	{
		ft_strdel(line);
		*line = read_line();
	}
}

static void			set_params(t_env *env)
{
	env->out_y = 0;
	env->out_x = 0;
	env->heatscore = 0;
	env->bestdist = env->m_rows * env->m_cols;
}

static void			set_players(t_env *env)
{
	char *line;

	line = read_line();
	if (line[10] == '1')
	{
		env->player = 'O';
		env->rival = 'X';
	}
	else
	{
		env->player = 'X';
		env->rival = 'O';
	}
	ft_strdel(&line);
}

int					main(void)
{
	t_env	env;
	char	*line;

	ft_bzero(&env, sizeof(t_env));
	set_players(&env);
	make_map(&env);
	make_heatmap(&env);
	while ((line = read_line()) != NULL)
	{
		skip_plateau(&line);
		ft_strdel(&line);
		read_map(&env);
		read_piece(&env);
		update_heatmap(&env);
		set_params(&env);
		filler(&env);
		ft_free_map(env.piece);
	}
	ft_free_map(env.map);
	ft_free_rows((void **)env.heatmap, env.m_rows);
	return (0);
}
