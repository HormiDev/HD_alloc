/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_alloc_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 12:17:56 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/09/29 13:45:30 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd_alloc_utils.h"
#include "hd_alloc.h"

void	hd_alloc_clear()
{
	t_hd_alloc		*alloc;
	t_hd_alloc_list	*current;
	t_hd_alloc_list	*next;

	current = alloc->alloc_list;
	while (current)
	{
		next = current->next;
		hd_u_free_hd_alloc_list_node(current);
		current = next;
	}
	alloc->alloc_list = 0;
}
