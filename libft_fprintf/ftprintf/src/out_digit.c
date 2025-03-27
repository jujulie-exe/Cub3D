/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_digit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:23:05 by jfranco           #+#    #+#             */
/*   Updated: 2025/03/21 17:01:22 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

int	out_digit(const int fd, int n)
{
	int		count;

	count = 0;
	if (n == INT_MIN)
		return (write(fd, "-2147483648", 11));
	if (n == INT_MAX)
		return (write(fd, "2147483647", 10));
	if (n < 0)
	{
		count += out_char(fd, '-');
		n = -n;
	}
	if (n < 10)
		count += out_char(fd, n + '0');
	else
	{
		count += out_digit(fd, n / 10);
		count += out_char(fd, n % 10 + '0');
	}
	return (count);
}

int	out_hex(const int fd, unsigned long long n)
{
	int long	count;
	char		*symb;
	int	add;

	symb = "0123456789abcdef";
	count = 0;
	if (n < 16)
	{
		add = write(fd, &symb[n], 1);
		if (add == -1)
			return (-1);
		count +=  add;
	}
	else
	{
		count += out_hex(fd, n / 16);
		count += write(fd, &symb[n % 16], 1);
	}
	return (count);
}

int	out_hexdigit_upper_case(const int fd, unsigned int n)
{
	int long		count;
	char			*symb;

	symb = "0123456789ABCDEF";
	count = 0;
	if (n < 16)
		count += write(fd, &symb[n], 1);
	else
	{
		count += out_hexdigit_upper_case(fd, n / 16);
		count += write(fd, &symb[n % 16], 1);
	}
	return (count);
}

int	out_digit_unsigned(const int fd, unsigned int n)
{
	int		count;

	count = 0;
	if (n < 10)
		count += out_char(fd, n + '0');
	else
	{
		count += out_digit_unsigned(fd, n / 10);
		count += out_char(fd,n % 10 + '0');
	}
	return (count);
}
