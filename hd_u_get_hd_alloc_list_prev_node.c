/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_u_get_hd_alloc_list_prev_node.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 21:10:47 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/09/21 12:13:29 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd_alloc_utils.h"

t_hd_alloc_list	*hd_u_get_hd_alloc_list_prev_node(t_hd_alloc *alloc, void *content)
{
	t_hd_alloc_list	*current;
	t_hd_alloc_list	*prev;

	if (!alloc || !content)
		return (NULL);
	current = alloc->alloc_list;
	prev = NULL;
	while (current)
	{
		if (current->content == content)
			return (prev);
		prev = current;
		current = current->next;
	}
	return (NULL);
}
