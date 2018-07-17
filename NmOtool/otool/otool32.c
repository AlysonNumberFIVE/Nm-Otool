/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool32.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:46:50 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/17 11:26:59 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

void		object_seg_32(struct mach_header *seg, void *content, 
		int flag)
{
	struct section	*sect;
	size_t			start;
	unsigned char	*file;
	size_t			limit;
	size_t			size;

	file = (unsigned char *)content;
	sect = (struct section *)&seg[1];
	while (42)
	{
		if (ft_strcmp(sect->sectname, "__text") == 0)
			break ;
		sect = (struct section *)((void*)sect + sizeof(struct section *));
	}
	start = sect->offset;
	if (flag == 1)
		limit = 0;
	else
		limit = sect->addr;
	size = sect->size;
	print_section(content, start, limit, size);
	ft_putchar('\n');
}

void		otool_32(struct mach_header *header, void *content, int flag)
{
	header = (struct mach_header *)content;
	object_seg_32(header, content, flag);
}
