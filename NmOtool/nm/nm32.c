/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm32.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:20:15 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/20 08:20:04 by angonyam         ###   ########.fr       */
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
	print_address_values(value, info->n_sect, 1);
}

void		string_segment(void *content,
		struct symtab_command *tab, char **array)
{
	struct nlist			*list;
	struct nlist			*info;
	uint32_t				i;
	const char				*string_tab;
	const char				*name;

	string_tab = (const char *)content + tab->stroff;
	list = (struct nlist *)((char*)content + tab->symoff);
	i = -1;
	while (++i < tab->nsyms)
	{
		info = &list[i];
		if (info->n_type == N_STAB)
			continue ;
		name = &string_tab[info->n_un.n_strx];
		print_32_sys(info);
		if ((info->n_type & N_TYPE) == N_SECT)
			print_val(array[info->n_sect - 1], info->n_type & N_EXT);
		which(info->n_type, info->n_sect, info->n_value);
		print_name(name);
	}
}

int			letter_segments_32(struct segment_command *seg,
	char ***array)
{
    uint32_t                max;
    uint32_t                i;
    unsigned char           *content;
    struct section       *sect;

    max = seg->nsects;
    content = (unsigned char *)seg;
    sect = (struct section *)(seg + 1);
    i = 0;
	*array = NULL;
	while (i < max)
    {
		ft_putendl(sect->sectname);
		*array = arraypush(*array, sect->sectname);
        if (ft_strcmp(sect->sectname, "__eh_frame") == 0)
            return (1);
        sect = (struct section *)((void*)sect +
                sizeof(struct section));
        i++;
    }
    return (0);
}

char		**segment_extraction_32(struct load_command *comm,
	int command_num)
{
    struct load_command     *keep;
    char                    **array;

	array = NULL;	
	keep = comm;
	letter_segments_32((struct segment_command *)keep, &array);
	return (array);
}

void		nm_32(struct mach_header *header,
		void *content)
{
	struct load_command		*load;
	int						command_num;
	struct symtab_command	*tab;
	char					**array;

	array = NULL;
	load = (struct load_command *)&header[1];
	command_num = header->ncmds;
	tab = iterate_through_load_commands(load, command_num);
	array = segment_extraction_32(load, command_num);
	string_segment(content, tab, array);
}
