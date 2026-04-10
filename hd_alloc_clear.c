/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_alloc_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 12:17:56 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/04/10 04:14:05 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd_alloc_utils.h"
#include "hd_alloc.h"

/**
 * @brief Libera toda la memoria asignada con hd_alloc y limpia la lista de
 * asignaciones.
 * 
 * Esta función debe ser llamada cuando ya no se necesita la memoria asignada
 * con hd_alloc.
 */
void	hd_alloc_clear(void)
{
	t_hd_alloc		*alloc;
	t_hd_alloc_list	*current;
	t_hd_alloc_list	*next;

	alloc = hd_u_get_alloc();
	current = alloc->alloc_list;
	while (current)
	{
		next = current->next;
		hd_u_free_hd_alloc_list_node(current);
		current = next;
	}
	alloc->alloc_list = 0;
}
