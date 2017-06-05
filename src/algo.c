/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 02:19:00 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/06/04 00:51:51 by gguiulfo         ###   ########.fr       */
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
	while (++i < env->pbox_rows)
	{
		j = -1;
		while (++j < env->pbox_cols)
		{
			if (env->piecebox[i][j] == '*')
			{
				// if (env->heatmap[y + i][x + j] == HEATMAX - 3)
				// 	score += HEATMAX + 1;
				// else
					score += env->heatmap[y + i][x + j];
			}

		}
	}
	return (score);
}

void	consider_position(t_env *env, int x, int y)
{
	// static	int tactic;
	int		new_score;

	new_score = get_heatscore(env, x, y);
	// if (EVEN(tactic))
	// {
	// 	if (new_score > env->heatscore)
	// 	{
	// 		env->heatscore = new_score;
	// 		env->out_x = x - env->left_shift;
	// 		env->out_y = y - env->top_shift;
	// 		++tactic;
	// 	}
	// }
	// else
	// {
		if (new_score >= env->heatscore)
		{
			env->heatscore = new_score;
			env->out_x = x;
			env->out_y = y;
			// ++tactic;
		}
	// }
}

bool	is_safe(t_env *env, int x, int y)
{
	int i;
	int j;
	int flag;


	flag = 0;
	i = -1;
	while (++i < env->pbox_rows)
	{
		j = -1;
		while (++j < env->pbox_cols)
		{
			if (env->piecebox[i][j] == '*')
			{
				if (i + y >= env->m_rows || j + x >= env->m_cols)
					return (false);
				if (i + y < 0 || j + x < 0)
					return (false);
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

	i = -env->pbox_rows - 1;
	while (++i < env->m_rows)
	{
		j = -env->pbox_cols - 1;
		while (++j < env->m_cols)
		{
			// ft_dprintf(2, "%{bcyan}ROW[%d]:COL[%d]%{eoc}", i, j);
			if (is_safe(env, j, i))
				consider_position(env, j, i);
		}
	}
	// ft_dprintf(2, "%{bgreen}[DEBUG]: %d %d%{eoc}\n", env->out_y, env->out_x);
	// if (env->out_y < 0 || env->out_x < 0)
		// ft_dprintf(2, "I can give negative coordinates!!!!!!!!!!!!!!!!!!!!!!!\n");
	ft_printf("%d %d\n", env->out_y, env->out_x);
	env->heatscore = 0;
	env->out_y = 0;
	env->out_x = 0;
}
