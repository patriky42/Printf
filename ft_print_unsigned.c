/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:32:35 by pabastid          #+#    #+#             */
/*   Updated: 2022/10/21 17:40:29 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	int	counter;

	counter = 0;
	if (n > 9)
	{
		counter = ft_print_unsigned(n / 10);
		if (counter == -1)
			return (-1);
		n = n % 10;
	}
	if (n <= 9)
	{
		if (ft_print_char((n + '0')) == -1)
			return (-1);
		counter++;
	}
	return (counter);
}
