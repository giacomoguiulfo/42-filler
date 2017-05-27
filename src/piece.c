/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 01:31:48 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/05/27 04:46:27 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static int	get_left_shift(t_env *env)
{
	int	left_shift;
	int x;
	int y;

	x = -1;
	left_shift = 0;
	while (++x < env->pbox_cols)
	{
		y = -1;
		while (++y < env->pbox_rows)
		{
			if (env->piecebox[y][x] == '*')
				return (left_shift);
		}
		left_shift++;
	}
	return (left_shift);
}

static int	get_top_shift(t_env *env)
{
	int	top_shift;
	int x;
	int y;

	y = -1;
	top_shift = 0;
	while (++y < env->pbox_rows)
	{
		x = -1;
		while (++x < env->pbox_cols)
		{
			if (env->piecebox[y][x] == '*')
				return (top_shift);
		}
		top_shift++;
	}
	return (top_shift);
}

static int	get_bottom_end(t_env *env)
{
	int	bottom_end;
	int x;
	int y;

	bottom_end = 0;
	y = env->pbox_rows;
	while (--y >= 0)
	{
		x = env->pbox_cols;
		while (--x >= 0)
		{
			if (env->piecebox[y][x] == '*')
				return (bottom_end);
		}
		++bottom_end;
	}
	return (bottom_end);
}

static int	get_right_end(t_env *env)
{
	int right_end;
	int x;
	int y;

	right_end = 0;
	x = env->pbox_cols;
	while (--x >= 0)
	{
		y = env->pbox_rows;
		while (--y >= 0)
		{
			if (env->piecebox[y][x] == '*')
				return (right_end);
		}
		++right_end;
	}
	return (right_end);
}

void		trim_piece(t_env *env)
{
	int y;

	env->piece = (char **)ft_memalloc(sizeof(char *) * (env->p_rows + 1));
	y = -1;
	while (++y < env->p_rows)
	{
		env->piece[y] =
		ft_strndup(env->piecebox[y + env->top_shift] + env->left_shift, env->p_cols);
	}
}

void	process_piece(t_env *env)
{
	ft_dprintf(2, "segfault here?\n");
	env->left_shift = get_left_shift(env);
	env->top_shift = get_top_shift(env);
	env->p_cols = env->pbox_cols - env->left_shift - get_right_end(env);
	env->p_rows = env->pbox_rows - env->top_shift - get_bottom_end(env);
	ft_dprintf(2, "env->p_cols: %d, env->p_rows: %d\n", env->p_cols, env->p_rows);
	trim_piece(env);
	ft_dprintf(2, "segfault here?\n");
}
