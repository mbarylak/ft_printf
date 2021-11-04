/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:18:58 by mbarylak          #+#    #+#             */
/*   Updated: 2021/11/04 20:49:01 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itohex(unsigned long int n, char *base)
{
	unsigned long int	nbr;
	char				*num;
	int					dig_count;

	dig_count = 1;
	nbr = n;
	while (nbr >= 16)
	{
		nbr = nbr / 16;
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
		num[dig_count] = base[n % 16];
		n = n / 16;
	}
	return (num);
}

int	ft_ptohex(void *ptr)
{
	unsigned long int	nptr;
	int					i;
	char				*num;
	int					count;

	i = 0;
	nptr = (unsigned long int) ptr;
	num = ft_itohex(nptr, "0123456789abcdef");
	write(1, "0x", 2);
	count = 2;
	while (num[i])
	{
		write(1, &num[i], 1);
		i++;
		count++;
	}
	free(num);
	return (count);
}


int	ft_putstr2(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
		write(1, &s[i++], 1);
	if (*s)
		free(s);
	return (i);
}
