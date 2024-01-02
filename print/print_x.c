/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 08:57:42 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/01/02 10:13:31 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//counts the number of bytes we need to represent hex

static int	hextcount(unsigned int nb)
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

static unsigned int	checker(unsigned int nb)
{
	if (nb < 0)
	{
		nb = UINT_MAX + nb;
	}
	return (nb);
}
// mode 1 for UPPERCASE
// else for lowercase

static char	*hex_converter(unsigned int nb, int mode)
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

void	print_x(unsigned int nb, int mode, int *count)
{
	char	*hex;

	hex = hex_converter(nb, mode);
	ft_putstr_fd(hex, 1, count);
	free(hex);
}
