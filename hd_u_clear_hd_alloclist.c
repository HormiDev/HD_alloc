/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_u_clear_hd_alloclist.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 12:17:56 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/09/21 21:46:31 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd_alloc_utils.h"

void	hd_u_clear_hd_alloclist(t_hd_alloc *alloc)
{
	t_hd_alloc_list	*current;
	t_hd_alloc_list	*next;

	if (!alloc)
		return ;
	current = alloc->alloc_list;
	while (current)
	{
		next = current->next;
		hd_u_free_hd_alloc_list_node(current);
		current = next;
	}
	alloc->alloc_list = NULL;
}
