/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seg_extract_32.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 13:12:45 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/20 14:12:43 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void		execution_head(char *argv, int argc)
{
	if (argc > 2)
	{
		ft_putstr(argv);
		ft_putendl(":");
	}
}

int			is_64_or_32(struct mach_header *head)
{
	if (head->magic == MH_MAGIC_64)
		return (1);
	else
		return (-1);
}

char		**segment_extraction_32(struct load_command *comm,
		int command_num)
{
	struct load_command		*keep;
	char					**array;

	command_num = 0;
	array = NULL;
	keep = comm;
	letter_segments_32((struct segment_command *)keep, &array);
	return (array);
}
