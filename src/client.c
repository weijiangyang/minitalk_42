/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:52:27 by weiyang           #+#    #+#             */
/*   Updated: 2025/08/06 17:46:11 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include "../libft/libft.h"

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
		usleep(100);
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
	while (*message)
	{
		send_char(server, *message);
		message++;
	}
	send_char(server, '\0');
	exit(EXIT_SUCCESS);
}
