/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string_or_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktimika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:11:47 by ktimika           #+#    #+#             */
/*   Updated: 2019/10/07 11:11:49 by ktimika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_string_or_char(void *arg, t_params params, int len, int *cnt)
{
	if (params.type == 'c' && params.modifier[0] == '\0')
		ft_putchar(*(unsigned char*)arg);
	else if ((params.type == 's' && params.modifier[0] == '\0') ||
			ft_strcmp((char*)arg, "(null)") == 0)
		write(1, (char*)arg, len);
	else if ((params.type == 'c' && params.modifier[0] == 'l') ||
			params.type == 'C')
		ft_putwchar(*(wchar_t*)arg);
	else if ((params.type == 's' && params.modifier[0] == 'l') ||
			params.type == 'S')
		ft_putwstr((wchar_t*)arg, len, cnt);
}

static void	get_char(int **res, va_list arg, t_params params, int *len)
{
	int		chr;

	chr = va_arg(arg, int);
	**res = chr;
	if (params.type == 'c' && params.modifier[0] == '\0')
		*len += 1;
	else
	{
		if (chr >= 0x0 && chr <= 0x7F)
			*len += 1;
		else if (chr >= 0x80 && chr <= 0x7FF)
			*len += 2;
		else if (chr >= 0x800 && chr <= 0xFFFF)
			*len += 3;
		else if (chr >= 0x10000 && chr <= 0x10FFFF)
			*len += 4;
	}
}

void		get_string_or_char(void **res, va_list arg, t_params params,
								int *len)
{
	if (is_string_type(params.type))
		*res = va_arg(arg, void*);
	else
		get_char((int **)res, arg, params, len);
	if (is_string_type(params.type))
	{
		if ((params.type == 's' && params.modifier[0] == '\0') || *res == NULL)
		{
			if (*res == NULL)
				*res = "(null)";
			*len = ft_strlen(*res);
		}
		else
			*len = ft_wstrlen(*res);
		if (*len > params.accuracy && params.accuracy != -1)
		{
			if ((params.type == 's' && params.modifier[0] == '\0') ||
				ft_strcmp(*res, "(null)") == 0)
				*len = params.accuracy;
			else
				*len = ft_wstrlen_acc(*res, params.accuracy);
		}
	}
}
