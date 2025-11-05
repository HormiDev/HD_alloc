/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_alloc_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 20:07:58 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/10/09 16:21:52 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HD_ALLOC_UTILS_H
#define HD_ALLOC_UTILS_H

#include <stdlib.h>

typedef struct s_hd_alloc_list
{
	void					*content;
	void					(*free_func)(void *);
	struct s_hd_alloc_list	*next;
} t_hd_alloc_list;

typedef struct s_hd_alloc
{
	t_hd_alloc_list *alloc_list;
	void			*(*error_func)(void);
	void			*error_ptr;
} t_hd_alloc;

t_hd_alloc		*hd_u_alloc_init(void);
t_hd_alloc		*hd_u_get_alloc(void);
t_hd_alloc_list	*hd_u_new_hd_alloc_list(void *content, void (*free_func)(void *));
t_hd_alloc_list	*hd_u_get_last_hd_alloc_list(t_hd_alloc *alloc);
t_hd_alloc_list	*hd_u_get_hd_alloc_list_prev_node(t_hd_alloc *alloc, void *content);
void			hd_u_add_last_hd_alloc_list(t_hd_alloc *alloc, t_hd_alloc_list *new_node);
void			hd_u_add_front_hd_alloc_list(t_hd_alloc *alloc, t_hd_alloc_list *new_node);
void			hd_u_free_hd_alloc_list_node(t_hd_alloc_list *node);


#endif