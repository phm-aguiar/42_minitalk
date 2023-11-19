/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:20:57 by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/19 15:03:40 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(int len)
{
	char	*msg;

	msg = malloc((len + 1) * sizeof(char));
	if (!(msg))
		return (NULL);
	msg[len] = '\0';
	return (msg);
}
