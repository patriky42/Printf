/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:14:18 by pabastid          #+#    #+#             */
/*   Updated: 2022/10/22 12:27:32 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_print_char(int c);
int	ft_print_digits(int n);
int	ft_print_str(char *str);
int	ft_print_hexa_low(unsigned int hx, int counter);
int	ft_print_hexa_up(unsigned int hx, int counter);
int	ft_print_pointers(void *ptr);
int	ft_print_unsigned(unsigned int n);
int	ft_printf(const char *format, ...);

#endif
