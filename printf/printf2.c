/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharley <xcharley@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 16:07:36 by xcharley          #+#    #+#             */
/*   Updated: 2021/12/25 14:53:33 by xcharley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_zero(unsigned long d, int *megacount)
{
	if (d == 0)
	{
		write(1, "0", 1);
		(*megacount) += 1;
	}
}

void	write_number(int i, char *hex, int *megacount)
{
	while (i >= 0)
	{
		write(1, &hex[i], 1);
		(*megacount)++;
		i--;
	}
}

void	print_upper_hex(unsigned int d, int *megacount)
{
	char	hex[100];
	int		i;
	int		temp;

	i = 0;
	check_zero(d, megacount);
	while (d != 0)
	{
		temp = 0;
		temp = d % 16;
		if (temp < 10)
			hex[i++] = temp + 48;
		else
			hex[i++] = temp + 55;
		d = d / 16;
	}
	i--;
	write_number(i, hex, megacount);
}

void	print_hex(void *p, int *megacount)
{
	char			hex[100];
	int				i;
	int				temp;
	unsigned long	d;

	d = (unsigned long)p;
	i = 0;
	write(1, "0x", 2);
	(*megacount) += 2;
	check_zero(d, megacount);
	while (d != 0)
	{
		temp = 0;
		temp = d % 16;
		if (temp < 10)
			hex[i++] = temp + 48;
		else
			hex[i++] = temp + 87;
		d = d / 16;
	}
	i--;
	write_number(i, hex, megacount);
}

void	print_lower_hex(unsigned int d, int *megacount)
{
	char	hex[100];
	int		i;
	int		temp;

	i = 0;
	check_zero(d, megacount);
	while (d != 0)
	{
		temp = 0;
		temp = d % 16;
		if (temp < 10)
			hex[i++] = temp + 48;
		else
			hex[i++] = temp + 87;
		d = d / 16;
	}
	i--;
	write_number(i, hex, megacount);
}
