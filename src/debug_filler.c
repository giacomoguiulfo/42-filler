/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_filler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 15:04:26 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/06/05 15:26:22 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void		debug_print_map(t_env *env)
{
	int i;

	i = -1;
	ft_dprintf(2, "%{bgreen}Map:%{eoc}\n");
	while (++i < env->m_rows)
		ft_dprintf(2, "%{bgreen}%s%{eoc}\n", env->map[i]);
}

void		debug_print_piece(t_env *env)
{
	int i;

	i = -1;
	ft_dprintf(2, "%{bgreen}Piece:%{eoc}\n");
	while (++i < env->p_rows)
		ft_dprintf(2, "%{bgreen}%s%{eoc}\n", env->piece[i]);
}

void		debug_print_heatmap(t_env *env)
{
	int i;
	int j;

	i = -1;
	ft_dprintf(2, "%{bgreen}Heat Map:%{eoc}\n");
	ft_dprintf(2, "  %4c", ' ');
	while (++i < env->m_cols)
		ft_dprintf(2, "%{cyan}%6d%{eoc}", i);
	ft_putchar_fd('\n', 2);
	i = -1
	while (++i < env->m_rows)
	{
		ft_dprintf(2, "%{cyan}%4d: %{eoc}", i);
		j = -1;
		while (++j < env->m_cols)
			ft_dprintf(2, "%{bgreen}%6d%{eoc}", env->heatmap[i][j]);
		ft_dprintf(2, "\n");
	}
}
