/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backit_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 12:00:54 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/16 12:09:07 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

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
