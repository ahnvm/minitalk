/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:12:18 by acan              #+#    #+#             */
/*   Updated: 2023/08/30 17:06:05 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_utils.h"

void	send_signal(int pid, unsigned char character)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		if (character >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(50);
	}
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 3)
	{
		if (ft_atoi(av[1]) < 1)
		{
			ft_putstr("Process Id must be bigger than 1");
			return (1);
		}
		while (av[2][i])
		{
			send_signal(ft_atoi(av[1]), av[2][i]);
			i++;
		}
	}
	else
	{
		ft_putstr("Use the client like './client <process_id> <message>'");
		return (1);
	}
	return (0);
}
