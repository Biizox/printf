/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_prct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharvoz <acharvoz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 00:31:46 by acharvoz          #+#    #+#             */
/*   Updated: 2024/06/11 00:38:30 by acharvoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_prct(const char	*c)
{
	if (*c == '\0')
		return ;

	if (*c == '%' && *(c + 1) == '%')
	{
		ft_putchar('%');
		ft_print_prct(c + 2);
	}
	else
	{
		ft_putchar(*c);
		ft_print_prct(c + 1);
	}
}
