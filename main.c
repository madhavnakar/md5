/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 09:53:10 by mnakar            #+#    #+#             */
/*   Updated: 2018/07/31 21:12:09 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include <math.h>

int		mod(int num, int n)
{
	int res;

	res = (num) % n;
	while (res < 0)
		res += n;
	return (res);
}

int		leftrotate(x, c)
{
	return (x << c | x >> (32 - c));
}

void	md5(char *str)
{
	uint8_t 	m[((ft_strlen(str) / 64) + 1) * 64];
	uint64_t	len;
	size_t		arr_len;
	char		*b_len;
	uint32_t	*tmp;	
	uint32_t	a0;
	uint32_t	b0;
	uint32_t	c0;
	uint32_t	d0;
	uint32_t	a;
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;
	uint32_t	K[64];
	uint32_t	s[64];

	for (int k = 0; k < 64; k++)
		K[k] = floor((pow(2, 31) * fabs(sin(k + 1)) * 2));

	for (int i = 0; i < 16; i += 4)
	{
		s[i] = 7;
		s[i + 1] = 12;
		s[i + 2] = 17;
		s[i + 3] = 22;
	}
	for (int i = 16; i < 32; i += 4)
	{
		s[i] = 5;
		s[i + 1] = 9;
		s[i + 2] = 14;
		s[i + 3] = 20;
	}
	for (int i = 32; i < 48; i += 4)
	{
		s[i] = 4;
		s[i + 1] = 11;
		s[i + 2] = 16;
		s[i + 3] = 23;
	}
	for (int i = 48; i < 64; i += 4)
	{
		s[i] = 6;
		s[i + 1] = 10;
		s[i + 2] = 15;
		s[i + 3] = 21;
	}

/*	for (int m = 0; m < 64; m++)
	{
		ft_printf("%d ", s[m]);
		if ((m + 1) % 16 == 0)
			ft_printf("\n");
	}
*/


	len = ft_strlen(str);
	arr_len = ((len / 64) + 1) * 64;
	ft_strcpy((char *)m, str);
	m[ft_strlen(str)] = 0x80;
	ft_bzero(m + len + 1, arr_len - len - 1);
	
	b_len = (char *)&len;
	for (int j = 7; j > -1; j--)
		m[arr_len - 1 + j] = b_len[j];

	a0 = 0x67452301;
	b0 = 0xefcdab89;
	c0 = 0x98badcfe;
	d0 = 0x10325476;

	for (int j = 0; j < 64; j++)
	{
		ft_printf("%b ", m[j]);
	}

	ft_printf("done with printing message\n");

	for (int j = 0; j < arr_len / 64; j++)
	{
		a = a0;
		b = b0;
		c = c0;
		d = c0;
		for (int i = 0; i < 64; i++)
		{
			uint32_t	F;
			uint32_t	g;
			if (0 <= i && i <= 15)
			{
				F = (a & b) | ((~b) & d);
				g = i;
			}
			else if (16 <= i && i <= 31)
			{
				F = (d &  i) + 5, 16);
			}
			else if (48 <= i && i <= 63)
			{
				F = c ^ (b | (~d));
				g = fmod(7 * i, 16);
			}
			ft_printf("g = %u\n", g);
			tmp = (uint32_t *)&m[64*j];
			if (g == 0)
				F = F + a + K[i] + 3875536896;
			else if (g == 15)
				F = F + a + K[i] + 1;
			else
				F = F + a + K[i];
			//F = F + a + K[i] + tmp[g];//m[64*j + g];
			ft_printf("%b\n", tmp[g]);
			a = d;
			d = c;
			c = b;
			b = b + leftrotate(F, s[i]); 
		}
		a0 = a0 + a;
		b0 = b0 + b;
		c0 = c0 + c;
		d0 = d0 + d;
		ft_printf("j = %d\n", j);
	}
	//ft_printf("arr_len = %zu\n", arr_len*8);
	ft_printf("MD5 (\"%s\") = %.8x%.8x%.8x%.8x\n", str, a0, b0, c0, d0);
}

int	main(int argc, char **argv)
{
	/*if (argc < 3)
	{
		ft_printf("usage: ./ft_ssl [md5/sha256] [-pqrtx] [-s string] [files ...]\n");
		return (0);
	}*/
	md5(argv[1]);
}
