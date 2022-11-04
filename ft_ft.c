/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahbibe <bahbibe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 22:52:51 by bahbibe           #+#    #+#             */
/*   Updated: 2022/11/04 08:02:46 by bahbibe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *ret)
{
	write(1, &c, 1);
	(*ret)++;
}

void	ft_putstr(char *s, int *ret)
{
	int	i;

	if (!s)
		ft_putstr("(null)", ret);
	else
	{
		i = 0;
		while (s[i] != '\0')
			ft_putchar(s[i++], ret);
	}
}

void	ft_putnbr(int n, int *ret)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", ret);
	}
	else if (n < 0)
	{
		ft_putchar('-', ret);
		ft_putnbr(-n, ret);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10, ret);
		ft_putnbr(n % 10, ret);
	}
	else if (n <= 9)
	{
		ft_putchar(n + '0', ret);
	}
}

void	ft_unsigned(unsigned int nb, int *ret)
{
	if (nb > 9)
	{
		ft_unsigned(nb / 10, ret);
		ft_unsigned(nb % 10, ret);
	}
	else
		ft_putchar(nb + '0', ret);
}

void	ft_hex(unsigned int nb, char chr, int *ret)
{
	unsigned int	n;
	char			*hex_base;

	n = nb;
	if (chr == 'x')
	hex_base = "0123456789abcdef";
	else
	hex_base = "0123456789ABCDEF";
	if (n < 16)
		ft_putchar(hex_base[n % 16], ret);
	else
	{
		ft_hex(n / 16, chr, ret);
		ft_hex(n % 16, chr, ret);
	}
}
