/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharvoz <acharvoz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 00:31:48 by acharvoz          #+#    #+#             */
/*   Updated: 2024/06/11 00:36:47 by acharvoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_nbr(int nb)
{
	int	div;
	int	chiffre;

	div = 1;

	if (nb < 0)
	{
		ft_print_char('-');
		nb = -nb;
	}

	while (nb / div >= 10)
		div *= 10;

	while (div > 0)
	{
		chiffre = nb / div;
		ft_print_char(chiffre + '0');
		nb %= div;
		div /= 10;
	}
	return (0);
}
