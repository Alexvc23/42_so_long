/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:45:20 by jvalenci          #+#    #+#             */
/*   Updated: 2022/01/06 16:27:12 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 *va_start
 enables access to variadic function arguments
 (function macro)
 *va_arg
 accesses the next variadic function argument
 (function macro)
 *va_copy
 makes a copy of the variadic function arguments
 (function macro)
 *va_end
 ends traversal of the variadic function arguments
 (function macro)
 *va_list
 holds the information needed by va_start, va_arg, va_end, and va_copy
 (typedef varible)
*/
/* char	ft_check_input(const char *s)
{
 
	char	conv[10];
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_strcpy(conv, "cspdiuxX%");
	while (s[i])
	{
		j = 0;
		while (conv[j])
		{
			if (s[i] == conv[j])
				return (conv[j]);
			j++;
		}
		i++;
	}
	return (0);
} */

int	ft_funcheck(va_list list, char c)
{
	int	counter;

	counter = 0;
	if (c == 's')
		counter += ft_putstr(va_arg(list, char *));
	if (c == 'c')
		counter += ft_putchar(va_arg(list, int));
	if (c == 'i' || c == 'd')
		counter += ft_putnbr(va_arg(list, int), 0);
	if (c == 'x')
		counter += ft_putnbr_base(va_arg(list, int), HEXA_LOW, 0);
	if (c == 'X')
		counter += ft_putnbr_base(va_arg(list, int), HEXA_UP, 0);
	if (c == 'p')
		counter += ft_print_address(va_arg(list, void *));
	if (c == 'u')
		counter += ft_unsigned_putnbr(va_arg(list, int), 0);
	if (c == '%')
		counter += ft_putchar('%');
	return (counter);
}

int	ft_printf(const char *s, ...)
{
	va_list	list;
	int		counter;

	counter = 0;
	va_start(list, s);
	while (*s)
	{
		if (*s == '%' && ft_strchr("cspdiuxX%", *(s + 1)))
		{
			counter += ft_funcheck(list, *(s + 1));
			s += 2;
			continue ;
		}
		write(1, s, 1);
		s++;
		counter++;
	}
	va_end(list);
	return (counter);
}