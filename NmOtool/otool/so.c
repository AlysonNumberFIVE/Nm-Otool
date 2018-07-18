/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 15:17:49 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/18 17:44:34 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

size_t			g_int = 0;

unsigned char	*next_frame(unsigned char *content, size_t size)
{
	size_t			i;

	i = 0;
	while (g_int < size)
	{
		if (content[i] == 0x20 &&
				content[i + 1] == 0x20 &&
				content[i + 2] == 0x20)
			break ;
		i++;
		g_int++;
	}
	return (reverse_to_next_frame(&content[i]));
}

unsigned char	*name_space(unsigned char *content, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size)
	{
		if (content[i] == 0x00 &&
				content[i + 1] == 0x00 &&
				content[i + 2] == 0x5f)
			break ;
		i++;
	}
	i += 2;
	return (&content[i]);
}

unsigned char	*print_labels(unsigned char *content, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size)
	{
		if (content[i] == 0x00 &&
				content[i + 1] == 0x00 &&
				content[i + 2] == 0x00 &&
				content[i + 3] == 0x00)
			break ;
		i++;
	}
	return (name_space(&content[i], size));
}

unsigned char	*print_names(unsigned char *content, char *filepath)
{
	size_t		i;

	ft_putstr(filepath);
	ft_putstr("(");
	i = 0;
	while (content[i])
	{
		ft_putchar(content[i]);
		i++;
	}
	ft_putstr(".o):\n");
	i++;
	return (&content[i]);
}

void			nm_so(unsigned char *content, size_t size,
		void (*symbols)(void *, int flag), char *filepath)
{
	unsigned char	*file;
	size_t			i;
	unsigned char	*names;

	file = leave_header(content, size);
	names = print_labels(content, size);
	i = 0;
	while (g_int < size)
	{
		names = print_names(names, filepath);
		file = find_stack_frame(file, size);
		symbols(file, 1);
		file = next_frame(file, size);
		ft_putchar('\n');
	}
}
