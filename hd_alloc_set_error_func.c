/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_alloc_set_error_func.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:09:06 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/11/06 19:13:51 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd_alloc.h"
#include "hd_alloc_utils.h"

/**
 * @brief Establece una función personalizada para manejar errores de asignación
 * de memoria.
 * 
 * @param error_func Puntero a la función que se llamará en caso de error de
 * asignación. La función debe devolver un puntero void*.
 * 
 * @example hd_alloc_set_error_func(hd_alloc_error_func_a);
 * Esta llamada establecerá la función hd_alloc_error_func_a como la función
 * que se llamará en caso de error de asignación.
 */
void	hd_alloc_set_error_func(void *(*error_func)(void))
{
	t_hd_alloc	*alloc;

	alloc = hd_u_get_alloc();
	alloc->error_func = error_func;
}
