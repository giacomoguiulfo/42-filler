/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 02:19:00 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/06/07 09:31:31 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static int	get_heatscore(t_env *env, int x, int y)
{
	int i;
	int j;
	int score;

	score = 0;
	i = -1;
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

static void	consider_position(t_env *env, int x, int y)
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

static bool	is_safe(t_env *env, int x, int y)
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
				if (i + y >= env->m_rows || j + x >= env->m_cols
					|| i + y < 0 || j + x < 0 || flag > 1)
					return (false);
				if (TOUPPER(env->map[i + y][j + x]) == env->player)
					flag++;
				else if (TOUPPER(env->map[i + y][x + j]) == env->rival)
					return (false);
			}
		}
	}
	return ((flag == 1) ? true : false);
}

void		filler(t_env *env)
{
	int i;
	int j;

	i = -env->p_rows - 1;
	while (++i < env->m_rows)
	{
		j = -env->p_cols - 1;
		while (++j < env->m_cols)
		{
			if (is_safe(env, j, i))
				consider_position(env, j, i);
		}
	}
	ft_printf("%d %d\n", env->out_y, env->out_x);
	env->heatscore = 0;
	env->out_y = 0;
	env->out_x = 0;
}
