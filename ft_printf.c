/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktimika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:16:17 by ktimika           #+#    #+#             */
/*   Updated: 2019/09/21 15:16:19 by ktimika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			get_argument(void **res, va_list arg,
								t_params *params, int *len)
{
	if (params->type == '%')
	{
		*res = "%";
		*len += 1;
	}
	else if (is_integer_type(params->type) || params->type == 'p')
		*res = get_integer_digit(params, arg, len);
	else if (is_string_type(params->type) || is_char_type(params->type))
		get_string_or_char(res, arg, *params, len);
	else if (is_float_type(params->type))
		*res = get_float_number(arg, params, len);
}

static int			correct_accuracy(char *arg, t_params *params, int len)
{
	if (ft_strchr(params->flags, '#') && arg[0] != '0' &&
		is_octal(params->type))
	{
		if (ft_strchr(params->flags, '0') && params->width > params->accuracy
		&& params->accuracy == -1)
			params->accuracy = params->width;
		if (len >= params->accuracy)
			params->accuracy = len + 1;
	}
	if (ft_strchr(params->flags, '#') && arg[0] != '0' && is_hex(params->type))
	{
		if (len < params->accuracy && !ft_strchr(params->flags, '-'))
			len = params->accuracy;
		len += 2;
	}
	return (len);
}

static void			apply_params_and_print(va_list arg, t_params *params,
											int *cnt)
{
	void		*res;
	int			len;
	int			size;
	int			tmp;

	res = &tmp;
	len = 0;
	get_argument(&res, arg, params, &len);
	size = len;
	size = correct_accuracy(res, params, size);
	if (!ft_strchr(params->flags, '-'))
		apply_width(res, params, size, cnt);
	apply_sign(res, *params, cnt);
	apply_octotorp(res, *params, cnt);
	apply_zero(res, *params, size, cnt);
	size += apply_accuracy(res, *params, len, cnt);
	if (ft_strchr(params->flags, '-'))
		apply_width(res, params, size, cnt);
}

static const char	*analyze_and_print(const char *format,
										va_list arg, int *cnt)
{
	t_params	params;
	const char	*type;

	type = format;
	while (!is_conversion_type(*type) && *type)
		type++;
	if (*type == '\0')
		return (type);
	get_params(&params, format, arg, *type);
	apply_params_and_print(arg, &params, cnt);
	return (++type);
}

int					ft_printf(const char *format, ...)
{
	va_list		arg;
	int			cnt;

	va_start(arg, format);
	cnt = 0;
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			format++;
			cnt++;
			continue;
		}
		format++;
		format = analyze_and_print(format, arg, &cnt);
	}
	va_end(arg);
	return (cnt);
}
