/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbehar <sbehar@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:28:29 by sbehar            #+#    #+#             */
/*   Updated: 2024/11/21 14:36:42 by sbehar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_format(char percent, va_list args)
{
	int	count;

	count = 0;
	if (percent == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (percent == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (percent == 'p')
		count += ft_isptrnull(va_arg(args, unsigned long));
	else if (percent == 'd' || percent == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (percent == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (percent == 'x')
		count += ft_putnbr_hex(va_arg(args, unsigned int), 0);
	else if (percent == 'X')
		count += ft_putnbr_hex(va_arg(args, unsigned int), 1);
	else if (percent == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_handle_format(*format, args);
		}
		else
		{
			count += ft_putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}

/*int	main()
{
	char *s;
	char str = "salut";
	int	nb;
	nb = ft_printf("%p\n", &str);
	ft_printf("%d", nb);
}*/
