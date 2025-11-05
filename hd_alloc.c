/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 12:20:44 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/10/09 16:16:15 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd_alloc.h"
#include "hd_alloc_utils.h"

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
