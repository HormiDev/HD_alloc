/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_u_get_last_hd_alloc_list.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 13:35:48 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/09/20 14:37:16 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd_alloc_utils.h"

/**
 * @brief Obtiene el último nodo de la lista de asignaciones.
 * 
 * Esta función recorre la lista de asignaciones en el
 * estructura `t_hd_alloc` y devuelve un puntero al último nodo
 * de la lista.
 * @param alloc Puntero a la estructura `t_hd_alloc`.
 * @return t_hd_alloc_list* Puntero al último nodo de la lista, o NULL si la
 * estructura es NULL o la lista está vacía.
 */
t_hd_alloc_list	*hd_u_get_last_hd_alloc_list(t_hd_alloc *alloc)
{
	t_hd_alloc_list	*current;

	if (!alloc)
		return (NULL);
	current = alloc->alloc_list;
	while (current && current->next)
		current = current->next;
	return (current);
}
