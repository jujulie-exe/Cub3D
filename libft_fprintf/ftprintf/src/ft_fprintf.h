/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:15:43 by jfranco           #+#    #+#             */
/*   Updated: 2025/03/21 16:51:14 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FPRINTF_H
# define FT_FPRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>

int	ft_fprintf(const int fd, const char *frmt, ...);
int	out_digit(const int fd, int n);
int	out_char(const int fd, int c);
int	out_hex(const int fd, unsigned long long n);
int	out_digit_unsigned(const int fd,unsigned int n);
int	out_hexdigit_upper_case(const int fd, unsigned int n);
int	print_ad(const int fd, void *ptr);

#endif
