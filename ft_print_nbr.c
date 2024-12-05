/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:08:13 by ehosta            #+#    #+#             */
/*   Updated: 2024/12/05 17:08:13 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_nbr(int base_id, long double value, int *prtd)
{
	if (base_id == 0)
		ft_print_nbrbase(value, "0123456789", prtd);
	else if (base_id == 1)
		ft_print_nbrbase(value, "0123456789abcdef", prtd);
	else if (base_id == 2)
		ft_print_nbrbase(value, "0123456789ABCDEF", prtd);
}
