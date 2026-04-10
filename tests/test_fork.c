/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:54:35 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/04/10 03:55:52 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hd_alloc.h"
#include <stdio.h>
#include <sys/wait.h>

static void	hd_fork_child_signal_handler(int sig)
{
	hd_alloc_clear();
	exit(128 + sig);
}

static void	hd_fork_continue(void)
{
	pid_t	pid;
	int		i;

	pid = hd_fork();
	if (pid > 0)
		kill(pid, SIGTERM);
	pid = hd_fork();
	if (pid > 0)
		kill(pid, SIGTERM);
	pid = hd_fork();
	pid = hd_fork();
	pid = hd_fork_cleanable(hd_fork_child_signal_handler);
	i = 0;
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
}

int	main(void)
{
	pid_t	pid;

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
	hd_fork_continue();
	printf("pid: %d fork succeeded\n", pid);
	hd_alloc_clear();
	return (0);
}
