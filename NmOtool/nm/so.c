/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 13:57:21 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/20 13:38:17 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

unsigned char	*exit_header(unsigned char *content, size_t size)
{
	size_t			i;
	extern size_t	g_int;

	i = 0;
	while (42)
	{
		if (g_int >= size)
			break ;
		if (content[i] == 0x00 &&
			content[i + 1] == 0x00 &&
			content[i + 2] == 0x5f)
			break ;
		i++;
		g_int++;
	}
	i += 2;
	g_int += 2;
	return (find_first_label_seg(&content[i], size));
}

unsigned char	*leave_header(unsigned char *content, size_t size)
{
	size_t			i;
	extern size_t	g_int;

	i = 0;
	while (42)
	{
		if (content[i] == 0x00 &&
			content[i + 1] == 0x00 &&
			content[i + 2] == 0x00 &&
			content[i + 3] == 0x00)
			break ;
		i++;
		g_int++;
	}
	i += 4;
	content = exit_header(&content[i], size);
	return (content);
}

int				start_frame(unsigned char *content, size_t size)
{
	extern size_t g_int;

	if (g_int + 8 >= size)
		return (-1);
	if (content[0] == 0xcf &&
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

void			nm_so(unsigned char *content, size_t size,
				void (*symbols)(void *), char *filepath)
{
	unsigned char	*file;
	size_t			i;
	unsigned char	*names;
	extern size_t	g_int;

	file = leave_header(content, size);
	if (endswith(filepath, ".so") == -1)
		names = print_labels(content, size);
	else
		names = NULL;
	i = 0;
	while (g_int < size)
	{
		if (endswith(filepath, ".so") == -1)
			names = print_names(names, filepath);
		else
		{
			ft_putstr(filepath);
			file = print_obj_name(file, size);
		}
		file = find_stack_frame(file, size);
		symbols(file);
		file = next_frame(file, size);
		ft_putchar('\n');
	}
}
