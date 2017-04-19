/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 10:34:22 by mfrankev          #+#    #+#             */
/*   Updated: 2017/03/15 10:35:27 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		choose_path(t_ants *ants, t_bool *visited, unsigned int *dist)
{
	int min;
	int min_index;
	int i;
	int min_links;

	i = 0;
	min = MAX_INT;
	min_links = MAX_INT;
	min_index = MAX_INT;
	while (i < ants->room_count)
	{
		if (visited[i] == FALSE && dist[i] <= (unsigned)min &&
			row_sum(ants, i) <= min_links)
		{
			min = dist[i];
			min_index = i;
			min_links = row_sum(ants, i);
		}
		i++;
	}
	return (min_index);
}

void	put_graph_values(t_dijkstra_data *data, t_ants *ants, int j, \
																int to_vertex)
{
	if (!((data->visited)[j]) && ants->links[to_vertex][j] &&
		(data->dist)[to_vertex] + 1 < (data->dist)[j])
	{
		(data->parent)[j] = to_vertex;
		(data->dist)[j] = (data->dist)[to_vertex] + 1;
	}
}

int		modified_dijkstra(t_ants *ants)
{
	int				to_vertex;
	int				j;
	t_dijkstra_data	data;
	t_room			*list_path;

	list_path = NULL;
	struct_init_free(&data, ants);
	while (!data.visited[ants->end - 1])
	{
		if ((to_vertex = choose_path(ants, data.visited, data.dist)) == MAX_INT)
			break ;
		(data.visited)[to_vertex] = TRUE;
		j = -1;
		while (++j < ants->room_count)
			put_graph_values(&data, ants, j, to_vertex);
	}
	if ((data.visited)[ants->end - 1])
	{
		print_path(ants, data.parent, ants->end - 1, &list_path);
		ft_lstpushback((&ants->paths),
						ft_lstnew(&list_path, sizeof(list_path)));
	}
	struct_init_free(&data, NULL);
	return (list_path ? 1 : 0);
}

void	delete_links(t_ants *ants)
{
	t_list	*l_crawler;
	t_room	*r_crawler;
	int		i;

	l_crawler = ants->paths;
	while (l_crawler->next)
		l_crawler = l_crawler->next;
	r_crawler = *(t_room**)(l_crawler->content);
	ants->links[(r_crawler)->num][(r_crawler)->next->num] = 0;
	ants->links[(r_crawler)->next->num][(r_crawler)->num] = 0;
	while ((r_crawler)->next)
	{
		if ((r_crawler)->num != ants->start - 1 && \
			(r_crawler)->num != ants->end - 1)
		{
			i = -1;
			while (++i < ants->room_count)
			{
				ants->links[(r_crawler)->num][i] = 0;
				ants->links[i][(r_crawler)->num] = 0;
			}
		}
		(r_crawler) = (r_crawler)->next;
	}
	return ;
}

void	print_path(t_ants *ants, int parent[], int j, t_room **list)
{
	t_room		*room;
	static int	i = 0;

	room = (t_room*)malloc(sizeof(*room));
	room->num = j;
	room->name = find_name_by_count(ants, j);
	room->len = i++;
	room->ant = -1;
	room->next = NULL;
	room->prev = NULL;
	if (parent[j] == -1)
	{
		i = 0;
		ft_room_pushback(list, room);
		return ;
	}
	print_path(ants, parent, parent[j], list);
	ft_room_pushback(list, room);
}
