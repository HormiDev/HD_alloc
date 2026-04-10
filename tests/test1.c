/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 20:34:28 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/04/10 03:58:17 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hd_alloc.h"
#include <unistd.h>
#include <string.h>

int	test_print(const char *str)
{
	int	len;

	len = write(1, str, strlen(str));
	write(1, "\n", 1);
	return (len);
}

int	main(void)
{
	char	*str1;

	hd_alloc_set_error_func(hd_alloc_error_func_d);
	str1 = hd_malloc(25 * sizeof(char));
	strncpy(str1, "Hello, hd_alloc!", 25);
	test_print(str1);
	str1 = hd_calloc(10, sizeof(char));
	test_print(str1);
	str1 = hd_alloc(strdup("This is a test string."), free);
	test_print(str1);
	str1 = hd_alloc(strdup("free me at the end"), free);
	test_print(str1);
	hd_free(str1);
	test_print("Freed string successfully.");
	hd_alloc_clear();
	str1 = hd_malloc(25 * sizeof(char));
	strncpy(str1, "Hello again, hd_alloc!", 25);
	test_print(str1);
	hd_alloc_clear();
	hd_free(str1);
	hd_alloc_clear();
	return (0);
}
