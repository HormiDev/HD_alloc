/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:58:24 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/11/09 20:57:26 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd_alloc.h"

void	*hd_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		hd_alloc_clear();
	return (hd_alloc(ptr, free));
}
