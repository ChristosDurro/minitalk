/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:54:42 by cdurro            #+#    #+#             */
/*   Updated: 2023/06/23 12:28:19 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

static void	handle_server_response(int signal)
{
	if (signal == SIGUSR2)
		ft_printf(SUCCESS_MSG);
	else
	{
		ft_printf(SERVER_IS_BUSY);
		exit(1);
	}
}

static void	send_binary(int pid, char *str)
{
	int	i;

	while (*str)
	{
		i = 0;
		while (i < 8)
		{
			if (*str & (1 << i++))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
		str++;
	}
}

static void	send_null(int pid)
{
	int	i;

	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
}

int main(int argc, char **argv)
{
	int pid;
	struct sigaction sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_handler = &handle_server_response;

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (argc == 3)
	{

		pid = ft_atoi(argv[1]);
		send_binary(pid, argv[2]);
		send_binary(pid, "\n");
		send_null(pid);
	}
	else
	{
		ft_printf(ARGS_ERROR, argv[0]);
		return 1;
    }
    return 0;
}