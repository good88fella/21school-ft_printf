/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktimika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 13:32:50 by ktimika           #+#    #+#             */
/*   Updated: 2019/10/06 13:32:54 by ktimika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_nan(char *arg)
{
	if (ft_strcmp(arg, "nan") == 0 ||
		ft_strcmp(arg, "NAN") == 0)
		return (1);
	return (0);
}

int		is_signed(t_params params)
{
	if (params.neg || ft_strchr(params.flags, '+') ||
		ft_strchr(params.flags, ' '))
		return (1);
	return (0);
}

void	apply_sign(char *arg, t_params params, int *cnt)
{
	if (is_signed(params) && (is_signed_int(params.type) ||
		is_float_type(params.type)))
	{
		if (params.neg)
		{
			ft_putchar('-');
			*cnt += 1;
		}
		else if (ft_strchr(params.flags, '+') && !is_nan(arg))
		{
			ft_putchar('+');
			*cnt += 1;
		}
		else if ((ft_strchr(params.flags, ' ') && !is_nan(arg)) ||
				(is_nan(arg) && params.width > 3 &&
				!ft_strchr(params.flags, '-')))
		{
			ft_putchar(' ');
			*cnt += 1;
		}
	}
}

void	apply_octotorp(char *arg, t_params params, int *cnt)
{
	if ((ft_strchr(params.flags, '#') && (is_hex(params.type) ||
		is_octal(params.type) || params.type == 'b')) || params.type == 'p')
	{
		if (((is_hex(params.type) || params.type == 'b') &&
			arg[0] != '0') || params.type == 'p')
		{
			if (params.type == 'x' || params.type == 'p')
				write(1, "0x", 2);
			else if (params.type == 'X')
				write(1, "0X", 2);
			else if (params.type == 'b')
				write(1, "0b", 2);
			*cnt += 2;
		}
		else if (is_octal(params.type) && arg[0] == '0' &&
				params.accuracy == 0)
			ft_putchar('0');
	}
}

void	apply_zero(char *arg, t_params params, int size, int *cnt)
{
	int count;

	if (ft_strchr(params.flags, '0') && !ft_strchr(params.flags, '-') &&
		!is_nan(arg) && (params.accuracy == -1 || is_float_type(params.type)))
	{
		if (is_signed(params) && (is_signed_int(params.type) ||
		is_float_type(params.type)))
			size++;
		count = params.width - size;
		if (count > 0)
			print_zero(count, cnt);
	}
}
