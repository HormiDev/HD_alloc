/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:47:42 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/11/05 19:57:45 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd_alloc.h"
#include "hd_alloc_utils.h"

/**
 * @brief Libera una asignación específica realizada con hd_alloc.
 *
 * @param ptr Puntero a la memoria que se desea liberar.
 * @warning Esta funcion es ineficiente para liberar múltiples asignaciones ya
 * que recorre la lista enlazada de asignaciones para encontrar la asignación
 */
void	hd_free(void *ptr)
{
	t_hd_alloc		*alloc;
	t_hd_alloc_list	*current;
	t_hd_alloc_list	*prev;

	alloc = hd_u_get_alloc();
	current = alloc->alloc_list;
	prev = 0;
	while (current)
	{
		if (current->content == ptr)
		{
			if (prev)
				prev->next = current->next;
			else
				alloc->alloc_list = current->next;
			if (current->free_func)
				current->free_func(current->content);
			hd_u_free_hd_alloc_list_node(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}
