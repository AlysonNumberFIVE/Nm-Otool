/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:24:45 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/17 10:47:29 by angonyam         ###   ########.fr       */
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

void		print_hex_value(unsigned long long hex)
{
	size_t	i;
	size_t	count;
	char	*number_array;
	char	c;

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

void		print_whitespace(void)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putchar(' ');
}

void		print_address_values(unsigned long long hex, int flag)
{
	if (flag > 0)
	{
		if (hex == 0)
		{
			pad_zeroes(16);
			ft_putchar(' ');
		}
		else
			print_hex_value(hex);
	}
	else
		print_whitespace();
}
