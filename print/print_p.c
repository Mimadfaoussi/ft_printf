/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 11:15:11 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/01/02 10:11:33 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//counts the number of bytes we need to represent hex

static int	hextcount(unsigned long long nb)
{
	int	i;

	i = 0;
	while (nb > 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i + 1);
}
// will check if number is negative and prepare it 

static unsigned long long	checker(unsigned long long nb)
{
	if (nb < 0)
	{
		nb = UINT_MAX + nb;
	}
	return (nb);
}
// mode 1 for UPPERCASE
// else for lowercase

static char	*hex_converter(unsigned long long nb, int mode)
{
	char	*result;
	char	*alpha;
	int		i;

	nb = checker(nb);
	if (nb == 0)
		return (ft_strdup("0"));
	if (mode == 1)
		alpha = ft_strdup("0123456789ABCDEF");
	else
		alpha = ft_strdup("0123456789abcdef");
	result = malloc(sizeof(char) * hextcount(nb));
	if (!result)
		return (NULL);
	i = hextcount(nb) - 2;
	result[i + 1] = '\0';
	while (nb > 0)
	{
		result[i] = alpha[nb % 16];
		i--;
		nb = nb / 16;
	}
	free(alpha);
	return (result);
}

static void	hexwrite(unsigned long long nb, int mode, int *count)
{
	char	*hex;

	hex = hex_converter(nb, mode);
	ft_putstr_fd(hex, 1, count);
	free(hex);
}

void	print_p(unsigned long long address, int *count)
{
	ft_putstr_fd("0x", 1, count);
	hexwrite(address, 2, count);
}
