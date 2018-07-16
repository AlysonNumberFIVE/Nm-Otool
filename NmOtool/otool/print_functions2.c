/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:59:59 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/16 12:21:51 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

void			intro_info(char *filename)
{
	ft_putstr(filename);
	ft_putstr(":\nContents of (__TEXT,__text) sectinn");
}

void			print_mem_val(unsigned long long hex)
{
	if (hex == 0)
		ft_putstr("00");
	else
		put_otool_hex(hex);
}

int				hex_number_length(size_t number)
{
	int			count;

	count = 0;
	while (number > 0)
	{
		number /= 16;
		count++;
	}
	return (count);
}
