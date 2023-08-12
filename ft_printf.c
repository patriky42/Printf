/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:43:55 by pabastid          #+#    #+#             */
/*   Updated: 2022/10/22 13:37:42 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_value(const char c, va_list arguments)
{
	if (c == 'c')
		return (ft_print_char(va_arg(arguments, int)));
	if (c == 's')
		return (ft_print_str(va_arg(arguments, char *)));
	if (c == 'p')
		return (ft_print_pointers(va_arg(arguments, void *)));
	if (c == 'i' || c == 'd')
		return (ft_print_digits(va_arg(arguments, int)));
	if (c == 'u')
		return (ft_print_unsigned(va_arg(arguments, unsigned int)));
	if (c == 'x')
		return (ft_print_hexa_low(va_arg(arguments, long int), 0));
	if (c == 'X')
		return (ft_print_hexa_up(va_arg(arguments, long int), 0));
	if (c == '%')
		return (ft_print_char('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		characters;
	int		i;

	characters = 0;
	i = -1;
	va_start(arguments, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			i++;
			characters += ft_value((char)format[i], arguments);
			if (characters == -1)
				return (-1);
		}
		else
		{	
			characters += ft_print_char(format[i]);
			if (characters == -1)
				return (-1);
		}
	}
	va_end(arguments);
	return (characters);
}
