/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 02:19:00 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/05/27 00:37:29 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		get_heatscore(t_env *env, int x, int y)
{
	int i;
	int j;
	int score;

	i = -1;
	score = 0;
	while (++i < env->p_rows)
	{
		j = -1;
		while (++j < env->p_cols)
		{
			if (env->piece[i][j] == '*')
				score += env->heatmap[y + i][x + j];
		}
	}
	return (score);
}

void	check_priority(t_env *env, int x, int y)
{
	int		new_score;

	new_score = get_heatscore(env, x, y);
	if (new_score >= env->heatscore)
	{
		env->heatscore = new_score;
		env->out_x = x;
		env->out_y = y;
	}
}

bool	is_safe(t_env *env, int x, int y)
{
	int i;
	int j;
	int flag;

	flag = 0;
	i = -1;
	while (++i < env->p_rows)
	{
		j = -1;
		while (++j < env->p_cols)
		{
			if (env->piece[i][j] == '*')
			{
				if (TOUPPER(env->map[i + y][j + x]) == env->player)
				{
					flag++;
					if (flag > 1)
						return (false);
				}
				else if (TOUPPER(env->map[i + y][x + j]) == env->rival)
					return (false);
			}

		}
	}
	return ((flag == 1) ? true : false);
}

void	filler(t_env *env)
{
	int i;
	int j;

	i = -1;

	while (++i + (env->p_rows - 1) < env->m_rows)
	{
		j = -1;
		while (++j + (env->p_cols - 1) < env->m_cols)
		{
			if (is_safe(env, j, i))
			{
				// ft_dprintf(2, "%{bgreen}Is safe in y: %d and x: %d%{eoc}\n", i, j);
				check_priority(env, j, i);
			}
		}
	}
	// ft_dprintf(2, "env->out_y: %d, env->out_x: %d\n", env->out_y, env->out_x);
	// ft_dprintf(STDOUT_FILENO, "%d %d\n", env->out_y, env->out_x);
	// ft_dprintf(STDOUT_FILENO, "%d %d\n", env->out_y, env->out_x);
	ft_dprintf(STDOUT_FILENO, "%d %d\n", env->out_y, env->out_x);
	// ft_printf("%d %d\n", env->out_y, env->out_x);
	env->heatscore = 0;
	// putpiece(env);
}
