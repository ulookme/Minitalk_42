/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:45:10 by chajjar           #+#    #+#             */
/*   Updated: 2022/05/26 13:23:05 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_check(int signal)
{
	signal = 0;
	ft_printf("RECEPTE MESSAGE\n");
}

void	send_message(pid_t pid, unsigned char s )
{
	char	*tab;
	int		i;

	i = 0;
	tab = ft_char_to_bytes(s);
	while (tab[i])
	{
		if (tab[i] == '1')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(30);
		i++;
	}
	free(tab);
	usleep(20);
}

int	main(int argc, char **argv)
{
	int		i;
	pid_t	pid;

	if (argc == 3)
	{
		i = 0;
		signal(SIGUSR1, sig_check);
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			send_message(pid, (unsigned char)argv[2][i]);
			i++;
		}
		send_message(pid, '\0');
	}
	return (0);
}
