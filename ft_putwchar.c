/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktimika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 13:28:36 by ktimika           #+#    #+#             */
/*   Updated: 2019/10/01 13:28:38 by ktimika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	get_bytes(int c, char code[], int *bytes)
{
	if (c >= 0x0 && c <= 0x7F)
		code[0] = c;
	else if (c >= 0x80 && c <= 0x7FF)
	{
		code[0] = (c >> 6) | 0xC0;
		code[1] = (c & 0x3F) | 0x80;
		*bytes += 1;
	}
	else if (c >= 0x800 && c <= 0xFFFF)
	{
		code[0] = (c >> 12) | 0xE0;
		code[1] = ((c >> 6) & 0x3F) | 0x80;
		code[2] = (c & 0x3F) | 0x80;
		*bytes += 2;
	}
	else if (c >= 0x10000 && c <= 0x10FFFF)
	{
		code[0] = (c >> 18) | 0xF0;
		code[1] = ((c >> 12) & 0x3F) | 0x80;
		code[2] = ((c >> 6) & 0x3F) | 0x80;
		code[3] = (c & 0x3F) | 0x80;
		*bytes += 3;
	}
}

int			ft_putwchar(int c)
{
	char	code[4];
	int		bytes;

	bytes = 1;
	get_bytes(c, code, &bytes);
	write(1, code, bytes);
	return (bytes);
}
