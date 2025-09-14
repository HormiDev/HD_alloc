/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_alloc_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 21:01:53 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/09/13 21:10:07 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_alloc_utils.h"

/**
 * @brief Añade un nuevo nodo a la lista de asignaciones.
 * 
 * Esta función añade un nuevo nodo al final de la lista de asignaciones
 * mantenida en la estructura t_alloc.
 * @param alloc Puntero a la estructura t_alloc que contiene la lista de asignaciones.
 * @param new_node Puntero al nuevo nodo a añadir.
 */
void	ft_add_alloc_node(t_alloc *alloc, t_alloc_list *new_node)
{
	t_alloc_list	*last;

	if (!alloc || !new_node)
		return ;
	if (!alloc->alloc_list)
		alloc->alloc_list = new_node;
	else
	{
		last = ft_get_last_alloc_node(alloc->alloc_list);
		last->next = new_node;
	}
}
