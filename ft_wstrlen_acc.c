/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen_acc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktimika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:42:50 by ktimika           #+#    #+#             */
/*   Updated: 2019/10/07 16:42:52 by ktimika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	wstrlen_checker(wchar_t chr, size_t *len, int *accuracy)
{
	if (chr >= 0x0 && chr <= 0x7F)
	{
		*accuracy -= 1;
		*len = *accuracy < 0 ? *len : *len + 1;
	}
	else if (chr >= 0x80 && chr <= 0x7FF)
	{
		*accuracy -= 2;
		*len = *accuracy < 0 ? *len : *len + 2;
	}
	else if (chr >= 0x800 && chr <= 0xFFFF)
	{
		*accuracy -= 3;
		*len = *accuracy < 0 ? *len : *len + 3;
	}
	else if (chr >= 0x10000 && chr <= 0x10FFFF)
	{
		*accuracy -= 4;
		*len = *accuracy < 0 ? *len : *len + 4;
	}
}

size_t		ft_wstrlen_acc(wchar_t *str, int accuracy)
{
	size_t	len;

	len = 0;
	while (*str && accuracy > 0)
	{
		wstrlen_checker(*str, &len, &accuracy);
		if (accuracy < 0)
			break ;
		str++;
	}
	return (len);
}
