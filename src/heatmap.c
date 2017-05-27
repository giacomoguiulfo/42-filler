/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 23:37:15 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/05/27 04:56:57 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static void	fill_heatmap(t_env *env, int y, int x)
{
	int	i;
	int	j;

	i = -1;
	while (++i < env->m_rows)
	{
		j = -1;
		while (++j < env->m_cols)
		{
			env->heatmap[i][j] = MAX(env->heatmap[i][j], HEATMAX - (ABS(x - j) + ABS(y - i)));
		}
	}
}

void	update_heatmap(t_env *env)
{
	int i;
	int j;

	i = 0;
	while (i < env->m_rows)
	{
		j = 0;
		while (j < env->m_cols)
		{
			if (TOUPPER(env->map[i][j]) == env->rival)
				fill_heatmap(env, i, j);
			j++;
		}
		i++;
	}
}

void	make_heatmap(t_env *env)
{
	int	i;

	i = 0;
	env->heatmap = (int **)ft_memalloc(sizeof(int *) * env->m_rows);
	while (i < env->m_rows)
		env->heatmap[i++] = (int *)ft_memalloc(sizeof(int) * env->m_cols);
}
