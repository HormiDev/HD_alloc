/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_alloc_error_func_a.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:05:26 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/11/06 19:22:53 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd_alloc.h"
#include "hd_alloc_utils.h"

/**
 * @brief Funcion de error para hd_alloc que limpia la memoria asignada con
 * hd_alloc y devuelve NULL.
 * 
 * Para usar esta función como manejador de errores, llame a
 * `hd_alloc_set_error_func(hd_alloc_error_func_a);`
 * 
 * @return void* Siempre devuelve NULL.
 */
void	*hd_alloc_error_func_a(void)
{
	t_hd_alloc *alloc;

	alloc = hd_u_get_alloc();
	hd_alloc_clear();
	return(0);
}
