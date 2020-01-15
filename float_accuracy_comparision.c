/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_accuracy_comparision.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktimika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 12:18:33 by ktimika           #+#    #+#             */
/*   Updated: 2019/10/15 12:18:46 by ktimika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_uint			ten_in_pow(t_uint pow)
{
	t_uint	res;

	res = 1;
	while (pow)
	{
		res *= 10;
		pow--;
	}
	return (res);
}

static t_uint	get_number_digit(t_uint arr[], int acc)
{
	t_uint	nb;
	t_uint	i;
	t_uint	n;

	i = (SIZE * NLEN - acc) / NLEN;
	n = (SIZE * NLEN - acc) % NLEN;
	nb = arr[i] % ten_in_pow(n + 1) / ten_in_pow(n);
	return (nb);
}

static void		fill_tmp_arr(t_uint tmp_arr[], int acc)
{
	t_uint	i;
	t_uint	n;

	i = (SIZE * NLEN - acc) / NLEN;
	n = (SIZE * NLEN - acc) % NLEN;
	fill_arr_bzero(tmp_arr, SIZE);
	tmp_arr[i] = ten_in_pow(n);
}

static void		rounding_integ(t_uint integ[], t_uint fract[], int acc)
{
	t_uint	dig_cnt;
	t_uint	fract_nb;
	t_uint	integ_nb;

	dig_cnt = digit_count(fract[SIZE - 1], 10);
	fract_nb = get_number_digit(fract, 1);
	integ_nb = get_number_digit(integ, SIZE * NLEN);
	if (dig_cnt > NLEN || (acc == 0 && (fract_nb > 5 ||
		(fract_nb == 5 && integ_nb % 2 == 1))))
	{
		fract[SIZE - 1] = 0;
		long_arithmetic_sums(integ, 1);
	}
}

void			float_rounding(t_uint integ[], t_uint fract[], int accuracy)
{
	int		acc;
	t_uint	tmp_arr[SIZE];
	t_uint	tmp_nb;
	t_uint	nb;

	acc = accuracy == -1 ? 6 : accuracy;
	tmp_nb = get_number_digit(fract, acc + 1);
	if (acc > 0)
		nb = get_number_digit(fract, acc);
	else
		nb = get_number_digit(integ, SIZE * NLEN);
	if (tmp_nb > 5 || (tmp_nb == 5 && nb % 2 == 1) ||
		is_more_num_dig(fract, 5, acc + 1))
	{
		fill_tmp_arr(tmp_arr, acc);
		long_arithmetic_sum(fract, tmp_arr);
		rounding_integ(integ, fract, acc);
	}
}
