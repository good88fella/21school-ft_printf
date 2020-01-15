/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktimika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 13:05:22 by ktimika           #+#    #+#             */
/*   Updated: 2019/10/01 13:05:26 by ktimika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putwstr(wchar_t *s, int len, int *cnt)
{
	int bytes;
	int tmp;

	bytes = 0;
	tmp = len;
	while (*s && len > 0)
	{
		if (*s >= 0x0 && *s <= 0x7F)
			len--;
		else if (*s >= 0x80 && *s <= 0x7FF)
			len -= 2;
		else if (*s >= 0x800 && *s <= 0xFFFF)
			len -= 3;
		else if (*s >= 0x10000 && *s <= 0x10FFFF)
			len -= 4;
		if (len < 0)
			break ;
		bytes += ft_putwchar(*s);
		s++;
	}
	*cnt = *cnt - (tmp - bytes);
}
