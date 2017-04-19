/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 10:32:53 by mfrankev          #+#    #+#             */
/*   Updated: 2017/03/15 10:35:05 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*find_name_by_count(t_ants *ants, int count)
{
	t_list	*crawler;

	crawler = ants->names;
	while (count)
	{
		crawler = crawler->next;
		count--;
	}
	return (crawler->content);
}

void	ft_room_pushback(t_room **head, t_room *new_elem)
{
	t_room *crawler;

	if (*head == NULL)
	{
		*head = new_elem;
		new_elem->prev = NULL;
	}
	else
	{
		crawler = *head;
		while (crawler->next)
			crawler = crawler->next;
		crawler->next = new_elem;
		new_elem->prev = crawler;
	}
	return ;
}

void	struct_init_free(t_dijkstra_data *data, t_ants *ants)
{
	if (ants == NULL)
	{
		free(data->dist);
		free(data->visited);
		free(data->parent);
		return ;
	}
	data->parent = (int *)malloc(sizeof(int) * ants->room_count);
	ft_bzero(data->parent, sizeof(*(data->parent)) * ants->room_count);
	data->visited = (t_bool *)malloc(
			sizeof(*(data->visited)) * ants->room_count);
	ft_bzero(data->visited, sizeof(*data->visited) * ants->room_count);
	data->dist = (unsigned int *)malloc(
			sizeof(*(data->dist)) * ants->room_count);
	ft_memset(data->dist, 0xff, sizeof(*(data->dist)) * ants->room_count);
	data->parent[ants->start - 1] = -1;
	data->dist[ants->start - 1] = 0;
	return ;
}

int		row_sum(t_ants *ants, int row)
{
	int sum;
	int i;

	sum = 0;
	i = 0;
	while (i < ants->room_count)
	{
		sum += ants->links[row][i++];
	}
	return (sum);
}

void	print_shiet(int *path, t_bool *visited, unsigned int *dist, \
														t_ants *ants)
{
	int i;

	i = 0;
	ft_putstr("\npath    ");
	while (i < ants->room_count)
	{
		ft_printf(" %d ", path[i]);
		i++;
	}
	i = 0;
	ft_putstr("\ndist    ");
	while (i < ants->room_count)
	{
		ft_printf(" %u ", dist[i]);
		i++;
	}
	i = 0;
	ft_putstr("\nvisited ");
	while (i < ants->room_count)
	{
		ft_printf(" %d ", visited[i]);
		i++;
	}
	ft_putchar('\n');
}
