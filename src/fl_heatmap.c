/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_heatmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 23:37:15 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/05/25 19:11:51 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static void	fl_fill_heatmap(t_env *env, int y, int x)
{
	int	i;
	int	j;

	i = -1;
	while (++i < env->m_rows)
	{
		j = -1;
		while (++j < env->m_cols)
		{
			env->heat[i][j] = MAX(env->heat[i][j], HEATMAX - (ABS(x - j) + ABS(y - i)));
		}
	}
}

void	fl_update_heatmap(t_env *env)
{
	int i;
	int j;

	i = 0;
	while (i < env->m_rows)
	{
		j = 0;
		while (j < env->m_cols)
		{
			if (env->map[i][j] == env->rival)
				fl_fill_heatmap(env, i, j);
			j++;
		}
		i++;
	}
}

void	fl_make_heatmap(t_env *env)
{
	int	i;

	i = 0;
	env->heat = (int **)ft_memalloc(sizeof(int *) * env->m_rows);
	while (i < env->m_rows)
		env->heat[i++] = (int *)ft_memalloc(sizeof(int) * env->m_cols);
}
