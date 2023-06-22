/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:54:42 by cdurro            #+#    #+#             */
/*   Updated: 2023/06/22 15:39:00 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

void	handle_server_response(int signal)
{
	if (signal == SIGUSR2)
		ft_printf("Message received!\n");
	else
	{
		ft_printf("Server is busy now. Try again later!\n");
		exit(1);
	}
}

void	send_binary(int pid, char *str)
{
	int	i;

	while (*str)
	{
		i = 0;
		while (i < 8)
		{
			if (*str & (1 << i++))
			{
				if (kill(pid, SIGUSR1) == -1)
					ft_printf("error s1\n");
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					ft_printf("error s2\n");				
			}
			usleep(100);
		}
		str++;
	}
}

void	send_null(int pid)
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
	int i;
	struct sigaction sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_handler = &handle_server_response;
	
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("Sigaction 1 error\n");
		exit(1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Sigaction 2 error\n");
		exit(1);
	}	
	if (argc == 3)
	{

		pid = ft_atoi(argv[1]);
		send_binary(pid, argv[2]);
		send_binary(pid, "\n");
		send_null(pid);
	}
	else
	{
		ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
		return 1;
    }
    return 0;
}