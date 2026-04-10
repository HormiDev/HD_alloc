/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 03:25:54 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/04/10 04:17:28 by ide-dieg         ###   ########.fr       */
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

static int	test_continue_continue(void)
{
	int	fd;

	fd = hd_open(".tmp/create_file_4.txt", O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
	{
		test_print("Failed to open .tmp/create_file_4.txt");
		hd_alloc_clear();
		return (1);
	}
	fd = hd_open(".tmp/create_file_1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		test_print("Failed to open .tmp/create_file_1.txt");
		hd_alloc_clear();
		return (1);
	}
	return (0);
}

static int	test_continue(void)
{
	int	fd;

	fd = hd_open(".tmp/create_file_2.txt", O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
	{
		test_print("Failed to open .tmp/create_file_2.txt");
		hd_alloc_clear();
		return (1);
	}
	fd = hd_open(".tmp/create_file_3.txt", O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
	{
		test_print("Failed to open .tmp/create_file_3.txt");
		hd_alloc_clear();
		return (1);
	}
	return (test_continue_continue());
	return (0);
}

int	main(void)
{
	int	fd;

	fd = hd_open(".tmp/create_file_1.txt", O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
	{
		test_print("Failed to open .tmp/create_file_1.txt");
		hd_alloc_clear();
		return (1);
	}
	test_print("File opened successfully");
	if (write(fd, "Hello, World!", 13) == 13)
		test_print("Data written successfully");
	else
	{
		test_print("Failed to write data");
		hd_alloc_clear();
		return (1);
	}
	close(fd);
	close(fd);
	close(fd);
	return (test_continue());
	test_print("Allocation cleared successfully");
	hd_alloc_clear();
	return (0);
}
