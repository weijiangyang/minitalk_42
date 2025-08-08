/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:56:59 by weiyang           #+#    #+#             */
/*   Updated: 2025/08/08 15:57:05 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include "../libft/libft.h"

volatile sig_atomic_t	g_server = BUSY;

void	ack_handler(int signo)
{
	(void) signo;
	g_server = READY;
}

void	end_handler(int signo)
{
	(void) signo;
	write (STDOUT_FILENO, "ok!\n", 4);
	exit (EXIT_SUCCESS);
}

void	send_char(int server, char c)
{
	int	bit;

	bit = 0;
	while (bit < CHAR_BIT)
	{
		if (c & (0b10000000 >> bit))
			kill_wrap(server, SIGUSR1);
		else
			kill_wrap(server, SIGUSR2);
		g_server = BUSY;
		while (g_server == BUSY)
			usleep(42);
		bit++;
	}
}

int	main(int ac, char **av)
{
	pid_t	server;
	char	*message;

	if (ac != 3)
	{
		perror("Usage = ./client <PID> \"message\"\n");
		exit(EXIT_FAILURE);
	}
	server = ft_atoi(av[1]);
	message = av[2];
	signal_wrap (SIGUSR1, ack_handler, false);
	signal_wrap (SIGUSR2, end_handler, false);
	while (*message)
	{
		send_char(server, *message);
		message++;
	}
	send_char(server, '\0');
	exit(EXIT_SUCCESS);
}
