#include "minitalk.h"
#include "libft/libft.h"

int main(int argc, char **argv)
{
    int pid = ft_atoi(argv[1]);
    int i = 0;
    int j;

    while (argv[2][i])
    {
        j = 0;
        while (j < 8)
        {
            usleep(1200);
            if((1 & argv[2][i]) == 1)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            argv[2][i] >>= 1; 
            j++;
        }
        i++;
    }
}