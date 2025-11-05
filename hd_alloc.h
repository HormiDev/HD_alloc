/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_alloc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 20:08:04 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/10/09 16:21:06 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HD_ALLOC_H
# define HD_ALLOC_H

#include <stdlib.h>

void	*hd_alloc(void *ptr, void (*free_func)(void *));
void	hd_alloc_clear(void);

void	*hd_alloc_error_func_a(void);

#endif