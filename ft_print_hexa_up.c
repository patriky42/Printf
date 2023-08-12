/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_up.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:19:32 by pabastid          #+#    #+#             */
/*   Updated: 2022/10/22 12:19:02 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa_up(unsigned int hx, int counter)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (hx > 15)
	{
		counter = ft_print_hexa_up(hx / 16, counter);
		if (counter == -1)
			return (-1);
		if (write (1, &base[hx % 16], 1) == -1)
			return (-1);
		counter++;
	}
	else
	{
		if (ft_print_char(base[hx % 16]) == -1)
			return (-1);
		counter++;
	}
	return (counter);
}
