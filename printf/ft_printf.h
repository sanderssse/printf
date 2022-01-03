/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharley <xcharley@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 14:52:04 by xcharley          #+#    #+#             */
/*   Updated: 2021/12/25 14:52:07 by xcharley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *c, ...);
void	c_s_p_d(char *s, va_list	ap, int *megacount);
void	i_u_x_upperx_percent(char *s, va_list	ap, int *megacount);
size_t	ft_strlen(const char *s);
void	print_number(int d, int *megacount);
void	print_unsigned_number(unsigned int d, int *megacount);
void	ft_putnbr_fd(int n, int fd);
void	print_upper_hex(unsigned int d, int *megacount);
void	print_hex(void *p, int *megacount);
void	print_lower_hex(unsigned int d, int *megacount);
void	print_number(int d, int *megacount);
void	print_unsigned_number(unsigned int d, int *megacount);
void	check_zero(unsigned long d, int *megacount);
void	write_number(int i, char *hex, int *megacount);

#endif