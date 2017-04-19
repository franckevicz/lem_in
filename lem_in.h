/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 10:34:22 by mfrankev          #+#    #+#             */
/*   Updated: 2017/03/15 10:35:11 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_ants
{
	int		count_ants;
	int		**links;
	int		room_count;
	int		start;
	int		end;
	t_list	*names;
	int		fd;
	t_list	*paths;
}				t_ants;

typedef	struct	s_room
{
	int					num;
	char				*name;
	int					len;
	int					ant;
	struct s_room		*next;
	struct s_room		*prev;
}				t_room;

typedef	struct	s_dijkstra_data
{
	t_bool			*visited;
	int				*parent;
	unsigned int	*dist;
}				t_dijkstra_data;

int				num_len(int number);
int				check_is_name(char *line);
int				operate_rooms(char *line, t_ants *ants);
int				create_link(char *line, t_ants *ants);
int				read_from_std(t_ants *ants, char **print);
int				**create_int_array(int n);
int				find_count_by_name(t_ants *ants, char *name, int word_len);
int				modified_dijkstra(t_ants *ants);
int				choose_path(t_ants *ants, t_bool *visited, unsigned int *dist);
int				modified_dijkstra(t_ants *ants);
int				row_sum(t_ants *ants, int row);
void			print_path(t_ants *ants, int parent[], int j, t_room **list);
void			operate_with_roomlist(t_room **head, int *left_ants,\
													int *finished,\
													t_ants *ants);
void			let_them_go(t_ants *ants);
void			ft_room_pushback(t_room **head, t_room *new_elem);
void			free_struct(t_ants *ants);
void			struct_init_free(t_dijkstra_data *data, t_ants *ants);
void			delete_links(t_ants *ants);
char			*find_name_by_count(t_ants *ants, int count);

void			ft_lstpushback(t_list **alst, t_list *new);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			print_shiet(int *path, t_bool *visited, unsigned int *dist, \
																t_ants *ants);
void			free_bzero(void *ptr, size_t size);
void			last_room(t_room **crawler, int *finished);

int				ft_listlen(t_list *head);
void			ft_print_list(t_list *head);
void			ft_print_int_matrix(int **array, int columns, int rows);
#endif
