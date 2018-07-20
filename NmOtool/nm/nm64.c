/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm64.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:24:12 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/20 06:34:08 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void		print_name(const char *name)
{
	ft_putstr(" ");
	ft_putstr(name);
	ft_putendl(" ");
}
/*
void		print_val(char *word)
{
	if (ft_strcmp(word, "__text") == 0)
		ft_putstr(" T ");
	else if (ft_strcmp(word, "__TEXT") == 0)
		ft_putstr(" s ");
	else if (ft_strcmp(word, "__DATA") == 0)
		ft_putstr(" b ");
	else if (ft_strcmp(word, "__obj_const") == 0)
		ft_putstr(" S ");
	else if (ft_strcmp(word, "__objc_selrefs") == 0)
		ft_putstr(" D ");
	else if (
}*/

void		string_segment_64(void *content,
		struct symtab_command *tabs, char **array)
{
	const char				*string_tab;
	struct nlist_64			*list;
	struct nlist_64			*info;
	uint32_t				i;
	const char				*name;
	unsigned int			val;

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
		val = info->n_type & N_TYPE;
		if (val == N_SECT)
		{	
			ft_putnbr(info->n_sect);
			ft_putstr(" ");
			ft_putstr(array[info->n_sect - 1]);
		}
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
	char					**array;

	array = NULL;
	size = 0;
	header64 = (struct mach_header_64 *)header;
	load = (struct load_command *)&header64[1];
	command_num = header64->ncmds;
	tab = iterate_through_load_commands(load, command_num);
	array = segment_extraction(load, command_num);
	string_segment_64(content, tab, array);
}
