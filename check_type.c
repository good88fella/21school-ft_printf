/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktimika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:18:26 by ktimika           #+#    #+#             */
/*   Updated: 2019/10/04 18:18:29 by ktimika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_conversion_type(char c)
{
	if (c == 'd' || c == 'D' || c == 'i' || c == 'u' || c == 'U' || c == 'b' ||
		c == 'o' || c == 'O' || c == 'x' || c == 'X' || c == 'f' || c == 'F' ||
		c == 'e' || c == 'E' || c == 'g' || c == 'G' || c == 'a' || c == 'A' ||
		c == 'c' || c == 'C' || c == 's' || c == 'S' || c == 'p' || c == 'n' ||
		c == '%' || c == 'n')
		return (1);
	return (0);
}

int	is_string_type(char c)
{
	if (c == 's' || c == 'S')
		return (1);
	return (0);
}

int	is_char_type(char c)
{
	if (c == 'c' || c == 'C')
		return (1);
	return (0);
}

int	is_integer_type(char c)
{
	if (c == 'd' || c == 'D' || c == 'i' || c == 'u' || c == 'U' || c == 'b' ||
		c == 'o' || c == 'O' || c == 'x'
	|| c == 'X')
		return (1);
	return (0);
}

int	is_float_type(char c)
{
	if (c == 'f' || c == 'F' || c == 'e' || c == 'E' || c == 'g' || c == 'G' ||
		c == 'a' || c == 'A')
		return (1);
	return (0);
}
