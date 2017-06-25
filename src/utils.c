/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 15:22:53 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/06/25 00:26:33 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

char	*read_line(void)
{
	int		c;
	int		bufsize;
	int		position;
	char	*buffer;

	position = 0;
	bufsize = FILLER_BUFF;
	buffer = (char *)malloc(sizeof(char) * bufsize);
	while (1)
	{
		if ((c = ft_getchar()) == EOF)
			free(buffer);
		if (c == EOF)
			return (NULL);
		if (c == '\n')
			buffer[position] = '\0';
		if (c == '\n')
			return (buffer);
		else
			buffer[position++] = c;
		if (position >= bufsize)
			buffer = ft_realloc(buffer, bufsize, bufsize + FILLER_BUFF);
		if (position >= bufsize)
			bufsize += FILLER_BUFF;
	}
}

int		make_map(t_env *env)
{
	char	*line;
	int		i;

	i = 0;
	get_next_line(STDIN_FILENO, &line);
	if (!line || !line[0])
		return (1);
	while (line[i] && !ISDIGIT(line[i]))
		i++;
	env->m_rows = ft_atoi(line + i);
	while (ISDIGIT(line[i]))
		i++;
	env->m_cols = ft_atoi(line + i);
	ft_strdel(&line);
	if (!(env->m_rows) || !(env->m_cols))
	{
		ft_dprintf(2, "Error: invalid map\n");
		return (1);
	}
	env->map = (char **)ft_memalloc(sizeof(char *) * (env->m_rows + 1));
	i = -1;
	while (++i < env->m_rows)
		env->map[i] = (char *)ft_memalloc(sizeof(char) * (env->m_cols + 1));
	return (0);
}

int		read_map(t_env *env)
{
	char	*line;
	int		i;

	i = -1;
	while (++i < env->m_rows)
	{
		get_next_line(STDIN_FILENO, &line);
		if (!line || !line[0])
			return (1);
		ft_memcpy(env->map[i], &line[4], env->m_cols);
		ft_strdel(&line);
	}
	return (0);
}

int		read_piece(t_env *env)
{
	char	*line;
	int		i;

	i = 0;
	get_next_line(STDIN_FILENO, &line);
	if (!line || !line[0])
		return (1);
	while (line[i] && !ISDIGIT(line[i]))
		i++;
	env->p_rows = ft_atoi(line + i);
	while (ISDIGIT(line[i]))
		i++;
	env->p_cols = ft_atoi(line + i);
	ft_strdel(&line);
	env->piece = (char **)ft_memalloc(sizeof(char *) * (env->p_rows + 1));
	i = -1;
	while (++i < env->p_rows)
	{
		get_next_line(STDIN_FILENO, &line);
		if (!line || !line[0])
			return (1);
		env->piece[i] = ft_strdup(line);
		ft_strdel(&line);
	}
	return (0);
}

void	get_rival_pos(t_env *env)
{
	int			x;
	int			y;

	y = -1;
	while (++y < env->m_rows)
	{
		x = -1;
		while (++x < env->m_cols)
		{
			if (TOUPPER(env->map[y][x]) == env->rival)
			{
				env->rival_pos_x = x;
				env->rival_pos_y = y;
				return ;
			}
		}
	}
}
