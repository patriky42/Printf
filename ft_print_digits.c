/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:47:13 by pabastid          #+#    #+#             */
/*   Updated: 2022/10/22 13:37:43 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	n_min(void)
{
	if (write(1, "-2147483648", 11) != 11)
		return (-1);
	return (11);
}

int	putnbr(int n, int *i)
{
	char	c;

	c = '0' + n;
	if (write(1, &c, 1) == -1)
		return (-1);
	*i = *i + 1;
	return (1);
}

int	ft_print_digits(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (n_min());
	if (n < 0)
	{
		if (write(1, "-", 1) < 0)
			return (-1);
		n = -n;
		i++;
	}
	if (n > 9)
	{
		i += ft_print_digits(n / 10);
		if (i == -1)
			return (-1);
		n = n % 10;
	}
	if (n <= 9)
	{
		if (putnbr(n, &i) == -1)
			return (-1);
	}
	return (i);
}
