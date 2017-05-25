/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 15:36:58 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/05/24 23:47:05 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

// static void	fl_answer(t_env env)
// {
// 	env.in_x = 5;
// 	env.in_y = 7;
// 	// Testing
// 	// ft_putstr_fd(ft_itoa(env.in_x), 2);
// 	// ft_putchar_fd(' ', 2);
// 	// ft_putstr_fd(ft_itoa(env.in_y), 2);
// 	// ft_putchar_fd('\n', 2);
// 	// Real -----------------------
// 	ft_putnbr(env.in_x);
// 	// ft_putstr_fd(ft_itoa(env.in_x), 1);
// 	ft_putchar_fd(' ', 1);
//
// 	// ft_putstr_fd(ft_itoa(env.in_y), 1);
// 	ft_putchar_fd('\n', 1);
// }
//
static void	fl_read_piece(t_env *env)
{
	char	**data;
	char	*line;
	int		i;

	i = 0;
	get_next_line(0, &line);
	data = ft_strsplit(line, ' ');
	env->p_row = ft_atoi(data[1]);
	env->p_col = ft_atoi(data[2]);
	ft_free_map(data);
	ft_strdel(&line);
	env->piece = (char **)ft_memalloc(sizeof(char *) * (env->p_row + 1));
	while (i < env->p_row)
	{
		get_next_line(0, &line);
		env->piece[i] = ft_strdup(line);
		ft_strdel(&line);
		i++;
	}
}

static void	fl_set_players(t_env *env)
{
	char *line;

	get_next_line(0, &line);
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

static void	fl_make_map(t_env *env)
{
	char	**data;
	char	*line;
	int		i;

	i = 0;
	get_next_line(0, &line);
	data = ft_strsplit(line, ' ');
	env->m_rows = ft_atoi(data[1]);
	env->m_cols = ft_atoi(data[2]);
	env->map = (char **)ft_memalloc(sizeof(char *) * (env->m_rows + 1));
	while (i < env->m_rows)
		env->map[i++] = (char *)ft_memalloc(sizeof(char) * (env->m_cols + 1));
	ft_strdel(&line);
	ft_free_map(data);
}

static void	fl_read_map(t_env *env)
{
	char	*line;
	int		i;

	i = 0;
	while (i < env->m_rows)
	{
		get_next_line(0, &line);
		ft_memcpy(env->map[i], &line[4], env->m_cols);
		ft_strdel(&line);
		i++;
	}
}

int		main(void)
{
	t_env env;
	char *line;

	fl_set_players(&env);
	fl_make_map(&env);
	fl_make_heatmap(&env);
	while (get_next_line(0, &line) > 0)
	{
		fl_read_map(&env);
		/* Print Map */
		ft_dprintf(2, "%{bgreen}Map:%{eoc}\n");
		for (int i = 0; i < env.m_rows; i++)
			ft_dprintf(2, "%{bgreen}%s%{eoc}\n", env.map[i]);
		/* --------- */
		fl_update_heatmap(&env);
		/* Print HeatMap */
		ft_dprintf(2, "%{bgreen}Heat Map:%{eoc}\n");
		for (int i = 0; i < env.m_rows; i++)
		{
			for (int j = 0; j < env.m_cols; j++)
				ft_dprintf(2, "%{bgreen}%4d%{eoc}", env.heat[i][j]);
			ft_dprintf(2, "\n");
		}
		/* ------------- */
		fl_read_piece(&env);
		/* Print Piece */
		ft_dprintf(2, "%{bgreen}Piece:%{eoc}\n");
		for (int i = 0; i < env.p_row; i++)
			ft_dprintf(2, "%{bgreen}%s%{eoc}\n", env.piece[i]);
		/* -----------*/
		ft_strdel(&line);
	}
	return (0);
}
