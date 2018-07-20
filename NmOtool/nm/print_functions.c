/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:24:45 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/20 13:39:05 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int			hex_number_length(size_t number)
{
	int		count;

	count = 0;
	while (number > 0)
	{
		number /= 16;
		count++;
	}
	return (count);
}

void		pad_zeroes(int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		ft_putstr("0");
		i++;
	}
}

void		print_hex_value(unsigned long long hex, int is_32)
{
	size_t	i;
	size_t	count;
	char	number_array[hex_number_length(hex) + 1];
	char	c;

	count = hex_number_length(hex);
	i = 0;
	number_array[count] = '\0';
	count--;
	while (hex > 0)
	{
		c = hex % 16;
		if (c >= 10)
			number_array[count] = c + 'a' - 10;
		else
			number_array[count] = c + '0';
		hex /= 16;
		count--;
	}
	pad_zeroes((is_32 == 1 ? 8 : 16) - ft_strlen(number_array));
	ft_putstr(number_array);
	ft_putstr(" ");
}

void		print_whitespace(int is_32)
{
	int		i;
	int		c;

	c = is_32 == 1 ? 8 : 16;
	i = 0;
	while (i < c)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putchar(' ');
}

void		print_address_values(unsigned long long hex, int flag,
		int is_32)
{
	if (flag > 0 || hex > 0)
	{
		if (hex == 0)
		{
			if (is_32 == 0)
				pad_zeroes(16);
			else
				pad_zeroes(8);
			ft_putchar(' ');
		}
		else
			print_hex_value(hex, is_32);
	}
	else
		print_whitespace(is_32);
}
