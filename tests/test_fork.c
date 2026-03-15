/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:54:35 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/03/15 05:12:19 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hd_alloc.h"
#include <stdio.h>
#include <sys/wait.h>

int main()
{
	pid_t pid;

	pid = hd_fork();
	if (pid == -1)
	{
		perror("fork failed");
		return (1);
	}
	if (pid > 0)
		kill(pid, SIGTERM);
	if (pid > 0)
		pid = hd_fork();
	if (pid > 0)
		kill(pid, SIGTERM);
	pid = hd_fork();
	if (pid > 0)
		kill(pid, SIGTERM);
	pid = hd_fork();
	if (pid > 0)
		kill(pid, SIGTERM);
	pid = hd_fork();
	if (pid > 0)
		kill(pid, SIGTERM);
	pid = hd_fork();
	if (pid > 0)
		kill(pid, SIGTERM);
	pid = hd_fork();
	pid = hd_fork();
	pid = hd_fork();
	pid = hd_fork();
	int i = 0;
	if (pid == 0)
	{
		while (i < 10)
		{
			printf("hola, soy un proceso hijo %d\n", i);
			sleep(1);
			i++;
		}
		
	}
	else
		sleep(3);
	printf("pid: %d fork succeeded\n", pid);
	hd_alloc_clear();
	return (0);
}
