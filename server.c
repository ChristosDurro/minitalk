/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:54:44 by cdurro            #+#    #+#             */
/*   Updated: 2023/06/23 12:29:43 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

static void	handle_signal(int signal, siginfo_t *info, void *context) 
{
	static int bit;
	static int character;
	static int client_pid;

	(void)context;
	if (!client_pid || client_pid == 0)
		client_pid = info->si_pid;
	if (client_pid == info->si_pid)
	{
		if (signal == SIGUSR1)
			character |= (1 << bit);
		if (++bit == 8)
		{
			write(1, &character, 1);
			if (character == '\0')
			{
				kill(client_pid, SIGUSR2);
				client_pid = 0;
			}
			character = 0;
			bit = 0;
		}
	}
	else
		kill(info->si_pid, SIGUSR1);
}

int main(void)
{
	struct sigaction sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
    ft_printf(SERVER_START, getpid());
	while (1) {
        pause();
    }

    return 0;
}
