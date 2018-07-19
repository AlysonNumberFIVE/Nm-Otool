/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm64.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:24:12 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/19 07:24:04 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void		print_name(const char *name)
{
	ft_putstr(" ");
	ft_putstr(name);
	ft_putendl(" ");
}

void		string_segment_64(void *content,
		struct symtab_command *tabs)
{
	const char				*string_tab;
	struct nlist_64			*list;
	struct nlist_64			*info;
	uint32_t				i;
	const char				*name;

	i = 0;
	string_tab = (const char*)content + tabs->stroff;
	list = (struct nlist_64*)((char*)content + tabs->symoff);
	while (i < tabs->nsyms)
	{
		info = &list[i];
		if (info->n_type & N_STAB)
		{
			i++;
			continue ;
		}
		name = &string_tab[info->n_un.n_strx];
		print_address_values(info->n_value, info->n_sect, 0);
		i++;
		which(info->n_type, info->n_sect, info->n_value);
		print_name(name);
	}
}

void		nm_64(struct mach_header *header,
			void *content, size_t size)
{
	struct mach_header_64	*header64;
	struct load_command		*load;
	int						command_num;
	struct symtab_command	*tab;

	size = 0;
	header64 = (struct mach_header_64 *)header;
	load = (struct load_command *)&header64[1];
	command_num = header64->ncmds;
	tab = iterate_through_load_commands(load, command_num);
	string_segment_64(content, tab);
}
