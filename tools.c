/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbehar <sbehar@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:26:56 by sbehar            #+#    #+#             */
/*   Updated: 2024/11/21 12:10:45 by sbehar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_putstr(char *s)
{
	if (s)
	{
		while (*s)
		{
			write(1, s, 1);
			s++;
		}
	}
}

int		ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int		ft_putnbr_hex(unsigned int n, int uppercase)
{
	char	*hex_lower;
	char	*hex_upper;
	char	*hex;

	hex_lower = "0123456789abcdef";
	hex_upper = "0123456789ABCDEF";
	if (uppercase)
		hex = hex_upper;
	else
		hex = hex_lower;
	if (n >= 16)
		ft_puthex(n / 16, uppercase);
	write(1, &hex[n % 16], 1);
}

int		ft_putnbr_unsigned(unsigned int n)
{
	char	c;

	if (n >= 10)
		ft_putnbr_unsigned(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}
