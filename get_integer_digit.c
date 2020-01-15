/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_integer_digits.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktimika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 19:33:28 by ktimika           #+#    #+#             */
/*   Updated: 2019/10/02 19:33:40 by ktimika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_byte(t_params *params, va_list arg)
{
	char			num;
	unsigned char	unum;

	if (is_signed_int(params->type))
	{
		num = va_arg(arg, int);
		params->neg = num < 0 ? 1 : 0;
		unum = params->neg ? num * -1 : num;
	}
	else
		unum = va_arg(arg, unsigned int);
	return (get_unsigned_num(*params, unum));
}

static char	*get_2bytes(t_params *params, va_list arg)
{
	short			num;
	unsigned short	unum;

	if (is_signed_int(params->type))
	{
		num = va_arg(arg, int);
		params->neg = num < 0 ? 1 : 0;
		unum = params->neg ? num * -1 : num;
	}
	else
		unum = va_arg(arg, unsigned int);
	return (get_unsigned_num(*params, unum));
}

static char	*get_4bytes(t_params *params, va_list arg)
{
	int				num;
	unsigned int	unum;

	if (is_signed_int(params->type))
	{
		num = va_arg(arg, int);
		params->neg = num < 0 ? 1 : 0;
		unum = params->neg ? num * -1 : num;
	}
	else
		unum = va_arg(arg, unsigned int);
	return (get_unsigned_num(*params, unum));
}

static char	*get_8bytes(t_params *params, va_list arg)
{
	long			num;
	size_t			unum;

	if (is_signed_int(params->type))
	{
		num = va_arg(arg, long);
		params->neg = num < 0 ? 1 : 0;
		unum = params->neg ? num * -1 : num;
	}
	else
		unum = va_arg(arg, size_t);
	return (get_unsigned_num(*params, unum));
}

char		*get_integer_digit(t_params *params, va_list arg, int *len)
{
	char			*res;

	if (params->modifier[0] == 'h' && params->modifier[1] == 'h' &&
		params->type != 'p' && params->type != 'D' && params->type != 'U'
		&& params->type != 'O')
		res = get_byte(params, arg);
	else if (params->modifier[0] == 'h' && params->modifier[1] == '\0' &&
		params->type != 'p' && params->type != 'D' && params->type != 'U'
		&& params->type != 'O')
		res = get_2bytes(params, arg);
	else if (params->modifier[0] == '\0' && params->type != 'p' &&
			params->type != 'D' && params->type != 'U' && params->type != 'O')
		res = get_4bytes(params, arg);
	else
		res = get_8bytes(params, arg);
	*len = ft_strlen(res);
	if (res[0] == '0' && params->accuracy == 0 && (!is_octal(params->type) ||
		(is_octal(params->type) && !ft_strchr(params->flags, '#'))))
		*len = 0;
	return (res);
}
