/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:01:21 by frmonfre          #+#    #+#             */
/*   Updated: 2023/03/21 08:33:44 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# include <signal.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <unistd.h>

void	sig_handler_srv(int signum, siginfo_t *info, void *context);

void	sig_handler_cli(int signum, siginfo_t *info, void *context);

void	send_message(int pid, char *msg);

#endif
