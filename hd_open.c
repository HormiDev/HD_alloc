/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 00:24:09 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/04/10 04:10:40 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd_alloc.h"

void	hd_free_open(void *file_ptr)
{
	close(*(int *)file_ptr);
	free(file_ptr);
}

/**
 * @brief Abre un file descriptor igual que lo haria un open con la
 * peculiaridad de gestionar la un puntero con referencia a fd el la lista
 * de hd_alloc para cerrarlo automaticamente cuando se libere la memoria
 * 
 * @param pathname Ruta al archivo a abrir
 * @param flags Flags para la apertura del archivo
 * @param ... Argumentos adicionales para la apertura del archivo
 * @return Descriptor de archivo o -1 en caso de error
 */
int	hd_open(const char *pathname, int flags, ...)
{
	va_list	args;
	mode_t	mode;
	int		*file_ptr;

	file_ptr = hd_alloc(malloc(sizeof(int)), hd_free_open);
	if (!file_ptr)
		return (-1);
	if (flags & (O_CREAT | O_TMPFILE))
	{
		va_start(args, flags);
		mode = va_arg(args, mode_t);
		va_end(args);
		*file_ptr = open(pathname, flags, mode);
	}
	else
		*file_ptr = open(pathname, flags);
	return (*file_ptr);
}
