/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 15:12:24 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/06/05 15:20:21 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	make_map(t_env *env)
{
	char	*line;
	int		i;

	i = 0;
	line = read_line();
	while (!ISDIGIT(line[i]))
		i++;
	env->m_rows = ft_atoi(line + i);
	while (ISDIGIT(line[i]))
		i++;
	env->m_cols = ft_atoi(line + i);
	ft_strdel(&line);
	env->map = (char **)ft_memalloc(sizeof(char *) * (env->m_rows + 1));
	i = -1;
	while (++i < env->m_rows)
		env->map[i] = (char *)ft_memalloc(sizeof(char) * (env->m_cols + 1));
}

void	read_map(t_env *env)
{
	char	*line;
	int		i;

	i = -1;
	while (++i < env->m_rows)
	{
		line = read_line();
		ft_memcpy(env->map[i], &line[4], env->m_cols);
		ft_strdel(&line);
	}
}
