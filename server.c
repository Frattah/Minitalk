/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:01:57 by frmonfre          #+#    #+#             */
/*   Updated: 2023/03/21 08:41:26 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"

void	sig_handler_srv(int signum, siginfo_t *info, void *context)
{
	static int	byte = 0;
	static int	i = 0;
	static int	pot[8] = {1, 2, 4, 8, 16, 32, 64, 128};

	free(context);
	if (signum == SIGUSR1)
		byte += pot[i];
	i++;
	if (i == 8)
	{
		ft_putchar_fd(byte, 1);
		if (byte == '\0')
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR1);
		}
		byte = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr_fd("Server correctly opened [PID = ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("]\n", 1);
	sa.sa_sigaction = sig_handler_srv;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
