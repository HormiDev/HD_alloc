/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 12:20:44 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/09/22 00:40:42 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd_alloc.h"
#include "hd_alloc_utils.h"

void	*hd_alloc(void *ptr, void (*free_func)(void *))
{
	t_hd_alloc		*alloc;
	
	alloc = hd_u_get_alloc();
	if (!alloc)
	{
		return (NULL);
	}
	if (!ptr)
	{
		alloc->error_func(ptr);
		return (NULL);
	}
	if (free_func)
		free_func(ptr);
	return (malloc(sizeof(ptr)));
}
