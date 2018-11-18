/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 17:25:28 by mnakar            #+#    #+#             */
/*   Updated: 2018/07/29 12:22:55 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef	struct		s_info
{
	int				*format;
	int				prec;
	int				zero;
}					t_info;

typedef struct		s_table
{
	char			flag;
	void			(*function)(t_info, va_list *);
}					t_table;

typedef struct		s_help
{
	int		sp;
	int		len;
	int		bits;
	char	spchar;
}					t_help;

# define SCHAR sizeof(signed char) * 8
# define UCHAR sizeof(unsigned char) * 8
# define SHORT sizeof(short) * 8
# define USHORT sizeof(unsigned short) * 8
# define INT sizeof(int) * 8
# define UINT sizeof(unsigned int) * 8
# define LONG sizeof(long) * 8
# define ULONG sizeof(unsigned long) * 8
# define LLONG sizeof(long long) * 8
# define ULLONG sizeof(unsigned long long) * 8
# define INTMAX_T sizeof(intmax_t) * 8
# define UINTMAX_T sizeof(uintmax_t) * 8
# define SIZE_T sizeof(size_t) * 8
# define NEG 0x80000000
# define POS 0x40000000
# define SP 0x20000000
# define ZERO 0x10000000
# define HASH 0x8000000
# define PER 0x4000000
# define HH 0x2000000
# define H 0x1000000
# define L 0x800000
# define LL 0x400000
# define J 0x200000
# define Z 0x100000
# define ISNEG(info) *info.format & NEG
# define ISPOS(info) *info.format & POS
# define ISSP(info) *info.format & SP
# define ISZERO(info) *info.format & ZERO
# define ISHASH(info) *info.format & HASH
# define ISPER(info) *info.format & PER
# define ISHH(info) *info.format & HH
# define ISH(info) *info.format & H
# define ISL(info) *info.format & L
# define ISLL(info) *info.format & LL
# define ISJ(info) *info.format & J
# define ISZ(info) *info.format & Z

int					ft_printf(char *s, ...);
int					parseopt(char **s, va_list *ap);
int					isflag(char c);
int					isfield(char c);
int					isconvflag(char c);
void				handle_s(t_info info, va_list *ap);
void				handle_int(t_info info, va_list *ap);
void				handle_u(t_info info, va_list *ap);
void				handle_x(t_info info, va_list *ap);
void				handle_xc(t_info info, va_list *ap);
void				handle_o(t_info info, va_list *ap);
void				handle_p(t_info info, va_list *ap);
void				handle_c(t_info info, va_list *ap);
void				handle_per(t_info info, va_list *ap);
void				handle_uc(t_info info, va_list *ap);
void				handle_dc(t_info info, va_list *ap);
void				handle_oc(t_info info, va_list *ap);
void				handle_b(t_info info, va_list *ap);
int					isneg(long long n, int bits, int isfinalcall);
void				ft_putschar(signed char n);
void				ft_putshort(short n);
void				ft_putlong(long n);
void				ft_putlonglong(long long n);
size_t				numlen_x(unsigned long long num, unsigned int base);
void				printformat_u(t_info info, unsigned long long n, int bits,
					int *spaces);
int					printformat_int(t_info info, long long n, int bits,
					int *spaces);
int					printformat_o(t_info info, long long n, int bits,
					int *spaces);
long long			negate(long long n, int bits);
unsigned long long	clear_bits_u(unsigned long long n, int bits);
unsigned long long	clear_bits_o(unsigned long long n, int bits);
long				clear_bits(long long n, int bits);
long long			negate(long long n, int bits);

#endif
