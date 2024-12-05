/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouannh <elouannh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:17:18 by elouannh          #+#    #+#             */
/*   Updated: 2024/11/23 12:17:18 by elouannh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_flag(char flg, va_list args)
{
	int		i;

	i = 0;
	if (!flg)
		return (i);
	else if (flg == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (flg == '%')
		return (ft_putchar_fd('%', 1));
	else if (flg == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (flg == 'd' || flg == 'i')
		ft_print_nbr(0, (long long)va_arg(args, int), &i);
	else if (flg == 'u')
		ft_print_nbr(0, (unsigned int)va_arg(args, unsigned int), &i);
	else if (flg == 'x')
		ft_print_nbr(1, (unsigned int)va_arg(args, unsigned int), &i);
	else if (flg == 'X')
		ft_print_nbr(2, (unsigned int)va_arg(args, unsigned int), &i);
	else if (flg == 'p')
		ft_print_ptr((unsigned long long)va_arg(args, void *), &i);
	return (i);
}

int	ft_parsefmt(char *str, va_list args)
{
	int	prtd;
	int	i;

	prtd = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			prtd += ft_format_flag(str[i + 1], args);
			i += 2;
			continue ;
		}
		ft_putchar_fd(str[i], 1);
		i++;
		prtd++;
	}
	return (prtd);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	if (!format || !*format)
		return (-1);
	len = 0;
	va_start(args, format);
	len = ft_parsefmt((char *)format, args);
	va_end(args);
	return (len);
}
