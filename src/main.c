/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 15:36:58 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/06/02 00:35:17 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>


#define FILLER_BUFF 4096
#include <stdio.h> // Delete or not
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

void		debug_print_map(t_env *env)
{
	ft_dprintf(2, "%{bgreen}Map:%{eoc}\n");
	for (int i = 0; i < env->m_rows; i++)
		ft_dprintf(2, "%{bgreen}%s%{eoc}\n", env->map[i]);
}

void		debug_print_heatmap(t_env *env)
{
	ft_dprintf(2, "%{bgreen}Heat Map:%{eoc}\n");
	ft_dprintf(2, "  %4c", ' ');
	for (int i = 0; i < env->m_cols; i++)
		ft_dprintf(2, "%{cyan}%6d%{eoc}", i);
	ft_putchar_fd('\n', 2);
	for (int i = 0; i < env->m_rows; i++)
	{
		ft_dprintf(2, "%{cyan}%4d: %{eoc}", i);
		for (int j = 0; j < env->m_cols; j++)
			ft_dprintf(2, "%{bgreen}%6d%{eoc}", env->heatmap[i][j]);
		ft_dprintf(2, "\n");
	}
}

void		debug_print_piece(t_env *env)
{
	ft_dprintf(2, "%{bgreen}Piece:%{eoc}\n");
	for (int i = 0; i < env->pbox_rows; i++)
		ft_dprintf(2, "%{bgreen}%s%{eoc}\n", env->piecebox[i]);
}

static void	set_players(t_env *env)
{
	char *line;

	line = read_line();
	if (line[10] == '1')
	{
		env->player = 'O';
		env->rival = 'X';
	}
	else
	{
		env->player = 'X';
		env->rival = 'O';
	}
	ft_strdel(&line);
}

static void	read_piece(t_env *env)
{
	char	*line;
	int		i;

	i = 0;
	line = read_line();
	while (!ISDIGIT(line[i]))
		i++;
	env->pbox_rows = ft_atoi(line + i);
	while (ISDIGIT(line[i]))
		i++;
	env->pbox_cols = ft_atoi(line + i);
	ft_strdel(&line);
	env->piecebox = (char **)ft_memalloc(sizeof(char *) * (env->pbox_rows + 1));
	i = -1;
	while (++i < env->pbox_rows)
	{
		line = read_line();
		env->piecebox[i] = ft_strdup(line);
		ft_strdel(&line);
	}
}

static void	make_map(t_env *env)
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

static void	read_map(t_env *env)
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

static inline void skip_plateau(char **line)
{
	if (!ft_strncmp(*line , "Plateau", 7))
	{
		ft_strdel(line);
		*line = read_line();
	}
}

int		main(void)
{
	t_env	env;
	char	*line;

	ft_bzero(&env, sizeof(t_env));
	set_players(&env);
	make_map(&env);
	make_heatmap(&env);
	while ((line = read_line()) != NULL)
	{
		skip_plateau(&line);
		ft_strdel(&line);
		read_map(&env);
		read_piece(&env);
		// debug_print_piece(&env);
		process_piece(&env);
		// debug_print_piece(&env);
		// debug_print_map(&env);
		update_heatmap(&env);
		// if (env.m_rows < 20)
			small_filler(&env);
		// debug_print_heatmap(&env);
		filler(&env);
		// usleep(100000);
		// sleep(1);
		// ft_free_map(env.piece);
		// ft_free_map(env.piecebox);
		// sleep(1);
	}
	ft_free_map(env.map);
	ft_free_rows((void **)env.heatmap, env.m_rows);
	return (0);
}
