/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:18:12 by jfranco           #+#    #+#             */
/*   Updated: 2025/03/21 17:02:22 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fprintf.h"
#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	out_str(const int fd, char *s)
{
	int	len;

	len = 0;
	if (s == NULL)
	{
		return (write(fd, "(null)", 6));
	}
	while (s[len] != '\0')
	{
		out_char(fd,(int)s[len]);
		len++;
	}
	return (len);
}

int	check_format(const int fd, char s, va_list ap)
{
	int	len;

	len = 0;
	if (s == '\0')
		return (-1);
	else if (s == 'c')
		len += out_char(fd, va_arg(ap, int));
	else if (s == 's')
		len += out_str(fd, va_arg(ap, char *));
	else if (s == 'd' || s == 'i')
		len += out_digit(fd, va_arg(ap, int));
	else if (s == 'x')
		len += out_hex(fd, va_arg(ap, unsigned int));
	else if (s == 'X')
		len += out_hexdigit_upper_case(fd, va_arg(ap, unsigned int));
	else if (s == 'u')
		len += out_digit_unsigned(fd, va_arg(ap, unsigned int));
	else if (s == 'p')
		len += print_ad(fd, va_arg(ap, void *));
	else if (s == '%')
		len += write(fd, &s, 1);
	return (len);
}

int	ft_fprintf(const int fd, const char *frmt, ...)
{
	int long		len;
	int long		result;
	va_list			ap;

	va_start(ap, frmt);
	len = 0;
	if (fd < 0 || write(fd, "", 0) < 0)
		return (-1);
	if (frmt == NULL)
		return (-1);
	while (*frmt != '\0')
	{
		if (*frmt == '%')
		{
			result = check_format(fd, *(++frmt), ap);
			if (result < 0)
				return (-1);
			len += result;
		}
		else
		{
			result = write(1, frmt, 1);
			if (result == -1)
				return (-1);
			len += result;
		}
		frmt++;
	}
	va_end(ap);
	return (len);
}
