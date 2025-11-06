/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_alloc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 20:08:04 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/11/06 19:21:05 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HD_ALLOC_H
# define HD_ALLOC_H

#include <stdlib.h>

void	*hd_alloc(void *ptr, void (*free_func)(void *));
void	*hd_malloc(size_t size);
void	*hd_calloc(size_t count, size_t size);
void	hd_alloc_clear(void);
void	hd_free(void *ptr);

void	hd_alloc_set_error_func(void *(*error_func)(void));
void	hd_alloc_set_error_ptr(void *error_ptr);

void	*hd_alloc_error_func_a(void);
void	*hd_alloc_error_func_b(void);
void	*hd_alloc_error_func_c(void);
void	*hd_alloc_error_func_d(void);

#endif