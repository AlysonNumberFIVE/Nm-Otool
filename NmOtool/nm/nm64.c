/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm64.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:24:12 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/20 13:39:19 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void		print_name(const char *name)
{
	ft_putstr(" ");
	ft_putendl(name);
}

void		print_val(char *word, int is_extern)
{
	if (ft_strcmp(word, "__bss") == 0)
		ft_putstr("b");
	else if (ft_strcmp(word, "__text") == 0)
		is_extern > 0 ? ft_putstr("T") : ft_putstr("t");
	else if (ft_strcmp(word, "__data") == 0)
		is_extern > 0 ? ft_putstr("D") : ft_putstr("d");
	else if (ft_strcmp(word, "__const") == 0)
		is_extern > 0 ? ft_putstr("S") : ft_putstr("s");
	else if (ft_strcmp(word, "__common") == 0)
		is_extern > 0 ? ft_putstr("S") : ft_putstr("s");
	else
		is_extern == 0 ? ft_putstr("s") : ft_putstr("S");
}

void		string_segment_64(void *content,
		struct symtab_command *tabs, char **array)
{
	const char				*string_tab;
	struct nlist_64			*list;
	struct nlist_64			*info;
	uint32_t				i;
	const char				*name;

	i = -1;
	string_tab = (const char*)content + tabs->stroff;
	list = (struct nlist_64*)((char*)content + tabs->symoff);
	while (++i < tabs->nsyms)
	{
		info = &list[i];
		if (info->n_type & N_STAB)
			continue ;
		name = &string_tab[info->n_un.n_strx];
		print_address_values(info->n_value, info->n_sect, 0);
		if ((info->n_type & N_TYPE) == N_INDR)
			ft_putstr("I");
		if ((info->n_type & N_TYPE) == N_SECT)
			print_val(array[info->n_sect - 1], info->n_type & N_EXT);
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
	free_2d_array((void**)array);
}
