/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 23:37:15 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/05/28 06:27:47 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	fill_heatmap(t_env *env, int y, int x, int heatmax)
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
			if (i == env->m_rows / 2 || j == env->m_cols / 2)
				env->heatmap[i][j] = HEATMAX + 10;
			tmp = heatmax - (ABS(x - j) + ABS(y - i));
			env->heatmap[i][j] = MAX(env->heatmap[i][j], tmp);
		}
	}
}

void	update_heatmap(t_env *env)
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
				fill_heatmap(env, i, j, HEATMAX);
		}
	}
}

void	make_heatmap(t_env *env)
{
	int	i;

	i = -1;
	env->heatmap = (int **)ft_memalloc(sizeof(int *) * env->m_rows);
	while (++i < env->m_rows)
		env->heatmap[i] = (int *)ft_memalloc(sizeof(int) * env->m_cols);
}
