/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:57:46 by frmonfre          #+#    #+#             */
/*   Updated: 2023/03/21 08:41:09 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"

void	sig_handler_cli(int signum, siginfo_t *info, void *context)
{
	if (signum != SIGUSR1)
		return;
	free(context);
	free(info);
	ft_putstr_fd("Message received!\n", 1);
	exit(1);
}

void	send_message(int pid, char *msg)
{
	int	i;
	int	j;

	i = -1;
	while (msg[++i])
	{
		j = -1;
		while (++j < 8)
		{
			usleep(500);
			if ((1 & msg[i]) == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			msg[i] >>= 1;
		}
	}
	while (++j < 17)
	{
		usleep(500);
		kill(pid, SIGUSR2);
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_putstr_fd("Error: Invalid Number of Parameter!\n", 1);
		exit(1);
	}
	sa.sa_sigaction = sig_handler_cli;
	sigaction(SIGUSR1, &sa, NULL);
	pid = ft_atoi(argv[1]);
	send_message(pid, argv[2]);
	while (1)
		pause();
}
