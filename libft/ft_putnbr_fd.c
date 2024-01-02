/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:49:22 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:06 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnbr_fd(long n, int fd, int *count)
{
	char	c;

	if (n < 0)
	{
		ft_putchar_fd('-', fd, count);
		n = -n;
		ft_putnbr_fd(n, fd, count);
		*count = *count + 1;
	}
	else if (n >= 10)
	{
		c = (n % 10) + '0';
		ft_putnbr_fd(n / 10, fd, count);
		ft_putchar_fd(c, fd, count);
	}
	else if (n < 10)
		ft_putchar_fd(n + '0', fd, count);
}
