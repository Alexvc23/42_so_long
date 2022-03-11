/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 10:02:43 by jvalenci          #+#    #+#             */
/*   Updated: 2022/03/11 15:29:13 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_checkstr(char *s)
{
	char	*str;
	int		iter;

	str = s;
	iter = 0;
	if (*s == 0 || *(s + 1) == 0)
		return (0);
	while (*str)
	{
		if (*str == '+' || *str == '-')
			return (0);
		iter = 1;
		while (*(str + iter))
		{
			if (*(str + iter) == *str)
				return (0);
			iter++;
		}
		str++;
	}
	return (1);
}

int	ft_putnbr_base(unsigned int nbr, char *base, int counter)
{
	unsigned int	lenbase;
	unsigned int	br;

	br = nbr;
	lenbase = ft_strlen(base);
	if (!ft_checkstr(base))
		return (0);
	if (br >= lenbase)
	{
		counter = ft_putnbr_base((br / lenbase), base, counter);
		counter = ft_putnbr_base((br % lenbase), base, counter);
	}
	else
	{
		write(1, base + br, 1);
		++counter;
	}
	return (counter);
}
/*int	main()
  {
  write(1, "42:", 3);
  ft_putnbr_base(0, "0123456789");
  write(1, "\n2a:", 4);
  ft_putnbr_base(600, "0123456789abcdef");
  write(1, "\n-2a:", 5);
  ft_putnbr_base(-42, "0123456789abcdef");
  write(1, "\n:", 2);
  ft_putnbr_base(42, "");
  write(1, "\n:", 2);
  ft_putnbr_base(42, "0");
  write(1, "\n:", 2);
  ft_putnbr_base(42, "+-0123456789abcdef");
  write(1, "\n:", 2);
  }
  */
