/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:12:12 by acan              #+#    #+#             */
/*   Updated: 2023/09/02 17:32:25 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_utils.h"

unsigned char	g_recievedchar = 0;

void	signalhandler(int signalNum)
{
	static int	bitcounter = 0;

	if (signalNum == SIGUSR1)
	{
		g_recievedchar |= 1 << bitcounter;
	}
	else if (signalNum == SIGUSR2)
	{
		g_recievedchar |= 0 << bitcounter;
	}
	bitcounter++;
	if (bitcounter == 7)
	{
		write(1, &g_recievedchar, 1);
		g_recievedchar = 0;
		bitcounter = 0;
	}
}

int	main(void)
{
	signal (SIGUSR1, signalhandler);
	signal (SIGUSR2, signalhandler);
	ft_putnbr_fd (getpid(), 1);
	write (1, "\n", 1);
	while (1)
		pause();
	return (0);
}
