/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:46:46 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/01/02 10:07:32 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_null(char *s, int fd, int *count)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd, count);
		i++;
	}
}

void	ft_putstr_fd(char *s, int fd, int *count)
{
	int	i;

	i = 0;
	if (s == NULL)
		print_null("(null)", fd, count);
	else
	{
		while (s[i] != '\0')
		{
			ft_putchar_fd(s[i], fd, count);
			i++;
		}
	}
}
