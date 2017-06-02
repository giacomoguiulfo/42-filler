/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_filler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 05:18:05 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/06/02 00:30:08 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static void	fill_bottom_right(t_env *env)
{
	int	x;
	int y;

	y = env->m_rows / 2;
	while (++y < env->m_rows)
	{
		x = env->m_cols / 2;
		while (++x < env->m_cols)
		{
			fill_heatmap(env, y, x, HEATMAX - 1);
		}
	}
}

static void	fill_bottom_left(t_env *env)
{
	int	x;
	int y;

	y = env->m_rows / 2;
	while (++y < env->m_rows)
	{
		x = -1;
		while (++x < env->m_cols / 2)
		{
			fill_heatmap(env, y, x, HEATMAX - 1);
		}
	}
}

static void	fill_top_right(t_env *env)
{
	int	x;
	int y;

	y = -1;
	while (++y < env->m_rows / 2)
	{
		x = env->m_cols / 2;
		while (++x < env->m_cols)
		{
			fill_heatmap(env, y, x, HEATMAX - 1);
		}
	}
}

static void	fill_top_left(t_env *env)
{
	int	x;
	int y;

	y = -1;
	while (++y < env->m_rows / 2)
	{
		x = -1;
		while (++x < env->m_cols / 2)
		{
			fill_heatmap(env, y, x, HEATMAX - 1);
		}
	}
}

void	fill_borders(t_env *env)
{
	int	x;
	int y;

	y = -1;
	while (++y < env->m_rows)
	{
		x = -1;
		while (++x < env->m_cols)
		{
			if (!x || !y || x + 1 == env->m_cols || y + 1 == env->m_rows)
				fill_heatmap(env, y, x, HEATMAX - 3);
		}
	}
}

void	get_player_pos(t_env *env)
{
	static int	flag;
	int			x;
	int			y;

	if (flag)
		return ;
	y = -1;
	while (++y < env->m_rows)
	{
		x = -1;
		while (++x < env->m_cols)
		{
			if (TOUPPER(env->map[y][x]) == env->player)
			{
				env->player_pos_x = x;
				env->player_pos_y = y;
				flag = 1;
				return ;
			}
		}
	}
}

void	small_filler(t_env *env)
{
	static int flag;

	if (flag)
		return ;
	get_player_pos(env);
	// fill_borders(env);
	if (env->player_pos_y < env->m_rows / 2)
	{
		if (env->player_pos_x < env->m_cols / 2)
			fill_bottom_right(env);
		else
			fill_bottom_left(env);
	}
	else
	{
		if (env->player_pos_x < env->m_cols / 2)
			fill_top_right(env);
		else
			fill_top_left(env);
	}
	flag = 1;
}
