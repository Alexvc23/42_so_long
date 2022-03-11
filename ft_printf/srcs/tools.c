/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:14:29 by jvalenci          #+#    #+#             */
/*   Updated: 2022/03/11 15:27:49 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_strlen(char *s)
{
	unsigned int	counter;

	counter = 0;
	while (*s)
	{
		counter++;
		s++;
	}
	return (counter);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		write(1, &s[i++], 1);
		counter++;
	}
	return (counter);
}

int	ft_putnbr(int n, int count)
{
	long long	nb;

	nb = (long long)n;
	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
		count++;
	}
	if (nb >= 10)
	{
		count = ft_putnbr((nb / 10), count);
		count = ft_putnbr((nb % 10), count);
	}
	else
	{
		ft_putchar(nb + '0');
		++count;
	}
	return (count);
}

int	ft_unsigned_putnbr(unsigned int n, int count)
{
	if (n >= 10)
	{
		count = ft_unsigned_putnbr((n / 10), count);
		count = ft_unsigned_putnbr((n % 10), count);
	}
	else
	{
		ft_putchar(n + '0');
		++count;
	}
	return (count);
}
