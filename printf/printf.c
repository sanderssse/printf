/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharley <xcharley@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:15:28 by xcharley          #+#    #+#             */
/*   Updated: 2021/12/25 14:53:39 by xcharley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(char c, int *megacount)
{
	write(1, &c, 1);
	(*megacount)++;
}

void	print_str(char *s, int *megacount)
{
	if (s == 0)
	{
		write(1, "(null)", 6);
		(*megacount) += 6;
		return ;
	}
	while (*s != '\0')
	{
		print_char(*s, megacount);
		s++;
	}
}

void	i_u_x_upperx_percent(char *s, va_list	ap, int *megacount)
{
	unsigned int		d;

	if (*s == 'i' || *s == 'u' || *s == 'x' || *s == 'X')
		d = va_arg(ap, int);
	if (*s == 'i')
		print_number(d, megacount);
	if (*s == 'u')
		print_unsigned_number(d, megacount);
	if (*s == 'x')
		print_lower_hex(d, megacount);
	if (*s == 'X')
		print_upper_hex(d, megacount);
	if (*s == '%')
	{
		write(1, "%", 1);
		(*megacount)++;
	}
}

void	c_s_p_d(char *s, va_list	ap, int *megacount)
{
	char	*str;
	char	c;
	int		d;
	void	*p;

	if (*s == 'c')
	{
		c = va_arg(ap, int);
		print_char(c, megacount);
	}
	if (*s == 's')
	{
		str = va_arg(ap, char *);
		print_str(str, megacount);
	}
	if (*s == 'p')
	{
		p = va_arg(ap, void *);
		print_hex(p, megacount);
	}
	if (*s == 'd')
	{
		d = va_arg(ap, int);
		print_number(d, megacount);
	}
}

int	ft_printf(const char *s, ...)
{
	int		megacount;
	char	*s2;
	va_list	ap;

	megacount = 0;
	s2 = (char *)s;
	va_start(ap, s);
	while (*s2)
	{
		while (*s2 && *s2 != '%')
		{
			write(1, s2, 1);
			megacount++;
			s2++;
		}
		if (*s2 == '\0')
			break ;
		s2++;
		c_s_p_d(s2, ap, &megacount);
		i_u_x_upperx_percent(s2, ap, &megacount);
		s2++;
	}
	va_end(ap);
	return (megacount);
}
