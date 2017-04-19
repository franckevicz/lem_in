/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crawling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 10:27:36 by mfrankev          #+#    #+#             */
/*   Updated: 2017/03/15 10:39:49 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	let_them_go(t_ants *ants)
{
	int		finished;
	int		left_ants;
	t_list	*crawler;

	finished = 0;
	left_ants = ants->count_ants;
	while (finished != ants->count_ants)
	{
		crawler = ants->paths;
		while (crawler)
		{
			operate_with_roomlist(crawler->content, &left_ants, &finished, \
																ants);
			crawler = crawler->next;
		}
		if (ants->count_ants - finished)
			ft_putchar('\n');
	}
}

void	last_room(t_room **crawler, int *finished)
{
	(*crawler)->ant = (*crawler)->prev->ant;
	(*finished)++;
	if ((*crawler)->ant != -1)
		ft_printf("L%d-%s ", (*crawler)->ant, (*crawler)->name);
	*crawler = (*crawler)->prev;
}

void	operate_with_roomlist(t_room **head, int *left_ants, int *finished, \
		t_ants *ants)
{
	t_room	*crawler;
	int		len;

	crawler = *head;
	len = crawler->len;
	while (crawler->next)
		crawler = crawler->next;
	if (crawler->ant != -1)
		last_room(&crawler, finished);
	while (crawler->prev)
	{
		crawler->ant = crawler->prev->ant;
		if (crawler->ant != -1)
			ft_printf("L%d-%s ", crawler->ant, crawler->name);
		crawler = crawler->prev;
	}
	crawler = crawler->next;
	if ((*left_ants) > 0 && len - (*((t_room**)(ants->paths->content)))->len \
																<= *left_ants)
	{
		crawler->ant = ants->count_ants - (*left_ants)-- + 1;
		ft_printf("L%d-%s ", crawler->ant, crawler->name);
		return ;
	}
}
