/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:12:18 by acan              #+#    #+#             */
/*   Updated: 2023/09/02 17:35:19 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_utils_bonus.h"

void	send_signal(int pid, unsigned char character)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (character >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(50);
	}
}

int	error_handler(int ac, char**av)
{
	long long	i;

	i = 0;
	if (ac == 3)
	{
		if (ft_atoi(av[1]) < 1)
		{
			ft_putstr("Process Id must be bigger than 0");
			return (1);
		}
		while (av[2][i])
		{
			send_signal(ft_atoi(av[1]), av[2][i]);
			i++;
		}
		return (0);
	}
	else
	{
		ft_putstr("Use the client like './client <process_id> <message>'");
		return (1);
	}
}

int	main(int ac, char **av)
{
	int	errorno;

	errorno = error_handler (ac, av);
	if (errorno)
		return (errorno);
	return (0);
}
