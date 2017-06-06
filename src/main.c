/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 15:36:58 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/06/05 15:35:01 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static void	read_piece(t_env *env)
{
	char	*line;
	int		i;

	i = 0;
	line = read_line();
	while (!ISDIGIT(line[i]))
		i++;
	env->p_rows = ft_atoi(line + i);
	while (ISDIGIT(line[i]))
		i++;
	env->p_rows = ft_atoi(line + i);
	ft_strdel(&line);
	env->piece = (char **)ft_memalloc(sizeof(char *) * (env->p_rows + 1));
	i = -1;
	while (++i < env->p_rows)
	{
		line = read_line();
		env->piece[i] = ft_strdup(line);
		ft_strdel(&line);
	}
}

static inline void skip_plateau(char **line)
{
	if (!ft_strncmp(*line , "Plateau", 7))
	{
		ft_strdel(line);
		*line = read_line();
	}
}

static void	set_players(t_env *env)
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

int		main(void)
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
		// debug_print_piece(&env);
		process_piece(&env);
		// debug_print_piece(&env);
		// debug_print_map(&env);
		update_heatmap(&env);
		if (env.m_rows < 20)
			small_filler(&env);
		// debug_print_heatmap(&env);
		filler(&env);
		// usleep(100000);
		// sleep(1);
		// ft_free_map(env.piece);
		// ft_free_map(env.piece);
		// sleep(1);
	}
	ft_free_map(env.map);
	ft_free_rows((void **)env.heatmap, env.m_rows);
	return (0);
}
