/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 15:48:03 by mfrankev          #+#    #+#             */
/*   Updated: 2017/03/15 10:35:30 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_listlen(t_list *head)
{
	t_list	*crawler;
	int		n;

	if (head == NULL)
		return (0);
	crawler = head;
	n = 0;
	while (crawler)
	{
		n++;
		crawler = crawler->next;
	}
	return (n);
}

void	ft_print_int_matrix(int **array, int columns, int rows)
{
	int i;
	int j;

	j = 0;
	while (j < rows)
	{
		i = 0;
		while (i < columns)
		{
			ft_printf("%6d ", array[j][i]);
			i++;
		}
		j++;
		ft_putchar('\n');
	}
	return ;
}

void	ft_print_list(t_list *head)
{
	while (head)
	{
		ft_putstr(head->content);
		ft_putchar('\n');
		head = head->next;
	}
	return ;
}

int		**create_int_array(int n)
{
	int **array;
	int i;

	i = 0;
	array = (int**)malloc(sizeof(int*) * (n + 1));
	while (i < n)
	{
		array[i] = (int*)malloc(sizeof(int) * (n + 1));
		ft_bzero(array[i], sizeof(int) * n);
		i++;
	}
	return (array);
}

int		num_len(int number)
{
	int n;

	n = 0;
	if (number <= 0)
		n++;
	while (ABS(number) >= 1)
	{
		number /= 10;
		n++;
	}
	return (n);
}
