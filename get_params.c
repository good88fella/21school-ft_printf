/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktimika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 19:45:56 by ktimika           #+#    #+#             */
/*   Updated: 2019/09/26 19:46:00 by ktimika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			check_flags(t_params *params, char format)
{
	int i;

	i = 0;
	if (ft_strchr(params->flags, format))
		return ;
	while (i < 5)
	{
		if (params->flags[i] == '\0' && (format == '-' || format == '+' ||
		format == ' ' || format == '#'))
		{
			params->flags[i] = format;
			break ;
		}
		if (params->flags[i] == '\0' && format == '0' && params->width == 0 &&
				params->accuracy == -1)
		{
			params->flags[i] = format;
			break ;
		}
		i++;
	}
}

static const char	*check_width(t_params *params, const char *format,
					va_list arg)
{
	if (ft_isdigit(*format))
	{
		params->width = ft_atoi(format);
		while (ft_isdigit(*format))
			format++;
		format--;
	}
	if (*format == '*')
	{
		params->width = va_arg(arg, int);
		if (params->width < 0)
		{
			params->width *= -1;
			check_flags(params, '-');
		}
	}
	return (format);
}

static const char	*check_accuracy(t_params *params, const char *format,
					va_list arg)
{
	if (*format == '.')
		params->accuracy = 0;
	if (params->accuracy == 0)
	{
		if (ft_isdigit(*format))
		{
			params->accuracy = ft_atoi(format);
			while (ft_isdigit(*format))
				format++;
			format--;
		}
		if (*format == '*')
		{
			params->accuracy = va_arg(arg, int);
			if (params->accuracy < 0)
				params->accuracy = -1;
		}
	}
	return (format);
}

static void			check_modifier(t_params *params, char format)
{
	int i;

	i = 0;
	if (params->modifier[i] == format && (format == 'j' || format == 'z' ||
	format == 't' || format == 'L'))
		return ;
	while (i < 2)
	{
		if (params->modifier[i] == '\0' && (format == 'l' || format == 'h' ||
		format == 'j' || format == 'z' || format == 't' || format == 'L'))
		{
			params->modifier[i] = format;
			break ;
		}
		i++;
	}
}

void				get_params(t_params *params, const char *format,
					va_list arg, char type)
{
	params->type = type;
	ft_bzero(params->flags, 5);
	params->width = 0;
	params->accuracy = -1;
	params->neg = 0;
	ft_bzero(params->modifier, 2);
	while (*format != type)
	{
		check_flags(params, *format);
		if (params->accuracy == -1)
			format = check_width(params, format, arg);
		format = check_accuracy(params, format, arg);
		check_modifier(params, *format);
		format++;
	}
}
