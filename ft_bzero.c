/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktimika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:08:56 by ktimika           #+#    #+#             */
/*   Updated: 2019/09/04 13:44:14 by ktimika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char *str;

	str = (unsigned char*)s;
	while (n > 0)
	{
		*str = '\0';
		str++;
		n--;
	}
}
