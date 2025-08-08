/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:31:16 by weiyang           #+#    #+#             */
/*   Updated: 2025/08/06 17:42:09 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <string.h>

enum
{
	READY,
	BUSY,
};

void	signal_wrap(int signo, void *handler, bool use_sigaction);
void	kill_wrap(pid_t pid, int signo);

#endif
