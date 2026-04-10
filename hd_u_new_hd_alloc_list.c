/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_u_new_hd_alloc_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 21:00:31 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/04/10 04:08:48 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd_alloc_utils.h"
#include <stdlib.h>

/**
 * @brief Crea un nuevo nodo de asignación `t_hd_alloc_list`.
 * 
 * Esta función crea un nuevo nodo de asignación que contiene un puntero
 * al contenido y una función para liberar ese contenido.
 * @param content Puntero al contenido a almacenar en el nodo.
 * @param free_func Función para liberar el contenido.
 * @return t_hd_alloc_list* Puntero al nuevo nodo de asignación, o NULL si
 * falla la asignación.
 */
t_hd_alloc_list	*hd_u_new_hd_alloc_list(void *content,
	void (*free_func)(void *))
{
	t_hd_alloc_list	*new_node;

	new_node = malloc(sizeof(t_hd_alloc_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->free_func = free_func;
	new_node->next = NULL;
	return (new_node);
}
