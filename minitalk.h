/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:05:56 by cdurro            #+#    #+#             */
/*   Updated: 2023/06/22 15:41:04 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H

#define _GNU_SOURCE

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

void	handle_server_response(int signal);
void	handle_signal(int signal, siginfo_t *info, void *context);
void	send_binary(int pid, char *str);
void	send_null(int pid);


#endif