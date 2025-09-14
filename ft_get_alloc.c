/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 20:41:33 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/09/13 20:56:39 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_alloc_utils.h"

/**
 * @brief Retorna un puntero estático a una estructura t_alloc.
 * 
 * Esta función asegura que solo exista una instancia de t_alloc
 * durante la ejecución del programa.
 * @return t_alloc * Puntero a la estructura t_alloc.
 */
t_alloc	*ft_get_alloc(void)
{
	static t_alloc	*alloc;

	if (!alloc)
	{
		alloc = malloc(sizeof(t_alloc));
		alloc->alloc_list = 0;
		alloc->malloc_calloc = 0;
	}
	return (alloc);
}
