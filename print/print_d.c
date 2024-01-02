/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:49:22 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/01/02 10:24:59 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	negative(int *count, int fd)
{
	ft_putstr_fd("-2147483648", fd, count);
}

void	print_d(int n, int fd, int *count)
{
	char	c;

	if (n == -2147483648)
	{
		negative(count, fd);
		return ;
	}
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd, count);
			n = -n;
			print_d(n, fd, count);
			count++;
		}
		else if (n >= 10)
		{
			c = (n % 10) + '0';
			print_d(n / 10, fd, count);
			ft_putchar_fd(c, fd, count);
		}
		else if (n < 10)
			ft_putchar_fd(n + '0', fd, count);
	}
}
