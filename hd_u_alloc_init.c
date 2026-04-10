/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_u_alloc_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 03:00:10 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/04/10 04:10:16 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd_alloc_utils.h"

t_hd_alloc	*hd_u_alloc_init(void)
{
	t_hd_alloc	*alloc;

	alloc = (t_hd_alloc *)malloc(sizeof(t_hd_alloc));
	if (!alloc)
		return (NULL);
	alloc->alloc_list = NULL;
	alloc->error_func = NULL;
	return (alloc);
}
