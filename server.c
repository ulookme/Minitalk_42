/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:45:29 by chajjar           #+#    #+#             */
/*   Updated: 2022/05/26 13:27:08 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_update(int sig, siginfo_t *info, void *context)
{
	static int	i;
	static char	tab[9];
	char		octet;

	context = 0;
	if (sig == SIGUSR1)
		tab[i++] = '1';
	if (sig == SIGUSR2)
		tab[i++] = '0';
	if (i == 8)
	{
		octet = ft_bytes_to_char(tab);
		if (octet)
			write(1, &octet, 1);
		else
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR1);
		}
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_update;
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		pause();
}
