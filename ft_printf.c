/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 08:10:42 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/01/02 10:14:06 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	format_specifier(const char *format, int *i, va_list *list, int *c)
{
	if (format[*i] == '%' && (format[*i + 1] == 'd' || format[*i + 1] == 'i' ))
		print_d(va_arg(*list, int), 1, c);
	else if (format[*i] == '%' && format[*i + 1] == 'u')
		print_u(va_arg(*list, long), c);
	else if (format[*i] == '%' && format[*i + 1] == 'p')
		print_p(va_arg(*list, unsigned long long), c);
	else if (format[*i] == '%' && format[*i + 1] == 's')
		ft_putstr_fd(va_arg(*list, char *), 1, c);
	else if (format[*i] == '%' && format[*i + 1] == 'c')
		ft_putchar_fd(va_arg(*list, int), 1, c);
	else if (format[*i] == '%' && format[*i + 1] == 'X')
		print_x(va_arg(*list, unsigned long long), 1, c);
	else if (format[*i] == '%' && format[*i + 1] == 'x')
		print_x(va_arg(*list, unsigned long long), 2, c);
	else if (format[*i] == '%' && format[*i + 1] == '%')
		ft_putchar_fd('%', 1, c);
	else
	{
		*i = *i + 1;
		return ;
	}
	*i = *i + 2;
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(list, format);
	while (format[i])
	{
		if (format[i] == '%')
			format_specifier(format, &i, &list, &count);
		else
		{
			ft_putchar_fd(format[i], 1, &count);
			i++;
		}
	}
	va_end(list);
	return (count);
}
