/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:15:25 by ehosta            #+#    #+#             */
/*   Updated: 2024/11/25 13:15:25 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	if (!str)
		return (ft_putstr_fd("(null)", 1));
	if (!*str)
		return (ft_putstr_fd("", 1));
	return (ft_putstr_fd(str, 1));
}
