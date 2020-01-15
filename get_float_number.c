/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_float_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktimika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 14:41:30 by ktimika           #+#    #+#             */
/*   Updated: 2019/10/13 14:41:32 by ktimika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	get_integer_part(t_uint integ[], t_ulong mantissa, int exp)
{
	t_ulong	mantis;

	mantis = mantissa;
	if (exp <= 0)
		mantis = 0;
	else if (exp > 0 && exp < 65)
		mantis = mantis >> (64u - exp);
	fill_integ_array(integ, mantis);
	while (exp - 65 >= 0)
	{
		long_arithmetic_sum(integ, integ);
		exp--;
	}
}

static void	get_fractional_part(t_uint fract[], t_ulong mantissa, int exp)
{
	t_ulong	mantis;
	t_uint	tmp_arr[SIZE];

	mantis = mantissa;
	if (exp > 0)
		mantis = mantissa << exp;
	if (exp != 64)
		fill_arr_500(tmp_arr);
	while (exp < 0)
	{
		long_arithmetic_divs(tmp_arr, 2);
		exp++;
	}
	fill_arr_bzero(fract, SIZE);
	if (exp != 64)
		fill_fractional_part(fract, tmp_arr, mantis);
}

static void	fill_nan_or_inf(t_float num, char **res, char type)
{
	char *s;

	s = *res;
	if ((num.bytes.mantissa >> 62u) == 3)
	{
		if (type == 'F' || type == 'f')
		{
			s[0] = 'N';
			s[1] = 'A';
			s[2] = 'N';
			if (type == 'f')
				ft_tolowercase(*res);
		}
	}
	else if ((num.bytes.mantissa >> 63u) == 1)
	{
		if (type == 'F' || type == 'f')
		{
			s[0] = 'I';
			s[1] = 'N';
			s[2] = 'F';
			if (type == 'f')
				ft_tolowercase(*res);
		}
	}
}

static char	*check_nan_or_inf(t_params params, t_float num, int exp)
{
	char	*res;

	res = NULL;
	if (exp == 16385)
	{
		if (!(res = ft_strnew(3)))
			return (NULL);
		fill_nan_or_inf(num, &res, params.type);
	}
	return (res);
}

char		*get_float_number(va_list arg, t_params *params, int *len)
{
	char	*res;
	t_float	num;
	t_uint	integ[SIZE];
	t_uint	fract[SIZE];
	int		exp;

	if (params->modifier[0] == 'L')
		num.value = va_arg(arg, long double);
	else
		num.value = va_arg(arg, double);
	exp = num.bytes.exp - 16382;
	res = check_nan_or_inf(*params, num, exp);
	if (!res)
	{
		if (num.bytes.sign == 1)
			params->neg = 1;
		get_integer_part(integ, num.bytes.mantissa, exp);
		get_fractional_part(fract, num.bytes.mantissa, exp);
		float_rounding(integ, fract, params->accuracy);
		if (!(res = concat_parts(integ, fract, *params)))
			return (NULL);
	}
	*len = ft_strlen(res);
	return (res);
}
