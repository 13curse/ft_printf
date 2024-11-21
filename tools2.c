/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbehar <sbehar@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:06:25 by sbehar            #+#    #+#             */
/*   Updated: 2024/11/21 15:08:09 by sbehar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_ptr(unsigned long p)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789abcdef";
	if (p >= 16)
	{
		count += ft_putnbr_ptr(p / 16);
	}
	count += write(1, &hex[p % 16], 1);
	return (count);
}

int	ft_isptrnull(unsigned long p)
{
	int	count;

	count = 0;
	if (p == 0)
		count += write(1, "(nil)", 5);
	else
	{
		count += write(1, "0x", 2);
		return (count + ft_putnbr_ptr(p));
	}
	return (count);
}
