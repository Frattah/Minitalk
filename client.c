/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:17:15 by frmonfre          #+#    #+#             */
/*   Updated: 2023/03/15 15:17:17 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
