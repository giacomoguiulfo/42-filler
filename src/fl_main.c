/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 15:36:58 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/05/23 02:55:28 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static void	fl_answer(t_env env)
{
	// Testing
	ft_putstr_fd(ft_itoa(env.in_x), 2);
	ft_putchar_fd(' ', 2);
	ft_putstr_fd(ft_itoa(env.in_y), 2);
	ft_putchar_fd('\n', 2);
	// Real -----------------------
	ft_putstr(ft_itoa(env.in_x));
	ft_putchar(' ');
	ft_putstr(ft_itoa(env.in_y));
	ft_putchar('\n');
}

static char	**fl_get_piece(t_env *env, char *line)
{
	char	**piece;
	char	**info;
	int		i;

	info = ft_strsplit(line, ' ');
	env->p_row = ft_atoi(info[1]);
	env->p_col = ft_atoi(info[2]);
	free(line);
	piece = (char **)malloc(sizeof(char *) * (env->p_row + 1));
	i = 0;
	while (i < env->p_row)
	{
		get_next_line(0, &line);
		piece[i] = ft_strdup(line);
		free(line);
		i++;
	}
	piece[i] = NULL; //TODO: I don't need to null terminate it
	return (piece);
	// ft_dprintf(2, "Piece info, y: %d, x: %d\n", env->p_row, env->p_col);
}

static char	**fl_get_map(t_env *env, char *line)
{
	char **map;
	char **info;
	int		i;

	info = ft_strsplit(line, ' ');
	ft_dprintf(STDERR_FILENO, "here!!!!!!! [%s]\n", info[0]);
	// if (!info[0] || !info[1] || !info[2]) // Do I need to check errors?
	// {
	// 	return (NULL);
	// }
	env->rows = ft_atoi(info[1]);
	ft_dprintf(STDERR_FILENO, "Here: %d\n", env->rows);
	env->cols = ft_atoi(info[2]);
	free(line);
	ft_free_map(info);
	map = (char **)malloc(sizeof(char *) * (env->rows + 1));
	get_next_line(0, &line);
	free(line);
	i = 0;
	while (i < env->rows)
	{
		get_next_line(0, &line);
		map[i] = ft_strdup(line + 4);
		i++;
		free(line);
	}
	map[i] = NULL; //TODO: I don't need to null terminate it
	return (map);
}

static void	fl_set_players(t_env *env, char *line)
{
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
}

int		main(void)
{
	t_env env;
	char *line;

	while (get_next_line(0, &line) > 0)
	{
		if (!ft_strncmp(line, "$$$", 3))
		{
			fl_set_players(&env, line); // TODO: Check if this function is enough
		}
		else if (!ft_strncmp(line, "Plateau", 7))
		{
			env.map = fl_get_map(&env, line);
			// ft_dprintf(STDERR_FILENO, "Rows: %d\n", env.rows);
			for (int i = 0; i < env.rows; i++)
				ft_dprintf(STDERR_FILENO, "%s\n", env.map[i]);
			// ft_dprintf(STDERR_FILENO, "Map: %s\n", line);
		}
		else if (!ft_strncmp(line, "Piece", 5))
		{
			// ft_dprintf(STDERR_FILENO, "Piece to place: %s\n", line);
			env.piece = fl_get_piece(&env, line);
			for (int i = 0; i < env.p_row; i++)
				ft_dprintf(STDERR_FILENO, "%s\n", env.piece[i]);
			filler(&env);
			// fl_answer(env); // fl_make_move
		}
		else
			free(line);
		// ft_dprintf(STDERR_FILENO ,"the line: [%s]\n", line);
		// free(line);
	}
	return (0);
}
