/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 20:06:35 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/11/09 21:35:19 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hd_alloc.h"
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	int i = 0;
	hd_alloc_set_error_func(hd_alloc_error_func_d);
	void *ptr = (void *)1;

	while(ptr)
	{
		ptr = hd_alloc(malloc(1024 * 1024 * 10), free);
		if (++i % 50000 == 0)
			write(1, ".", 1);
	}
	return (0);
}
