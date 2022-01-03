/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharley <xcharley@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:47:33 by xcharley          #+#    #+#             */
/*   Updated: 2021/12/25 14:53:47 by xcharley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	print_number(int d, int *megacount)
{
	int	i;

	ft_putnbr_fd(d, 1);
	if (d == -2147483648)
	{
		(*megacount) += 11;
		return ;
	}
	i = 0;
	if (d < 0)
	{
		d = -d;
		(*megacount)++;
	}
	while (d > 9)
	{
		d = d / 10;
		i++;
	}
	i++;
	(*megacount) += i;
}

void	print_unsigned_number(unsigned int d, int *megacount)
{
	int		i;
	char	hex[100];
	int		temp;

	i = 0;
	check_zero(d, megacount);
	while (d != 0)
	{
		temp = 0;
		temp = d % 10;
		hex[i] = temp + 48;
		i++;
		d = d / 10;
	}
	i--;
	write_number(i, hex, megacount);
}
