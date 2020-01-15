/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat_parts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktimika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:49:38 by ktimika           #+#    #+#             */
/*   Updated: 2019/10/14 12:49:41 by ktimika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_part(char **dest, t_uint src[], int size)
{
	char	*s;
	t_uint	i;
	t_uint	m;

	s = *dest;
	i = 0;
	while (size >= 0)
	{
		m = BASE / 10;
		while (m)
		{
			s[i] = src[size] / m + '0';
			src[size] %= m;
			m /= 10;
			i++;
		}
		size--;
	}
}

static char	*gets_integ_float_num(t_uint integ[], int size)
{
	char	*int_part;
	char	*most_dig;
	char	*least_dig;

	while (!integ[size] && size)
		size--;
	if (integ[size] == 0)
	{
		if (!(int_part = ft_strnew(1)))
			return (NULL);
		int_part[0] = '0';
	}
	else
	{
		if (!(least_dig = ft_strnew((size * 9))))
			return (NULL);
		if (!(most_dig = ft_itoa_base_mod(integ[size], 10)))
			return (NULL);
		fill_part(&least_dig, integ, size - 1);
		if (!(int_part = ft_strjoin(most_dig, least_dig)))
			return (NULL);
		free(most_dig);
		free(least_dig);
	}
	return (int_part);
}

static char	*gets_fract_float_num(t_uint fract[], t_params params, int size)
{
	char	*fract_part;
	int		i;
	int		num_cnt;
	t_uint	m;

	i = 0;
	num_cnt = params.accuracy == -1 ? 6 : params.accuracy;
	if (!(fract_part = ft_strnew(num_cnt + 1)))
		return (NULL);
	if (params.accuracy != 0)
		fract_part[i++] = '.';
	while (size >= 0)
	{
		m = BASE / 10;
		while (m && num_cnt)
		{
			fract_part[i++] = fract[size] / m + '0';
			fract[size] %= m;
			m /= 10;
			num_cnt--;
		}
		size--;
	}
	return (fract_part);
}

char		*concat_parts(t_uint integ[], t_uint fract[], t_params params)
{
	char	*res;
	char	*int_part;
	char	*fract_part;

	if (!(int_part = gets_integ_float_num(integ, SIZE - 1)))
		return (NULL);
	if (!(fract_part = gets_fract_float_num(fract, params, SIZE - 1)))
		return (NULL);
	if (!(res = ft_strjoin(int_part, fract_part)))
		return (NULL);
	free(int_part);
	free(fract_part);
	return (res);
}
