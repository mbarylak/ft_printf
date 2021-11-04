/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:17:11 by mbarylak          #+#    #+#             */
/*   Updated: 2021/11/04 20:46:42 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

static int	digit_counter(int n)
{
	unsigned int	nbr;
	int				dig_count;

	dig_count = 1;
	if (n < 0)
	{
		nbr = n * -1;
		dig_count++;
	}
	else
		nbr = n;
	while (nbr >= 10)
	{
		nbr = nbr / 10;
		dig_count++;
	}
	return (dig_count);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	char			*num;
	int				dig_count;

	dig_count = digit_counter(n);
	num = (char *) malloc((dig_count + 1) * sizeof (char));
	if (!num)
		return (NULL);
	if (n < 0)
	{
		nbr = n * -1;
		num[0] = '-';
	}
	else
		nbr = n;
	if (nbr == 0)
		num[0] = '0';
	num[dig_count] = '\0';
	while (nbr > 0)
	{
		dig_count--;
		num[dig_count] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (num);
}

char	*ft_utoa(unsigned int n)
{
	unsigned int	nbr;
	char			*num;
	unsigned int	dig_count;

	dig_count = 1;
	nbr = n;
	while (nbr >= 10)
	{
		nbr = nbr / 10;
		dig_count++;
	}
	num = (char *) malloc((dig_count + 1) * sizeof (char));
	if (!num)
		return (NULL);
	if (n == 0)
		num[0] = '0';
	num[dig_count] = '\0';
	while (n > 0)
	{
		dig_count--;
		num[dig_count] = (n % 10) + '0';
		n = n / 10;
	}
	return (num);
}
