/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_alloc_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 21:19:59 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/09/13 21:20:48 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_alloc_utils.h"

/**
 * @brief Libera un nodo de asignación.
 * 
 * Esta función libera el contenido del nodo utilizando la función
 * de liberación proporcionada y luego libera el nodo en sí.
 * @param node Puntero al nodo de asignación a liberar.
 */
void	ft_free_alloc_node(t_alloc_list *node)
{
	if (!node)
		return ;
	if (node->free_func)
		node->free_func(node->content);
	free(node);
}
