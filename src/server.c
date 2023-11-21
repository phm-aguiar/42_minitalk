/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:51:34 by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/21 11:23:07 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	handler(int signal, siginfo_t *info, void *context)
{
	static int	c = 0;
	static int	bit = 0;

	context = NULL;
	if (signal == SIGUSR1)
		c += 0 << bit;
	else if (signal == SIGUSR2)
		c += 1 << bit;
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		bit = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sigact;

	sigact.sa_sigaction = handler;
	sigact.sa_flags = SA_SIGINFO;
	sigemptyset(&sigact.sa_mask);
	ft_printf("PID: %d\n", getpid());
	ft_printf("Aguardando sinal...\n");
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	while (1)
		pause();
	return (0);
}
