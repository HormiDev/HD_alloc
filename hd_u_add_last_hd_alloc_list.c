/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_u_add_last_hd_alloc_list.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 13:27:31 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/04/10 04:13:16 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd_alloc_utils.h"

void	hd_u_add_last_hd_alloc_list(t_hd_alloc *alloc,
			t_hd_alloc_list *new_node)
{
	t_hd_alloc_list	*current;

	if (!alloc || !new_node)
		return ;
	current = hd_u_get_last_hd_alloc_list(alloc);
	if (!current)
		alloc->alloc_list = new_node;
	else
		current->next = new_node;
}
