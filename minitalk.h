/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:37:01 by chajjar           #+#    #+#             */
/*   Updated: 2022/05/26 13:31:07 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "./ft_printf/ft_printf.h"

int				ft_2_power(int nb);
char			*ft_char_to_bytes(unsigned char octet);
unsigned char	ft_bytes_to_char(char *str);
int				ft_atoi(const char *str);
#endif
