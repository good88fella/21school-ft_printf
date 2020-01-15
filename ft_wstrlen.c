/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktimika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 13:30:24 by ktimika           #+#    #+#             */
/*   Updated: 2019/10/01 13:30:28 by ktimika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_wstrlen(wchar_t *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		if (*str >= 0x0 && *str <= 0x7F)
			len++;
		else if (*str >= 0x80 && *str <= 0x7FF)
			len += 2;
		else if (*str >= 0x800 && *str <= 0xFFFF)
			len += 3;
		else if (*str >= 0x10000 && *str <= 0x10FFFF)
			len += 4;
		str++;
	}
	return (len);
}
