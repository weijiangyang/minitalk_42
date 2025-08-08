/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:21:23 by weiyang           #+#    #+#             */
/*   Updated: 2025/08/07 16:37:04 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include "../libft/libft.h"

void	kill_wrap(pid_t pid, int signo)
{
	if (kill(pid, signo) < 0)
	{
		perror("kill signal failed!");
		exit(EXIT_FAILURE);
	}
}

void	signal_wrap(int signo, void *handler, bool use_sigaction)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sigemptyset(&sa.sa_mask);
	if (use_sigaction)
	{
		sa.sa_sigaction = (void (*)(int x, siginfo_t * y, void *))handler;
		sa.sa_flags = SA_SIGINFO;
	}
	else
	{
		sa.sa_handler = (void (*)(int))handler;
		sa.sa_flags = 0;
	}
	if (sigaction(signo, &sa, NULL) < 0)
	{
		perror("Problem sigaction!");
		exit(EXIT_FAILURE);
	}
}
