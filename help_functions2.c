/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 10:29:14 by mfrankev          #+#    #+#             */
/*   Updated: 2017/03/15 10:34:59 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		create_link(char *line, t_ants *ants)
{
	int link_x;
	int link_y;

	if (ft_strchr(ft_strchr(line, '-') + 1, '-'))
		return (0);
	if (ants->links == NULL)
		ants->links = create_int_array(ft_listlen(ants->names));
	link_x = find_count_by_name(ants, line, ft_strchr(line, '-') - line);
	link_y = find_count_by_name(ants, ft_strchr(line, '-') + 1,
								ft_strlen(ft_strchr(line, '-') + 1));
	if (link_x == 0 || link_y == 0)
		return (0);
	ants->links[link_y - 1][link_x - 1] = 1;
	ants->links[link_x - 1][link_y - 1] = 1;
	return (1);
}

void	free_bzero(void *ptr, size_t size)
{
	ft_bzero(ptr, size);
	free(ptr);
	return ;
}

void	free_struct(t_ants *ants)
{
	t_room	*r_crawler;
	t_list	*tmp_lst;
	int		i;

	i = 0;
	while (i < ants->room_count)
		free(ants->links[i++]);
	free(ants->links);
	ft_lstdel(&(ants->names), &free_bzero);
	tmp_lst = ants->paths;
	while (tmp_lst)
	{
		r_crawler = *((t_room**)(tmp_lst)->content);
		while (r_crawler)
		{
			free(r_crawler);
			r_crawler = r_crawler->next;
		}
		tmp_lst = tmp_lst->next;
	}
	ft_lstdel(&(ants->paths), &free_bzero);
	return ;
}
