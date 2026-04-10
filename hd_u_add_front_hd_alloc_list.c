/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_u_add_front_hd_alloc_list.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 22:06:50 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/04/10 04:04:31 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd_alloc_utils.h"

void	hd_u_add_front_hd_alloc_list(t_hd_alloc *alloc,
			t_hd_alloc_list *new_node)
{
	if (!alloc || !new_node)
		return ;
	new_node->next = alloc->alloc_list;
	alloc->alloc_list = new_node;
}
