/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahbibe <bahbibe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:39:06 by bahbibe           #+#    #+#             */
/*   Updated: 2022/11/04 08:27:06 by bahbibe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

void	ft_putchar(char c, int *ret);
void	ft_putstr(char *s, int *ret);
void	ft_putnbr(int n, int *ret);
void	ft_unsigned(unsigned int nb, int *ret);
void	ft_hex(unsigned int nb, char chr, int *ret);
void	ft_pointer(const void *nb, int *ret);
int		ft_printf(const char *str, ...);

#endif
