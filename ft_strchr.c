/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktimika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:05:53 by ktimika           #+#    #+#             */
/*   Updated: 2019/09/04 20:49:50 by ktimika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int len;
	int i;

	len = 0;
	while (s[len])
		len++;
	len++;
	i = 0;
	while (i < len)
	{
		if (*s == (unsigned char)c)
			return ((char*)s);
		i++;
		s++;
	}
	return (NULL);
}
