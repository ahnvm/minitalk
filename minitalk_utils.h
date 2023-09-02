/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:16:31 by acan              #+#    #+#             */
/*   Updated: 2023/08/30 15:37:08 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_UTILS_H
# define MINITALK_UTILS_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	ft_putstr(char *str);
int		ft_atoi(const char *str);
void	ft_putnbr_fd(int n, int fd);

#endif