/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:28:52 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/16 11:32:02 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int			end_arc_signature(unsigned char *content)
{
	if (content[0] == 0x23 &&
		content[1] == 0x31 &&
		content[2] == 0x2f &&
		content[3] == 0x32)
		return (1);
	return (-1);
}

int			arc_magic(unsigned char *content)
{
	if (content[0] == 0x21 &&
		content[1] == 0x3c &&
		content[2] == 0x61 &&
		content[3] == 0x72 &&
		content[4] == 0x63 &&
		content[5] == 0x68 &&
		content[6] == 0x3e &&
		content[7] == 0x0a)
		return (1);
	return (-1);
}

int			handle_arc_end(unsigned char *content, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (end_arc_signature(&content[i]) == 1)
			break ;
		i++;
	}
	return (i);
}

int			handle_arc_start(unsigned char *content, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (signature_check(&content[i]) == 1)
			break ;
		i++;
	}
	return (i);
}

void		recursive_nm(unsigned char *content, size_t size, size_t count)
{
	size_t			start;
	unsigned char	*file;
	size_t			end;

	if (count + 3 > size)
		exit(1);
	start = handle_arc_start(content, size);
	file = &content[start];
	end = handle_arc_end(content, size);
	symbols(&content[start]);
	count += end;
	end += 3;
	recursive_nm(&content[end], size, count);
}
