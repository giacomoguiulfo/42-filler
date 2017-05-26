/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 02:19:00 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/05/25 20:12:24 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>


void	fl_is_safe(t_env *env, int x, int y)
{
	
}

void	filler(t_env *env)
{
	int i;
	int j;

	i = -1;
	while (++i < env->rows)
	{
		j = -1;
		while (++j < env->cols)
		{
			if (fl_is_safe(env, j, i))
			{
				// fl_check_priority(env);
			}
		}
	}
	// fl_putpiece(env);
}
