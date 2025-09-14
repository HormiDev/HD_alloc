/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 20:07:58 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/09/14 18:52:12 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALLOC_UTILS_H
#define FT_ALLOC_UTILS_H

#include <stdlib.h>

typedef struct s_alloc_list
{
	void *content;
	void (*free_func)(void *);
	struct s_alloc_list *next;
} t_alloc_list;

typedef struct s_alloc
{
	t_alloc_list *alloc_list;
	int malloc_calloc;
	void *(*error_func)(void *);
} t_alloc;

t_alloc *ft_get_alloc(void);
t_alloc_list *ft_new_alloc_node(void *content, void (*free_func)(void *));
void ft_add_alloc_node(t_alloc *alloc, t_alloc_list *new_node);
t_alloc_list *ft_get_last_alloc_node(t_alloc *alloc);
void ft_free_alloc_node(t_alloc_list *node);

#endif