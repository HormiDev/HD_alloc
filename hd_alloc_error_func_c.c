/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_alloc_error_func_c.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:00:12 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/11/06 19:23:02 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd_alloc.h"
#include "hd_alloc_utils.h"

/**
 * @brief Funcion de error para hd_alloc que imprime un mensaje de error,
 * limpia la memoria asignada con hd_alloc y devuelve NULL.
 * 
 * Para usar esta función como manejador de errores, llame a
 * `hd_alloc_set_error_func(hd_alloc_error_func_c);`
 * 
 * @return void* Siempre devuelve NULL.
 */
void	*hd_alloc_error_func_c(void)
{
	t_hd_alloc *alloc;

	write(2, "hd_alloc: memory allocation error\n", 35);
	alloc = hd_u_get_alloc();
	hd_alloc_clear();
	return(0);
}
