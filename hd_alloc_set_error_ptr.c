/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_alloc_set_error_ptr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:14:22 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/11/06 19:20:22 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd_alloc.h"
#include "hd_alloc_utils.h"

/**
 * @brief Establece un puntero personalizado para que en caso de error de
 * asignación de memoria una funcion de error personalizada pueda utilizarlo.
 * 
 * @param error_ptr Puntero que se devolverá en caso de error de asignación.
 */
void	hd_alloc_set_error_ptr(void *error_ptr)
{
	t_hd_alloc	*alloc;

	alloc = hd_u_get_alloc();
	alloc->error_ptr = error_ptr;
}
