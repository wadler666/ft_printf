/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahbibe <bahbibe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:37:44 by bahbibe           #+#    #+#             */
/*   Updated: 2022/11/04 09:36:10 by bahbibe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_formats(va_list args, const char c, int *ret)
{
	if (c == '%')
		ft_putchar('%', ret);
	else if (c == 'c')
		ft_putchar(va_arg(args, int), ret);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), ret);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), ret);
	else if (c == 'x' || c == 'X')
		ft_hex(va_arg(args, unsigned int), c, ret);
	else if (c == 'p')
		ft_pointer(va_arg(args, const void *), ret);
	else if (c == 'u')
		ft_unsigned(va_arg(args, unsigned int), ret);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		ret ;

	va_start(args, str);
	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_formats(args, str[i], &ret);
		}
		else
			ft_putchar(str[i], &ret);
		i++;
	}
	va_end(args);
	return (ret);
}
