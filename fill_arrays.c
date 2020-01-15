/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_arrays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktimika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:08:24 by ktimika           #+#    #+#             */
/*   Updated: 2019/10/13 16:08:26 by ktimika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_arr_bzero(t_uint arr[], t_uint size)
{
	t_uint	i;

	i = 0;
	while (i < size)
		arr[i++] = 0;
}

void	fill_integ_array(t_uint integ[], t_ulong mantis)
{
	t_uint	i;

	i = 0;
	fill_arr_bzero(integ, SIZE);
	while (mantis)
	{
		integ[i] = mantis % BASE;
		mantis /= BASE;
		i++;
	}
}

void	fill_arr_500(t_uint tmp_arr[])
{
	fill_arr_bzero(tmp_arr, SIZE - 1);
	tmp_arr[SIZE - 1] = 500000000;
}

void	fill_fractional_part(t_uint fract[], t_uint tmp_arr[],
								t_ulong mantis)
{
	t_uint	i;

	i = 0;
	while (i < 64)
	{
		if (mantis & (1ul << (63u - i)))
			long_arithmetic_sum(fract, tmp_arr);
		long_arithmetic_divs(tmp_arr, 2);
		i++;
	}
}
