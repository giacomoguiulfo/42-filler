/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 01:31:48 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/05/27 03:23:13 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static void	find_new_dim(t_env *env, int *last_x, int *last_y, int org_x)
{
	char	*ptr;
	int		x;

	x = -1;
	while (++x < env->p_rows)
	{
		if ((ptr = ft_strrchr(env->piece[x], '*')) == NULL)
			continue ;
		(*last_y)++;
		*last_x = MAX(*last_x, ptr - env->piece[x] - org_x);
		ft_dprintf(2, "last_x: %d\n", *last_x);
	}
}

void	process_piece(t_env *env)
{
	char **newpiece;
	int x;
	int y;
	int	org_y;
	int	org_x;
	int last_x;
	int last_y;

	org_x = env->p_cols;
	org_y = -1;
	y = -1;
	while (++y < env->p_rows)
	{
		x = -1;
		while (++x < env->p_cols)
		{
			if (env->piece[y][x] == '*')
			{
				if (org_y == -1)
					org_y = y;
				org_x = MIN(org_x, x);
				break ;
			}
		}
	}
	last_y = 0;
	last_x = 0;
	find_new_dim(env, &last_x, &last_y, org_x);
	ft_dprintf(2, "Origin Y: %d, Origin X: %d\n", org_y, org_x);
	ft_dprintf(2, "New Rows: %d, New Cols: %d\n", last_y, last_x);
	newpiece = (char **)ft_memalloc(sizeof(char *) * (last_y + 1));
	y = -1;
	while (++y < last_y)
		newpiece[y] = ft_strndup(env->piece[y + org_y] + org_x, last_x + 1);
	for (int i = 0; newpiece[i]; i++)
		ft_dprintf(2, "%{red}%s%{eoc}\n", newpiece[i]);
	env->p_rows = last_y;
	env->p_cols = last_x + 1;
	ft_free_map(env->piece);
	env->piece = newpiece;
}
