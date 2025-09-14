/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_last_alloc_node.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 21:06:29 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/09/14 18:40:26 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_alloc_utils.h"

/**
 * @brief Obtiene el último nodo de la lista de asignaciones.
 * 
 * Esta función recorre la lista de asignaciones y retorna un puntero
 * al último nodo de la lista.
 * @param alloc_list Puntero a la lista de asignaciones.
 * @return t_alloc_list* Puntero al último nodo de la lista, o NULL si la lista está vacía.
 */
t_alloc_list	*ft_get_last_alloc_node(t_alloc *alloc)
{
	t_alloc_list	*current;

	if (!alloc || !alloc->alloc_list)
		return (NULL);
	current = alloc->alloc_list;
	while (current->next)
		current = current->next;
	return (current);
}
