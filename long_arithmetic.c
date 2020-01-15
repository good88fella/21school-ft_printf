/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_arithmetic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktimika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 14:43:35 by ktimika           #+#    #+#             */
/*   Updated: 2019/10/13 14:43:37 by ktimika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	long_arithmetic_sum(t_uint dest[], t_uint src[])
{
	t_uint	i;
	t_uint	tmp;

	i = 0;
	tmp = 0;
	while (i < SIZE)
	{
		tmp += dest[i] + src[i];
		if (i != SIZE - 1)
			dest[i] = tmp % BASE;
		else
			dest[i] = tmp;
		tmp /= BASE;
		i++;
	}
}

void	long_arithmetic_sums(t_uint dest[], t_uint nb)
{
	t_uint	i;
	t_uint	tmp;

	i = 0;
	tmp = 0;
	while (i < SIZE)
	{
		tmp += dest[i] + nb;
		nb = 0;
		dest[i] = tmp % BASE;
		tmp /= BASE;
		i++;
	}
}

void	long_arithmetic_divs(t_uint dest[], t_uint num)
{
	int		i;
	t_uint	tmp;

	i = SIZE - 1;
	tmp = 0;
	while (i >= 0)
	{
		tmp = tmp * BASE + dest[i];
		dest[i] = tmp / num;
		tmp = tmp % num;
		i--;
	}
}

int		is_more_num_dig(t_uint arr[], t_uint num, int acc)
{
	t_uint	num_arr[SIZE];
	t_uint	tmp_arr[SIZE];
	int		i;
	t_uint	n;

	i = (SIZE * NLEN - acc) / NLEN;
	n = (SIZE * NLEN - acc) % NLEN;
	fill_arr_bzero(num_arr, SIZE);
	fill_arr_bzero(tmp_arr, SIZE);
	num_arr[i] = num * ten_in_pow(n);
	tmp_arr[i] = arr[i] % (ten_in_pow(n) * 10);
	while (i >= 0)
	{
		if (tmp_arr[i] > num_arr[i])
			return (1);
		else if (tmp_arr[i] < num_arr[i])
			return (0);
		i--;
		if (i >= 0)
			tmp_arr[i] = arr[i];
	}
	return (0);
}
