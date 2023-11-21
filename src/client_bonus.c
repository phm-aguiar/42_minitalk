/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:41:49 by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/21 14:53:04 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int		g_setexit = 0;

void	handler(int signal)
{
	if (signal == SIGUSR1)
		g_setexit = 1;
}

void	send_msg(unsigned char bip, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_setexit = 0;
		if (bip >> bit & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bit++;
		while (!g_setexit)
			;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*msg;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		msg = argv[2];
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		while (*msg)
		{
			send_msg(*msg, pid);
			msg++;
		}
		ft_printf("\nThe Process server has received the message.\n");
	}
	return (0);
}
