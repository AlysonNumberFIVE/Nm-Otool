/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 15:15:54 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/17 15:21:50 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

int				arc_magic(unsigned char *content)
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

int				signature_check(unsigned char *content)
{
	if ((content[0] == 0xcf || content[0] == 0xce) &&
			content[1] == 0xfa &&
			content[2] == 0xed &&
			content[3] == 0xfe &&
			content[4] == 0x07 &&
			content[5] == 0x00 &&
			content[6] == 0x00 &&
			content[7] == 0x01)
		return (1);
	return (-1);
}

unsigned char	*find_stack_frame(unsigned char *content, size_t size)
{
	size_t			i;
	extern size_t	g_int;

	i = 0;
	while (g_int < size)
	{
		if (start_frame(&content[i], size) == 1)
			break ;
		i++;
		g_int++;
	}
	return (&content[i]);
}

unsigned char	*reverse_to_next_frame(unsigned char *content)
{
	size_t			i;
	extern size_t	g_int;

	i = 0;
	while (content[i] != 0x00)
	{
		i--;
		g_int--;
	}
	return (&content[i]);
}
