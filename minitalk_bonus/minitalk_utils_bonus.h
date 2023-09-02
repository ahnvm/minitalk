/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:16:31 by acan              #+#    #+#             */
/*   Updated: 2023/08/30 17:08:45 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_UTILS_BONUS_H
# define MINITALK_UTILS_BONUS_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	ft_putstr(char *str);
int		ft_atoi(const char *str);
void	ft_putnbr_fd(int n, int fd);

#endif