/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_u_get_alloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 03:05:05 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/09/22 13:44:25 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd_alloc_utils.h"

t_hd_alloc *hd_u_get_alloc(void)
{
	static t_hd_alloc *alloc;

	if (!alloc)
		alloc = hd_u_alloc_init();
	if (!alloc)
	{
		write(2, "Error: Memory allocation failed in hd_u_get_alloc\n", 51);
		exit(1);
	}
	return (alloc);
}
