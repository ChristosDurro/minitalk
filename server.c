/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:54:44 by cdurro            #+#    #+#             */
/*   Updated: 2023/06/22 15:40:32 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

void	handle_signal(int signal, siginfo_t *info, void *context) 
{
	static int bit;
	static int character;
	static int client_pid;

	(void)context;
	if (!client_pid || client_pid == 0)
		client_pid = info->si_pid;
	if (client_pid != info->si_pid)
	{
		kill(info->si_pid, SIGUSR1);
		return ;
	}
	if (signal == SIGUSR1) {
		character |= (1 << bit);
	}
	bit++;
	if (bit == 8)
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

int main(int argc, char **argv)
{
	struct sigaction sa;

	if (argc != 1)
	{
		ft_printf("Usage: ./server\n");
		exit(1);
	}
    ft_printf("Server PID: %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1) {
        pause();
    }

    return 0;
}
