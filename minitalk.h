/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:05:56 by cdurro            #+#    #+#             */
/*   Updated: 2023/06/23 12:40:34 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H

#define _GNU_SOURCE

#include <signal.h>
#include "libft/libft.h"

#define SERVER_START "\033[32mServer PID: %d\033[0m\n"
#define SERVER_IS_BUSY "\033[31mServer is busy now. Try again later!\n"
#define ARGS_ERROR "\033[31mUsage: %s <server_pid> <message>\n"
#define SUCCESS_MSG "\033[32mMessage received!\n"

#endif