/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_symbols.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:50:00 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/18 16:00:03 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"
#include <stdio.h>

void					print_x(size_t limit)
{
	ft_putchar('\n');
	if (limit == 0)
		ft_putstr("0000000000000000 ");
	else
		print_hex_value((unsigned long long)limit);
	ft_putstr("     ");
}

void					print_section(void *content, size_t start, size_t limit,
		size_t size)
{
	unsigned char			*file;
	size_t					i;
	int						d;

	file = (unsigned char *)content;
	i = 0;
	d = 0;
	print_x(limit);
	limit += 16;
	while (i < size)
	{
		if (d % 16 == 0 && d > 0)
		{
			print_x(limit);
			limit += 16;
			d = 0;
		}
		if (file[start] == 0)
			ft_putstr("00");
		put_otool_hex((unsigned long long)file[start]);
		ft_putchar(' ');
		i++;
		d++;
		start++;
	}
}

struct section_64		*find_segment_position_64(
				struct segment_command_64 *seg)
{
	struct section_64		*sect;
	uint32_t				i;

	sect = (struct section_64*)seg;
	i = 0;
	while (i < seg->nsects)
	{
		if (ft_strcmp(sect->sectname, "__text") == 0)
			break ;
		sect = (struct section_64 *)(((void*)sect) +
				sizeof(struct section_64 ));
		i++;
	}
	return (sect);
}

void					otool(void *content, int flag)
{
	struct mach_header		*header;
	int						is_64;

	header = content;
	is_64 = is_64_or_32(header);
	ft_putstr("Contents of (__TEXT,__text) section");
	if (is_64 == 1)
		otool_64(header, content, flag);
	else
		otool_32(header, content, flag);
}
