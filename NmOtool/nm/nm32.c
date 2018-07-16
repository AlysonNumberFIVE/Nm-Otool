/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm32.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:20:15 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/16 11:22:14 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void		print_32_sys(struct nlist *info)
{
	uint32_t				value;

	value = info->n_value;
	if ((info->n_value & N_TYPE) == N_SECT &&
			info->n_desc == N_ARM_THUMB_DEF)
		value |= 1;
	print_address_values(value, info->n_sect);
}

void		string_segment(void *content,
		struct symtab_command *tab)
{
	struct nlist			*list;
	struct nlist			*info;
	uint32_t				i;
	const char				*string_tab;
	const char				*name;

	string_tab = (const char *)content + tab->stroff;
	list = (struct nlist *)((char*)content + tab->symoff);
	i = 0;
	while (i < tab->nsyms)
	{
		info = &list[i];
		if (info->n_type == N_STAB)
		{
			i++;
			continue ;
		}
		i++;
		name = &string_tab[info->n_un.n_strx];
		print_32_sys(info);
		which(info->n_type, info->n_sect, info->n_value);
		print_name(name);
	}
}

void		nm_32(struct mach_header *header,
		void *content)
{
	struct load_command		*load;
	int						command_num;
	struct symtab_command	*tab;

	load = (struct load_command *)&header[1];
	command_num = header->ncmds;
	tab = iterate_through_load_commands(load, command_num);
	string_segment(content, tab);
}
