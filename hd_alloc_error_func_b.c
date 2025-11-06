/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_alloc_error_func_b.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:44:28 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/11/05 20:14:33 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd_alloc.h"
#include "hd_alloc_utils.h"

/**
 * @brief Funcion de error para hd_alloc que limpia la memoria asignada con
 * hd_alloc y termina el programa con EXIT_FAILURE.
 * 
 * @return void* Nunca devuelve, ya que termina el programa.
 */
void	*hd_alloc_error_func_b(void)
{
	t_hd_alloc *alloc;

	alloc = hd_u_get_alloc();
	hd_alloc_clear();
	exit(EXIT_FAILURE);
}
