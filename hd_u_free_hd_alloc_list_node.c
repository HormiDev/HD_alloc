/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_u_free_hd_alloc_list_node.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 22:47:36 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/09/21 00:53:05 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd_alloc_utils.h"

void	hd_u_free_hd_alloc_list_node(t_hd_alloc_list *node)
{
	if (!node)
		return ;
	if (node->free_func && node->content)
		node->free_func(node->content);
	free(node);
}
