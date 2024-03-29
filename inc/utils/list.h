/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:11:11 by yboudoui          #+#    #+#             */
/*   Updated: 2023/03/18 15:43:03 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "memory.h"
# include <stdbool.h>

typedef struct s_list	*t_list;

struct s_list {
	void	*content;
	t_list	next;
	t_list	prev;
};

typedef void			(*t_fp_destroy_content)(void*);
typedef void			*(*t_fp_process_content)(void *);

t_list	list_create(void *content);
bool	list_create_back(t_list *root, void *content);
bool	list_create_front(t_list *root, void *content);

bool	list_create_next(t_list *root, void *content);
bool	list_create_prev(t_list *root, void *content);

void	list_destroy(t_list lst, t_fp_destroy_content del);
void	list_clear(void *root, t_fp_destroy_content del);

void	list_new_insert_after(t_list *root, void *data);
void	list_new_insert_before(t_list *root, void *data);

bool	list_add_back(t_list *root, t_list new);
bool	list_add_front(t_list *root, t_list new);
bool	list_add_next(t_list *root, t_list new);
bool	list_add_prev(t_list *root, t_list new);

void	*list_to_array(t_list lst, void *(*f)(void *));

t_list	ft_lstmap(t_list lst, void *(*f)(void *), void (*del)(void *));
void	*list_subset(void *list, void *(*f)(void *));
void	list_iter(void *list, void (*f)(void *, void *), void *data);

void	list_remove_one(void *lst, t_fp_destroy_content del);

t_list	list_last(t_list lst);
t_list	list_first(t_list lst);
size_t	list_size(t_list lst);

t_list	str_array_to_list(char *str_array[]);

#endif
