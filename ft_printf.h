/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktimika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:16:24 by ktimika           #+#    #+#             */
/*   Updated: 2019/09/21 15:16:26 by ktimika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_FT_PRINTF_H
# define PRINTF_FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define BASE (1000000000u)
# define SIZE (100u)
# define NLEN (9u)

typedef unsigned long	t_ulong;
typedef unsigned int	t_uint;

typedef struct	s_params
{
	char		flags[5];
	int			width;
	int			accuracy;
	char		modifier[2];
	char		type;
	int			neg;
}				t_params;

typedef struct	s_bytes
{
	t_ulong		mantissa: 64;
	t_uint		exp: 15;
	t_uint		sign: 1;
}				t_bytes;

typedef union	u_float
{
	t_bytes		bytes;
	long double value;
}				t_float;

int				ft_printf(const char *format, ...);
void			get_params(t_params *params, const char *format,
				va_list arg, char type);
char			*get_float_number(va_list arg, t_params *params, int *len);
void			float_rounding(t_uint integ[], t_uint fract[], int accuracy);
char			*concat_parts(t_uint integ[], t_uint fract[], t_params params);
void			print_string_or_char(void *arg, t_params params, int len,
				int *cnt);
void			get_string_or_char(void **res, va_list arg, t_params params,
				int *len);
char			*get_unsigned_num(t_params params, size_t unum);
char			*get_integer_digit(t_params *params, va_list arg, int *len);
void			long_arithmetic_sum(t_uint dest[], t_uint src[]);
void			long_arithmetic_sums(t_uint dest[], t_uint nb);
void			long_arithmetic_divs(t_uint dest[], t_uint num);
int				is_more_num_dig(t_uint arr[], t_uint nb, int acc);
void			fill_integ_array(t_uint integ[], t_ulong mantissa);
void			fill_fractional_part(t_uint fract[], t_uint tmp_arr[],
				t_ulong mantis);
void			fill_arr_500(t_uint tmp_arr[]);
void			fill_arr_bzero(t_uint arr[], t_uint size);
char			*ft_itoa_base_mod(size_t value, int base);
int				digit_count(size_t nb, int base);
t_uint			ten_in_pow(t_uint pow);
void			apply_width(char *arg, t_params *params, int size, int *cnt);
int				apply_accuracy(char *arg, t_params params, int len, int *cnt);
void			print_zero(int count, int *cnt);
void			apply_sign(char *arg, t_params params, int *cnt);
void			apply_octotorp(char *arg, t_params params, int *cnt);
void			apply_zero(char *arg, t_params params, int size, int *cnt);
int				is_signed(t_params params);
int				is_nan(char *arg);
int				is_conversion_type(char c);
int				is_string_type(char c);
int				is_char_type(char c);
int				is_integer_type(char c);
int				is_float_type(char c);
int				ft_isdigit(int c);
int				is_signed_int(int c);
int				is_hex(int c);
int				is_octal(int c);
int				is_int(int c);
int				ft_atoi(const char *str);
void			ft_putwstr(wchar_t *s, int len, int *cnt);
void			ft_putchar(int c);
int				ft_putwchar(int c);
void			ft_putnbr(int n);
void			ft_bzero(void *s, size_t n);
size_t			ft_strlen(const char *str);
size_t			ft_wstrlen(wchar_t *str);
size_t			ft_wstrlen_acc(wchar_t *str, int accuracy);
char			*ft_strchr(const char *s, int c);
char			*ft_tolowercase(char *str);
char			*ft_strnew(size_t size);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_strcmp(const char *s1, const char *s2);

#endif
