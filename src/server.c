/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:51:34 by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/19 18:52:32 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include <stdlib.h>

int		g_bin = -1;

void	handler(int signal)
{
	if (signal == SIGUSR1)
		g_bin = 0;
	else if (signal == SIGUSR2)
		g_bin = 1;
	else
		ft_printf("Invalid signal\n");
}

int	main(void)
{
	int		i;
	char	*msg;

	msg = ft_strnew(8);
	i = 0;
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	ft_printf("Aguardando sinal...\n");
	while (1)
	{
		pause();
		if (g_bin != -1)
		{
			msg[i++] = g_bin + '0';
			g_bin = -1;
		}
		if (i == 8)
		{
			i = 0;
			ft_printf("%c", ft_binatoi(msg));
		}
	}
	return (0);
}
