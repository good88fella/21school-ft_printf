/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_is_it.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktimika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 13:07:36 by ktimika           #+#    #+#             */
/*   Updated: 2019/10/06 13:07:47 by ktimika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		is_signed_int(int c)
{
	if (c == 'd' || c == 'D' || c == 'i')
		return (1);
	return (0);
}

int		is_int(int c)
{
	if (c == 'd' || c == 'D' || c == 'i' ||
		c == 'u' || c == 'U')
		return (1);
	return (0);
}

int		is_octal(int c)
{
	if (c == 'o' || c == 'O')
		return (1);
	return (0);
}

int		is_hex(int c)
{
	if (c == 'x' || c == 'X')
		return (1);
	return (0);
}
