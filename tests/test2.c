/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 20:06:35 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/04/10 03:57:30 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hd_alloc.h"
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int		i;
	void	*ptr;

	i = 0;
	ptr = (void *)1;
	hd_alloc_set_error_func(hd_alloc_error_func_d);
	while (ptr)
	{
		ptr = hd_malloc(1024 * 1024);
		if (++i % 100 == 0)
			write(1, ".", 1);
	}
	write(1, "\nExited loop", 13);
	hd_alloc_clear();
	return (0);
}
/*
int main(void)
{
	void *ptr;
	
	ptr = (void *)1;
	while (ptr)
		ptr = malloc(1024 * 1024 * 10);
	exit (1);
}*/
