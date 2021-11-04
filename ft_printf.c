/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:18:43 by mbarylak          #+#    #+#             */
/*   Updated: 2021/11/04 20:48:58 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	do_ur_thing(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_ptohex(va_arg(args, void *)));
	else if (c == 'i' || c == 'd')
		return (ft_putstr2(ft_itoa(va_arg(args, int))));
	else if (c == 'u')
		return (ft_putstr2(ft_utoa(va_arg(args, unsigned int))));
	else if (c == 'x')
		return (ft_putstr2(ft_itohex(va_arg(args, unsigned int), \
						"0123456789abcdef")));
	else if (c == 'X')
		return (ft_putstr2(ft_itohex(va_arg(args, unsigned int), \
						"0123456789ABCDEF")));
	else if (c == '%')
		return (ft_putchar('%'));
	return (write(1, &c, 1));
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			count += do_ur_thing(s[i + 1], args);
			i = i + 2;
		}
		else
		{
			write(1, &s[i], 1);
			i++;
			count++;
		}
	}
	va_end(args);
	return (count);
}
