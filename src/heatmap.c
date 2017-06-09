/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 23:37:15 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/06/08 20:06:00 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static void	heatmap_recursor(t_env *env, short level)
{
	int x;
	int y;
	int tmp;

	if (level <= 1)
		return ;
	y = -1;
	while (++y < env->m_rows)
	{
		x = -1;
		while (++x < env->m_cols)
		{
			if (env->heatmap[y][x] > 0)
			{
				tmp = env->heatmap[y][x];
				if (x - 1 >= 0 && env->heatmap[y][x - 1] < tmp)
					env->heatmap[y][x - 1] = tmp / DIVISH;
				if (x + 1 < env->m_cols && env->heatmap[y][x + 1] < tmp)
					env->heatmap[y][x + 1] = tmp / DIVISH;
				if (y - 1 >= 0 && env->heatmap[y - 1][x] < tmp)
					env->heatmap[y - 1][x] = tmp / DIVISH;
				if (y + 1 < env->m_rows && env->heatmap[y + 1][x] < tmp)
					env->heatmap[y + 1][x] = tmp / DIVISH;
			}
		}
	}
	heatmap_recursor(env, level / DIVISH);
}

void		update_heatmap(t_env *env)
{
	int i;
	int j;

	i = -1;
	while (++i < env->m_rows)
	{
		j = -1;
		while (++j < env->m_cols)
		{
			if (TOUPPER(env->map[i][j]) == env->rival)
				env->heatmap[i][j] = HEATMAX;
		}
	}
	heatmap_recursor(env, HEATMAX);
}

void		make_heatmap(t_env *env)
{
	int	i;

	i = -1;
	env->heatmap = (int **)ft_memalloc(sizeof(int *) * env->m_rows);
	while (++i < env->m_rows)
		env->heatmap[i] = (int *)ft_memalloc(sizeof(int) * env->m_cols);
}
