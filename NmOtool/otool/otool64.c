/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool64.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:49:27 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/16 12:22:49 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

void		object_seg(struct mach_header_64 *seg,
			void *content)
{
	struct section_64	*sect;
	unsigned char		*file;
	size_t				start;
	size_t				limit;
	size_t				size;

	file = (unsigned char *)content;
	sect = (struct section_64 *)&seg[1];
	while (42)
	{
		if (ft_strcmp(sect->sectname, "__text") == 0)
			break ;
		sect = (struct section_64 *)((void*)sect + sizeof(struct section_64 *));
	}
	start = sect->offset;
	limit = sect->addr;
	size = sect->size;
	print_section(content, start, limit, size);
	ft_putchar('\n');
}

void		otool_64(struct mach_header *header,
		void *content)
{
	struct mach_header_64 *header64;

	header64 = (struct mach_header_64 *)header;
	object_seg(header64, content);
}
