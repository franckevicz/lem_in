/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 10:28:48 by mfrankev          #+#    #+#             */
/*   Updated: 2017/03/15 10:35:23 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_is_name(char *line)
{
	int i;

	i = 0;
	if (line[i] && line[i] == ' ')
		i++;
	else
		return (0);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	if (line[i] && line[i] == ' ' && i >= 2)
		i++;
	else
		return (0);
	if (!ft_isdigit(line[i]))
		return (0);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	if (line[i] == 0)
		return (1);
	else
		return (0);
}

int		write_room(char *line, size_t *i, t_ants *ants)
{
	char *tmp;

	while (line[*i] && line[*i] == ' ')
		(*i)++;
	while (line[*i] && line[*i] != ' ')
		(*i)++;
	if (*i && check_is_name(&line[*i]) && !ants->links)
	{
		tmp = ft_strndup(line, *i);
		if (find_count_by_name(ants, tmp, *i))
		{
			free(tmp);
			return (0);
		}
		ft_lstpushback(&(ants->names), ft_lstnew(tmp, *i + 1));
		free(tmp);
	}
	else
		return (0);
	return (1);
}

int		operate_rooms(char *line, t_ants *ants)
{
	size_t	i;

	i = 0;
	if (ft_strlen(line) == 7 && ft_strnstr(line, "##start", 7))
		ants->start = ft_listlen(ants->names) + 1;
	if (ft_strlen(line) == 5 && ft_strnstr(line, "##end", 5))
		ants->end = ft_listlen(ants->names) + 1;
	if (!ft_strcmp("##start", line) || !ft_strcmp("##end", line))
		return (1);
	if (ft_strchr(line, '-'))
	{
		if (!create_link(line, ants))
			return (0);
	}
	else
	{
		if (*line == '#')
			return (1);
		if (!write_room(line, &i, ants))
			return (0);
	}
	return (1);
}

int		find_count_by_name(t_ants *ants, char *name, int word_len)
{
	int		i;
	t_list	*crawler;

	if (ants->names == NULL)
		return (0);
	i = 1;
	crawler = ants->names;
	if (crawler->content_size == (unsigned)word_len + 1 &&
		!ft_memcmp(crawler->content, name, word_len))
		return (i);
	while (crawler)
	{
		if (crawler->content_size == (unsigned)word_len + 1 &&
			!ft_memcmp(crawler->content, name, word_len))
			return (i);
		crawler = crawler->next;
		i++;
	}
	return (0);
}

int		read_from_std(t_ants *ants, char **print)
{
	char *line;
	char *out;

	get_next_line(ants->fd, &line);
	if (!line || ft_strlen(line) != (unsigned)num_len(ft_atoi(line)))
		return (0);
	ants->count_ants = ft_atoi(line);
	out = ft_strdup(line);
	free(line);
	while (get_next_line(ants->fd, &line))
	{
		if (ft_strlen(line) == 0 || *line == 'L' || !operate_rooms(line, ants))
		{
			free(line);
			return (0);
		}
		if (ants->links && !ants->room_count)
			ants->room_count = ft_listlen(ants->names);
		out = ft_freejoin(out, "\n");
		out = ft_freejoin(out, line);
		free(line);
	}
	free(line);
	*print = out;
	return (1);
}
