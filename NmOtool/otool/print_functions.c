/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:52:46 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/20 13:02:09 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

void			put_otool_hex(unsigned long long hex)
{
	char		*str;
	size_t		size;
	size_t		i;
	size_t		c;

	size = hex_number_length(hex);
	str = (char*)malloc(sizeof(char) * (size + 1));
	i = 0;
	str[size] = '\0';
	size--;
	while (hex > 0)
	{
		c = hex % 16;
		if (c >= 10)
			str[size] = c + 'a' - 10;
		else
			str[size] = c + '0';
		hex /= 16;
		size--;
	}
	if (ft_strlen(str) == 1)
		ft_putchar('0');
	ft_putstr(str);
	free(str);
}

void			pad_zeroes(int len)
{
	int			i;

	i = 0;
	while (i < len)
	{
		ft_putstr("0");
		i++;
	}
}

void			print_hex_value(unsigned long long hex)
{
	size_t		i;
	size_t		count;
	char		*number_array;
	char		c;

	count = hex_number_length(hex);
	number_array = (char*)malloc(sizeof(char) * count + 1);
	i = 0;
	count--;
	number_array[count] = '\0';
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
	pad_zeroes(16 - ft_strlen(number_array));
	ft_putstr(number_array);
	ft_putstr(" ");
	free(number_array);
}

void			print_whitespace(void)
{
	int			i;

	i = 0;
	while (i < 16)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putchar(' ');
}

void			print_address_values(unsigned long long hex, int flag)
{
	if (flag > 0)
		print_hex_value(hex);
	else
		print_whitespace();
}
