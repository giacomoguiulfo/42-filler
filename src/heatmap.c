/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 23:37:15 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/06/06 15:30:17 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void		fill_heatmap(t_env *env, int y, int x, int heatmax)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < env->m_rows)
	{
		j = -1;
		while (++j < env->m_cols)
		{
			if (!env->special && (j == env->m_cols / 2))
				env->heatmap[i][j] = HEATMAX;
			tmp = heatmax - (ABS(x - j) + ABS(y - i));
			env->heatmap[i][j] = MAX(env->heatmap[i][j], tmp);
		}
	}
}

static void	special_heatmap(t_env *env, int i, int j)
{
	if (j > env->m_cols / 2 && j == i + env->m_cols / 2)
		fill_heatmap(env, i, j, HEATMAX + 2);
	else if (i == env->m_rows / 2 ||
			(j == env->m_cols / 2 && i < env->m_rows / 2))
		fill_heatmap(env, i, j, HEATMAX);
	else if (i < env->m_rows / 5)
		fill_heatmap(env, i, j, HEATMAX - 1);
	else if (j > env->m_cols - 3 && i < env->m_cols / 2)
		fill_heatmap(env, i, j, HEATMAX);
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
			if (env->special)
				special_heatmap(env, i, j);
			else if (TOUPPER(env->map[i][j]) == env->rival)
				fill_heatmap(env, i, j, HEATMAX);
		}
	}
}

void		make_heatmap(t_env *env)
{
	int	i;

	i = -1;
	env->heatmap = (int **)ft_memalloc(sizeof(int *) * env->m_rows);
	while (++i < env->m_rows)
		env->heatmap[i] = (int *)ft_memalloc(sizeof(int) * env->m_cols);
}
