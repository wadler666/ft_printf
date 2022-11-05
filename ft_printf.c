/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahbibe <bahbibe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:37:44 by bahbibe           #+#    #+#             */
/*   Updated: 2022/11/05 04:44:49 by bahbibe          ###   ########.fr       */
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
			if (str[i] == '\0')
				continue ;
			ft_formats(args, str[i], &ret);
		}
		else
			ft_putchar(str[i], &ret);
		i++;
	}
	va_end(args);
	return (ret);
}
int	main()
{
	int	n = 20;
	int	*p = &n;
	char	*s = "%%\nMy name is: %s(%c)\nI'm %d or %i\nor in hex %x/%X\nthe pointer to it is %p\nthe unsigned %u\n";
	int	fttotal = ft_printf(s, "Bob", 'M', n, n, n + 43, n + 43, p, 4294967295);
	ft_printf("\n");
	int	systotal = printf(s, "Bob", 'M', n, n, n + 43, n + 43, p, 4294967295);
	ft_printf("\n");
	printf("Total sys printf: %d, total ft_printf: %d\n", systotal, fttotal);
	
	s = "%%x with -1[%x]\n";
	int n1 = ft_printf(s, -1);
	int n2 = printf(s, -1);
	printf("ft_printf: [%d] | printf: [%d]\n", n1, n2);

	return 0;
}