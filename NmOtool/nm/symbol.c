/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:27:01 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/18 17:47:14 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"
#include <stdio.h>
#include <mach-o/stab.h>

struct symtab_command		*iterate_through_load_commands(
		struct load_command *comm,
		int command_num)
{
	struct load_command		*keeping_track;
	int						i;
	struct symtab_command	*tabs;

	tabs = NULL;
	i = 0;
	keeping_track = comm;
	while (i < command_num)
	{
		keeping_track = (struct load_command*)((char*)keeping_track +
				keeping_track->cmdsize);
		if (keeping_track->cmdsize == 0)
			return (NULL);
		if (keeping_track->cmd == LC_SYMTAB)
		{
			tabs = (struct symtab_command*)keeping_track;
			break ;
		}
		i++;
	}
	return (tabs);
}

int							is_64_or_32(struct mach_header *head)
{
	if (head->magic == MH_MAGIC_64)
		return (1);
	else
		return (-1);
}

void						which(unsigned int n_type,
		unsigned int n_sect,
		unsigned int n_value)
{
	unsigned int			val;
	unsigned int			shutup;

	shutup = n_value;
	val = n_type & N_TYPE;
	if (val == N_UNDF)
	{
		if (n_value != 0)
			ft_putstr(" C ");
		else
			ft_putstr(" U ");
	}
	else if (val == N_ABS)
		ft_putstr(" A ");
	else if (val == N_SECT)
		special_letters(n_sect, n_type);
}

void						symbols(void *content)
{
	int						is_64;
	struct mach_header		*header;
	size_t					size;

	size = 0;
	header = content;
	is_64 = is_64_or_32(header);
	if (is_64 == 1)
		nm_64(header, content, size);
	else
		nm_32(header, content);
}
