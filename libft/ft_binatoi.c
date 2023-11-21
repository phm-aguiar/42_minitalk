/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binatoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:31:51 by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/20 17:41:13 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_binatoi(char *bin)
{
	int	power;
	int	i;
	int	inter;
	int	result;

	result = 0;
	i = 0;
	while (bin[i])
	{
		inter = 1;
		power = ft_strlen(bin) - 1 - i;
		while (power--)
			inter *= 2;
		result += (bin[i] - '0') * inter;
		i++;
	}
	return (result);
}
