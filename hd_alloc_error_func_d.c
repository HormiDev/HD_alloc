/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_alloc_error_func_d.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:13:26 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/11/09 23:35:27 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd_alloc.h"
#include "hd_alloc_utils.h"

/**
 * @brief Funcion de error para hd_alloc que imprime un mensaje de error,
 * limpia la memoria asignada con hd_alloc y termina el programa con
 * EXIT_FAILURE.
 * 
 * Para usar esta función como manejador de errores, llame a
 * `hd_alloc_set_error_func(hd_alloc_error_func_d);`
 *
 * @return void* Nunca devuelve, ya que termina el programa.
 */
void	*hd_alloc_error_func_d(void)
{
	write(2, "hd_alloc: memory allocation error\n", 35);
	hd_alloc_clear();
	exit(1);
}
