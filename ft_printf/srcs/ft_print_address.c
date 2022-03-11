/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:12:23 by jvalenci          #+#    #+#             */
/*   Updated: 2021/11/29 10:16:48 by jvalenci         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_basel(unsigned long long nbr, char *base, int counter)
{
	unsigned long long	lenbase;

	lenbase = ft_strlen(base);
	if (!ft_checkstr(base))
		return (0);
	if (nbr >= lenbase)
	{
		counter = ft_putnbr_basel((nbr / lenbase), base, counter);
		counter = ft_putnbr_basel((nbr % lenbase), base, counter);
	}
	else
	{
		write(1, base + nbr, 1);
		++counter;
	}
	return (counter);
}

int	ft_print_address(void *address)
{
	int			counter;
	long long	new_address;

	counter = 0;
	new_address = (long long)address;
	if (!address)
	{
		counter += ft_putstr("0x");
		counter += ft_putstr("0");
		return (counter);
	}
	counter += ft_putstr("0x");
	counter += ft_putnbr_basel(new_address, HEXA_LOW, 0);
	return (counter);
}
