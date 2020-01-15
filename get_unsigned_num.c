/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unsigned_num.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktimika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 14:29:49 by ktimika           #+#    #+#             */
/*   Updated: 2019/10/04 14:29:53 by ktimika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			digit_count(size_t nb, int base)
{
	int		i;

	i = 0;
	while (nb)
	{
		nb /= base;
		i++;
	}
	return (i);
}

static char	*get_result(char *res, size_t value, int base, int size)
{
	char	*tab_base;
	int		i;

	tab_base = "0123456789ABCDEF";
	i = 1;
	while (value)
	{
		res[size - i] = tab_base[value % base];
		value /= base;
		i++;
	}
	return (res);
}

char		*ft_itoa_base_mod(size_t value, int base)
{
	char	*res;
	int		size;

	if (value == 0)
		return ("0");
	size = digit_count(value, base);
	if (!(res = (char*)malloc(sizeof(res) * (size + 1))))
		return (NULL);
	res[size] = '\0';
	res = get_result(res, value, base, size);
	return (res);
}

char		*get_unsigned_num(t_params params, size_t unum)
{
	char	*res;

	res = NULL;
	if (params.type == 'b')
		res = ft_itoa_base_mod(unum, 2);
	else if (is_octal(params.type))
		res = ft_itoa_base_mod(unum, 8);
	else if (is_int(params.type))
		res = ft_itoa_base_mod(unum, 10);
	else if (is_hex(params.type) || params.type == 'p')
	{
		res = ft_itoa_base_mod(unum, 16);
		if (params.type == 'x' || params.type == 'p')
			ft_tolowercase(res);
	}
	return (res);
}
