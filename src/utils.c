/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 15:22:53 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/06/06 15:32:06 by gguiulfo         ###   ########.fr       */
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

void	get_player_pos(t_env *env)
{
	static int	flag;
	int			x;
	int			y;

	if (flag)
		return ;
	y = -1;
	while (++y < env->m_rows)
	{
		x = -1;
		while (++x < env->m_cols)
		{
			if (TOUPPER(env->map[y][x]) == env->player)
			{
				env->player_pos_x = x;
				env->player_pos_y = y;
				flag = 1;
				return ;
			}
		}
	}
}
