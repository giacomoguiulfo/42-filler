/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 15:36:58 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/06/25 01:02:28 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static inline void	skip_plateau(char **line)
{
	if (!ft_strncmp(*line, "Plateau", 7))
	{
		ft_strdel(line);
		get_next_line(STDIN_FILENO, line);
	}
}

static void			set_params(t_env *env)
{
	env->out_y = 0;
	env->out_x = 0;
	env->heatscore = 0;
	env->bestdist = env->m_rows * env->m_cols;
}

static int			set_players(t_env *env)
{
	char *line;

	get_next_line(STDIN_FILENO, &line);
	if (ft_strchr(line, '1') != NULL)
	{
		env->player = 'O';
		env->rival = 'X';
	}
	else if (ft_strchr(line, '2') != NULL)
	{
		env->player = 'X';
		env->rival = 'O';
	}
	else
	{
		ft_strdel(&line);
		ft_dprintf(2, "Error: invalid player\n");
		return (1);
	}
	ft_strdel(&line);
	return (0);
}

int					main(void)
{
	t_env	env;
	char	*line;

	ft_bzero(&env, sizeof(t_env));
	if (set_players(&env))
		return (1);
	if (make_map(&env))
		return (2);
	make_heatmap(&env);
	while ((get_next_line(STDIN_FILENO, &line) > 0))
	{
		skip_plateau(&line);
		ft_strdel(&line);
		if (read_map(&env))
			return (3);
		if (read_piece(&env))
			return (4);
		update_heatmap(&env);
		// debug_print_heatmap(&env);
		set_params(&env);
		filler(&env);
		// sleep(1);
		ft_free_map(env.piece);
	}
	ft_free_map(env.map);
	ft_free_rows((void **)env.heatmap, env.m_rows);
	return (0);
}
