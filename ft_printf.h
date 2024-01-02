/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 08:11:32 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/01/02 10:14:36 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <ctype.h>
# include <unistd.h>
# include <limits.h>

int				ft_printf(const char *format, ...);
size_t			ft_strlen(const char *s);
void			ft_putchar_fd(char c, int fd, int *count);
void			ft_putstr_fd(char *s, int fd, int *count);
void			ft_putnbr_fd(long n, int fd, int *count);
void			print_d(int n, int fd, int *count);
void			print_u(unsigned int nb, int *c);
void			print_p(unsigned long long address, int *count);
char			*ft_strdup(const char *str);
void			print_x(unsigned int nb, int mode, int *count);

#endif