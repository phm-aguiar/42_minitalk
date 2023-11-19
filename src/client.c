/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:41:49 by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/19 18:54:36 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	send_msg(char *bip, int pid)
{
	char	*binary;
	int		i;
	int		j;

	i = 0;
	while (bip[i])
	{
		binary = ft_itobin(bip[i]);
		ft_printf("%c = %s \n", bip[i], binary);
		j = 0;
		while (binary[j])
		{
			if (binary[j] == '1')
				kill(pid, SIGUSR2);
			else if (binary[j] == '0')
				kill(pid, SIGUSR1);
			j++;
			usleep(10000);
		}
		free(binary);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		send_msg(argv[2], pid);
	}
	return (0);
}
