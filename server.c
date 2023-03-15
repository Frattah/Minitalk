#include "minitalk.h"
#include "libft/libft.h"

int     pot(int a, int b)
{
    if (b == 0)
        return (1);
    return (a * pot(a, b - 1));
}

void    sig_handler(int signum, siginfo_t *info, void *context)
{
    static int  byte = 0;
    static int  i = 0;

    if (signum == SIGUSR1)
        byte += pot(2, i);
    i++;
    if (i == 8)
    {
        ft_putchar_fd(byte, 1);
        byte = 0;
        i = 0;
    }
}

int main()
{
    t_sa    sa;

    sa = (t_sa) malloc(sizeof(struct sigaction));
    if (!sa)
        exit(1);
	ft_putstr_fd("Server correctly opened [PID = ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("]\n", 1);
	sa->sa_sigaction = sig_handler;
	sa->sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, sa, NULL);
	sigaction(SIGUSR2, sa, NULL);
	while (1)
		pause();
    free(sa);
	return (0);
}