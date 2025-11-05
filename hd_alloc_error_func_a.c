/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_alloc_error_func_a.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:05:26 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/11/05 19:27:14 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd_alloc.h"
#include "hd_alloc_utils.h"

void	*hd_alloc_error_func_a(void)
{
	t_hd_alloc *alloc;

	alloc = hd_u_get_alloc();
	hd_alloc_clear();
	return(0);
}
