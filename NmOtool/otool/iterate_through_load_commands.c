/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate_through_load_commands.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 12:02:14 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/16 12:09:49 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

struct segment_command_64		*iterate_to_textseg(
		struct load_command *comm,
		int command_num, size_t count)
{
	struct load_command			*keeping_track;
	struct segment_command_64	*seg;
	int							i;

	i = 0;
	seg = NULL;
	keeping_track = comm;
	while (i < command_num)
	{
		keeping_track = (struct load_command*)((char*)keeping_track +
				keeping_track->cmdsize);
		count += keeping_track->cmdsize;
		if (keeping_track->cmdsize == 0)
			return (NULL);
		if (keeping_track->cmd == LC_SEGMENT_64)
		{
			seg = (struct segment_command_64 *)keeping_track;
			break ;
		}
		i++;
	}
	return (seg);
}
