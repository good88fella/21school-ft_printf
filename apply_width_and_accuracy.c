/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width_and_accuracy.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktimika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 14:21:25 by ktimika           #+#    #+#             */
/*   Updated: 2019/10/06 14:21:28 by ktimika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_spaces(t_params params, int size, int *cnt)
{
	int		i;
	char	*str;
	int		count;

	count = params.width - size;
	if (count > 0)
	{
		if (!(str = (char*)malloc(sizeof(str) * count)))
			exit(1);
		i = 0;
		while (i < count)
		{
			str[i] = ' ';
			i++;
		}
		write(1, str, count);
		*cnt += count;
		free(str);
	}
}

void		apply_width(char *arg, t_params *params, int size, int *cnt)
{
	if (!ft_strchr(params->flags, '0') || ft_strchr(params->flags, '-') ||
	is_nan(arg) || (params->accuracy != -1 && is_integer_type(params->type)))
	{
		if (size < params->accuracy && is_integer_type(params->type))
			size = params->accuracy;
		if (is_signed(*params) && (is_signed_int(params->type) ||
			(is_float_type(params->type) && !is_nan(arg)) ||
			(is_nan(arg) && params->width > 3 &&
			!ft_strchr(params->flags, '-'))))
			size++;
		if (params->type == 'p')
		{
			if (params->type == 'p')
				size += 2;
		}
		print_spaces(*params, size, cnt);
	}
}

void		print_zero(int count, int *cnt)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = (char*)malloc(sizeof(str) * count)))
		exit(1);
	while (i < count)
	{
		str[i] = '0';
		i++;
	}
	write(1, str, count);
	*cnt += count;
	free(str);
}

int			apply_accuracy(char *arg, t_params params, int len, int *cnt)
{
	int count;

	count = 0;
	if ((is_integer_type(params.type) || params.type == 'p') &&
		len < params.accuracy)
	{
		count = params.accuracy - len;
		print_zero(count, cnt);
	}
	if ((is_integer_type(params.type) || params.type == '%' ||
		params.type == 'p') && (arg[0] != '0' || params.accuracy != 0))
		write(1, arg, len);
	else if (is_string_type(params.type) || is_char_type(params.type))
		print_string_or_char(arg, params, len, cnt);
	else if (is_float_type(params.type))
		write(1, arg, len);
	*cnt += len;
	if (arg[0] != '0' && (is_integer_type(params.type) || params.type == 'p'))
		free(arg);
	if (is_float_type(params.type))
		free(arg);
	return (count);
}
