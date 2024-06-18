/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharvoz <acharvoz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 00:31:36 by acharvoz          #+#    #+#             */
/*   Updated: 2024/06/11 00:29:55 by acharvoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_check_format(char type, va_list args)
{
	int	count;
	
	count = 0;
	if (type == '%')
		return (ft_print_prct('%'));
	else if (type == 'd' || type == 'i')
		count += ft_print_nbr(va_args(args, int));
	else if (type == 's')
		count += ft_print_str(va_args(args, char *));
	else if (type == 'c')
		count += ft_print_char(va_args(args, int));
	else if (type == 'u')
		count += ft_print_unsigned(va_args(args, unsigned int));
	else if (type == 'x' || type == 'X')
		count += ft_print_exa(va_args(args, unsigned int), type);
	else if (type == 'p')
		count += ft_print_ptr(va_args(args, unsigned long long int));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list args;
	int	i;
	int	count;
	
	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i])
		{
			i++;
			count += ft_check_format(format[i], args);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}