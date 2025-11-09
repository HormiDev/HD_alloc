/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 12:20:44 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/11/09 23:18:30 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd_alloc.h"
#include "hd_alloc_utils.h"

/**
 * @brief Registra un puntero y su función de liberación en el sistema de
 * gestión de memoria.
 * Esta función permite rastrear y liberar automáticamente la memoria
 * asignada cuando ya no se necesite, evitando fugas de memoria.
 * Si `ptr` es NULL, se llama a la función de error configurada (si existe)
 * y se devuelve NULL.
 * Si ocurre un error al registrar la asignación, se libera la memoria
 * utilizando la función `free_func` proporcionada (si existe), se llama a la
 * función de error configurada (si existe) y se devuelve NULL.
 * 
 * @param ptr Puntero a la memoria asignada que se desea gestionar.
 * @param free_func Puntero a la función que se utilizará para liberar la
 * memoria cuando ya no se necesite.
 * @return void* Devuelve el mismo puntero `ptr` si la asignación y el registro
 * fueron exitosos. Si `ptr` es NULL o si ocurre un error durante el
 * registro, devuelve NULL o llama a la función de error configurada.
 * 
 * @warning Si no se configura ninguna función de error y ocurre un error, la
 * función simplemente devolverá NULL sin limpiar la memoria. y el usuario será
 * responsable de llamar a hd_alloc_clear() o manejar la situación de error.
 */
void	*hd_alloc(void *ptr, void (*free_func)(void *))
{
	t_hd_alloc		*alloc;
	t_hd_alloc_list *new_alloc;

	alloc = hd_u_get_alloc();
	if (!ptr)
	{
		if (alloc->error_func)
			return (alloc->error_func());
		return (0);
	}
	new_alloc = hd_u_new_hd_alloc_list(ptr, free_func);
	if (!new_alloc)
	{
		if (ptr && free_func)
			free_func(ptr);
		if (alloc->error_func)
			return (alloc->error_func());
		return (0);
	}
	hd_u_add_front_hd_alloc_list(alloc, new_alloc);
	return(ptr);
}
