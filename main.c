/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 10:32:53 by mfrankev          #+#    #+#             */
/*   Updated: 2017/03/15 10:35:17 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_ants	ants;
	char	*print;

	print = NULL;
	ft_bzero(&ants, sizeof(ants));
	if (!read_from_std(&ants, &print) || !ants.count_ants || !ants.names || \
		!ants.start || !ants.end || ants.start == ants.end || !ants.links)
	{
		ft_putstr("Error\nIncorrect input\n");
		return (0);
	}
	while (modified_dijkstra(&ants))
		delete_links(&ants);
	if (!ants.paths)
	{
		ft_putstr("Error\nThere is no possible ways from start to the end.\n");
		return (0);
	}
	ft_printf("%s\n\n", print);
	free(print);
	let_them_go(&ants);
	free_struct(&ants);
	return (0);
}
