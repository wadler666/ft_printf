/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahbibe <bahbibe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 04:48:44 by bahbibe           #+#    #+#             */
/*   Updated: 2022/11/04 08:04:25 by bahbibe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_phex(unsigned long nb, int *ret)
{
	char	*hex_base;

	hex_base = "0123456789abcdef";
	if (nb < 16)
		ft_putchar(hex_base[nb % 16], ret);
	else
	{
		ft_phex(nb / 16, ret);
		ft_phex(nb % 16, ret);
	}
}

void	ft_pointer(const void *p, int *ret)
{
	unsigned long	ptr;

	ptr = (unsigned long )p;
	ft_putstr("0x", ret);
	ft_phex(ptr, ret);
}
