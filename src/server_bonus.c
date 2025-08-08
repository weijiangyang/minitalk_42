/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:57:52 by weiyang           #+#    #+#             */
/*   Updated: 2025/08/08 15:57:56 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	handler(int signo, siginfo_t *info, void *more_info)
{
	static char		c = 0;
	static char		bit = 0;
	static pid_t	client;

	(void) more_info;
	if (info->si_pid)
		client = info->si_pid;
	if (signo == SIGUSR1)
		c |= 0b10000000 >> bit;
	else if (signo == SIGUSR2)
		c &= ~(0b10000000 >> bit);
	bit ++;
	if (bit == CHAR_BIT)
	{
		bit = 0;
		if (c == '\0')
		{
			kill_wrap(client, SIGUSR2);
			return ;
		}
		write (STDOUT_FILENO, &c, 1);
		c = 0;
	}
	kill_wrap (client, SIGUSR1);
}

int	main(void)
{
	printf("the pid of server is %d\n", getpid());
	signal_wrap(SIGUSR1, handler, true);
	signal_wrap (SIGUSR2, handler, true);
	while (1)
		pause();
	exit (EXIT_SUCCESS);
}
